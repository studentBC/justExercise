class Solution {
public:
	static bool compare(pair<int,int>& a, pair<int,int>& b) {
		if (a.first == b.first) {
			return a.second < b.second;
		} else {
			return a.first < b.first;
		}
	}
    vector<int> sortByBits(vector<int>& arr) {
 		vector<pair<int,int>>bits;
		vector<int>ans;
		int count = 0;
		for (int i: arr) {
			count = 0;
			for (int j = 0; j < 32; j++) {
				if(i>>j&1) count++;
			}
			bits.push_back(make_pair(count, i));
		}
		sort(bits.begin(), bits.end(), compare);
		for (auto& it: bits) {
			ans.push_back(it.second);
		}
		return ans;
    }
};
//the 16 ms solution
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> pairs;
        for(int num : arr) {
            int cnt = 0;
            int temp = num;
            while (temp) {
                cnt += temp % 2;
                temp /= 2;
            }
            pairs.emplace_back(cnt, num);
        }
        sort(pairs.begin(), pairs.end());
        vector<int> ans;
        for(const auto & p : pairs) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
