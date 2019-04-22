class Solution {
public:
	static bool compare (vector<int,int>a , vector<int,int>b ) {
		return a.second < b.second;
	}
    int twoCitySchedCost(vector<vector<int>>& costs) {
		vector<pair<int,int>>da , db;
 		int ans = 0 , half = costs.size()>>1;
		for (int i = 0; i < costs.size(); i++) }{
			 if (min(costs[i][0],costs[i][1]) == costs[i][0]) {
				 da.emplace_back(pair<int,int>(i,costs[i][1] - costs[i][0]));
			 } else {
				 db.emplace_back(pair<int,int>(i,costs[i][0]- costs[i][1]));
			 }
		}
		if (da.size() == db.size()) {
			for (int i = 0; i < costs.size(); i++) ans+=min(costs[i][0],costs[i][1])
		} else if (da.size() < db.size()) {
			sort(db.begin(),db.end(),compare);
			half-=da.size();
			for (int i = 0; i < da.size(); i++) ans+=costs[da[i].first][0];
			for (int i = 0; i < half; i++) ans+=costs[db[i].first][0];
			for (int i = half; i < db.size(); i++) ans+=costs[db[i].first][1];
		} else {
			sort(da.begin(),da.end(),compare);
			half-=db.size();
			for (int i = 0; i < db.size(); i++) ans+=costs[db[i].first][1];
			for (int i = 0; i < half; i++) ans+=costs[da[i].first][1];
			for (int i = half; i < da.size(); i++) ans+=costs[da[i].first][0];

		}
		return ans;
    }
};
//4ms method
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // sort in asending order of A - B
        vector<pair<int, int>> indices;
        int n = costs.size();
        for (int i = 0; i < n; i++)
            indices.emplace_back(costs[i][0] - costs[i][1], i);
        sort(indices.begin(), indices.end());// pair sort use first to sort by default ?!
        int ans = 0;
        for (int i = 0; i < n / 2; i++)
            ans += costs[indices[i].second][0];
        for (int i = n / 2; i < n; i++)
            ans += costs[indices[i].second][1];
        return ans;
    }
};
