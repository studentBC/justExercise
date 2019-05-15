class Solution {
public:
    static bool compare (pair<int, int>& a , pair<int,int>& b) {
        return a.first+a.second < b.first+b.second;
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>>temp;
        vector<vector<int>>ans;
        vector<int>tmp;
        int sum;
        for (int i:nums1) {
            for (int j :nums2) {
                temp.emplace_back(pair<int,int>(i,j));
            }
        }
        sort (temp.begin(), temp.end(), compare);
        for (int i = 0, j = 0; i < temp.size() && j < k; i++,j++) {
            tmp.clear();
            tmp.emplace_back(temp[i].first);
            tmp.emplace_back(temp[i].second);
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k ) {

		int n1 =  nums1.size() , n2 =  nums2.size();
		if (!n1 || !n2){
			return {};
		}
		//good method to construct paired priority queue 
		auto comp = [&] (pair<int,int> a , pair<int,int>  b ){
			return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
		};
		priority_queue<pair<int,int> , vector<pair<int,int>> , decltype(comp)>  pq(comp);
		
		for(int i = 0; i < nums1.size(); ++i){
			pq.push({i , 0});
		}

		vector<vector<int>> ans ; 

		while(k > 0 && !pq.empty()){
			auto p =  pq.top();
			pq.pop();
			ans.push_back({nums1[p.first] , nums2[p.second]});

			if (++p.second <  n2){
				pq.push(p);
			}
			--k;
		}

		return ans;

	}
};
