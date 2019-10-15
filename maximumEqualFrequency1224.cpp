#include <stdint.h>
#include <string.h>

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

#ifndef LOCALRUN
#define printf(format, ...)
#endif

using namespace std;

class Solution {
private:
  static constexpr int max_val = 100001;

public:
  Solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  int maxEqualFreq(vector<int>& nums) {
    int freq[max_val + 1]; memset(freq, 0, sizeof(freq));
    for (const int x : nums) ++freq[x];

    int ff[max_val + 1]; memset(ff, 0, sizeof(ff));

    int live_values = 0;
    for (int x = 0; x <= max_val; ++x) {
      if (freq[x])
        ++live_values;
      ++ff[freq[x]];
    }

    for (int len = nums.size(); len; --len) {
      if (ff[1] == len) return len;
      if (ff[1] == 1 && (len - 1) % (live_values - 1) == 0) {
        const int req_freq = (len - 1) / (live_values - 1);
        if (ff[req_freq] == (live_values - 1)) return len;
      }
      if ((len - 1) % live_values == 0) {
        const int req_freq = (len - 1) / live_values;
        if (ff[req_freq] == live_values - 1 &&
            ff[req_freq + 1] == 1)
          return len;
      }

      const int val = nums[len - 1];
      int f_val = freq[val];
      --ff[f_val];
      --freq[val]; --f_val;
      ++ff[f_val];
      if (f_val == 0) --live_values;
    }

    return 1;
  }
};

#ifdef LOCALRUN
void run_test(vector<int> v) {
  printf("%d\n", Solution().maxEqualFreq(v));
}

int main() {
  run_test({2,2,1,1,5,3,3,5});
  run_test({1,1,1,2,2,2,3,3,3,4,4,4,5});
  run_test({1,1,1,2,2,2});
  run_test({10,2,8,9,3,8,1,5,2,3,7,6});
  return 0;
}
#endif
