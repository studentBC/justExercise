class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
 		long long mix[100002] = {}, sum = 0, last = 0;
		bool end[100002] = {};
		vector<vector<long long>>ans;
		for (auto& s: segments) {
			mix[s[0]]+=s[2];
			mix[s[1]]-=s[2];
			end[s[0]] = end[s[1]] = true;
		}
		for (int i = 1; i < 100002; i++) {
			if (end[i] && sum) ans.push_back({last, i, sum});
			last = end[i]?i:last;
			sum+=mix[i];
		}
		return ans;
    }
};
//292 ms solution
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int minIdx = INT_MAX, maxIdx = INT_MIN;
        for(const auto& seg : segments){
            minIdx = min(minIdx, seg[0]);
            maxIdx = max(maxIdx, seg[1]);
        }
        vector<long long> painting(maxIdx + 1, 0);
        for(const auto& seg : segments){
            painting[seg[0]] += seg[2];
            painting[seg[1]] -= seg[2];
        }
        vector<vector<long long>> ans;
        long long curColor = painting[minIdx];
        int prev = minIdx;
        for(int i = minIdx + 1; i <= maxIdx; i++){
            if(painting[i] != 0){
                if(curColor != 0){
                    ans.push_back({prev, i, curColor});
                }
                curColor += painting[i];
                prev = i;
            }
        }
        return ans;
    }
};
