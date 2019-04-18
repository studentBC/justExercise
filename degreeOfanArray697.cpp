class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int>freq;
        map<int,int>start;
        int most = 0, ans = nums.size(), length, count;
        for (int i = 0; i < nums.size(); i++) {
            auto it = freq.find(nums[i]);
            if (it == freq.end()) {
                freq.insert(pair<int,int>(nums[i],1));
                start.insert(pair<int,int>(nums[i],i));
            } else {
                it->second++;
                if (most < it->second) {
                    most = it->second;
                }
            }
        }
        if (!freq.empty() && most == 0) most = 1;
        //cout << "the most freq " << most << endl;
        for (auto it = freq.begin(); it!=freq.end(); it++) {
            if (it->second == most) {
                //cout << "find " << it->first << endl;
                length = 0; count = 0;
                for (int j = start.find(it->first)->second; j < nums.size() ; j++) {
                    if (nums[j] == it->first) {
                        count++;
                    }
                    length++;
                    if (count == most)break;
                }
                if (length < ans) ans = length;
            }
        }
        return ans;
    }
};
//the fatest method
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    struct Element {
        Element() : freq(0), left(0), right(0) {}
        Element(const int f, const int l, const int r) : freq(f), left(l), right(r) {}
        int freq;
        unsigned short left;
        unsigned short right;
    };

    int findShortestSubArray(vector<int> &nums) {
        // Construct the frequency table
        std::unordered_map<int, Element> table;
        int maxfreq = 0;
        const int N = nums.size();
        for (int idx = 0; idx < N; ++idx) {
            const int value = nums[idx];
            auto it = table.find(value);
            if (it == table.end()) {
                table.emplace(value, Element(1, idx, 0));
                maxfreq = std::max(maxfreq, 1);
            } else {
                it->second.freq += 1;
                it->second.right = idx;
                maxfreq = std::max(maxfreq, it->second.freq);
            }
        }

        // Now find the shortest subarray which has the same maximum frequency
        int minlen = N;
        for (auto it : table) {
            if (it.second.freq == maxfreq) {
                minlen = std::min(minlen, it.second.right == 0 ? 1 : it.second.right - it.second.left + 1);
            }
        }

        return minlen;
    }
};
