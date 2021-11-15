class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>ans;
        unordered_map<int, int>value;
        int len = items.size(), length;
        for (int i = 0; i < len; i++) {
            value[items[i][0]] = max(items[i][1], value[items[i][0]]);
        }
        vector<pair<int,int>>item;
        for (auto& it: value) {
            item.push_back({it.first, it.second});
        }
        sort(item.begin(), item.end());
        vector<int>dp;
        int tmp = 0;
        for (int i = 0; i < item.size(); i++) {
            tmp = max(tmp, item[i].second);
            item[i].second = tmp;
        }
        len = queries.size(); length = item.size()-1;
        int left = 0, right = length, mid;
        for (int i = 0; i < len; i++) {
            tmp = 0;left = 0; right = length;
            while (left <= right) {
                mid = (left+right)/2;
                if (item[mid].first > queries[i]) {
                    right = mid-1;
                } else if (item[mid].first == queries[i]) {
                    tmp = item[mid].second;break;
                } else {
                    left = mid+1;
                }
            }
            if (right > -1 && right <= length && item[right].first < queries[i]) ans.push_back(item[right].second);
            else ans.push_back(tmp);
        }
        return ans;
    }
};
