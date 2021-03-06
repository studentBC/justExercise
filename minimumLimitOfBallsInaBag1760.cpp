class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right, mid, tmp, ans = INT_MAX;
        priority_queue<int>pq;
        //for (int i: nums) pq.push(i);
        sort(nums.begin(), nums.end(), greater<int>());
        right = nums[0];
        int count = 0;
        while (left <= right) {
            mid = (left+right)/2;
            //priority_queue<int>temp = pq;
            count = 0;
            for (int i = 0; i < nums.size() && count <= maxOperations; i++) {
                if (nums[i] > mid) {
                    count+=nums[i]/mid;
                    if (nums[i]%mid == 0) count--;
                } else {
                    break;
                }
            }
            //cout << mid <<" , " << count << endl;
            if (count <= maxOperations) {
                ans = min(ans, mid);
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};
//72 ms solution
// #define DEBUGGG
namespace {
#ifdef DEBUGGG
#define LOG(x) cout << (x) << endl << flush
#define PL(l) { cout << "["; for (auto &e : l) cout << e << ','; cout << "]" << endl; }
#else
#define LOG(x)
#define PL(l)
#endif
static auto _speedupMagic = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
}

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOp) {
        int N = nums.size();
        int lo = 1, hi = *max_element(nums.begin(), nums.end()), mid;
        while (lo < hi) {
            mid = lo + (hi - lo)/2;
            int c = 0;
            for (int n : nums)
                c += (n - 1)/mid;
            if (c <= maxOp) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
