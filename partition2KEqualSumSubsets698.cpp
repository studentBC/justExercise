class Solution {
public:
	void go (int start, vector<int>& nums, bool& found, int target, int sum, vector<int>& indices) {
		if (sum == target) {
			found = true;
			for (int i = 0; i < indices.size(); i++) {
				nums[indices[i]] = INT_MAX;
			}
		} else {
			for (int i = start+1; i < nums.size(); i++) {
				if (nums[i]!=INT_MAX && sum+nums[i] <= target) {
					indices.push_back(i);
					go (i,nums,found,target, sum+nums[i],indices);
					indices.pop_back();
				}
			}
		}
	}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
 		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum+=nums[i];
		}
		if (sum%K !=0) return false;
		sum = sum/K;
		sort(nums.begin(), nums.end(), greater<int>());
		bool found;
		vector<int>indices;
		for (int i = -1; i < nums.size(); i++) {
			if (nums[i] != INT_MAX) {
				found = false;
				go (i,nums,found, sum, 0, indices);
				if (!found) return false;
			}
		}
		return true;
    }
};
//the fatest method cost only 4ms
class Solution {
public:
    vector<int> ns;
    vector<int> pocket;
    int target;
    int count;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto i:nums){sum+=i;}
        if(sum%k!=0) return false;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        target=sum/k;
        if(nums[0]>target) return false;;
        ns=nums;
        pocket=vector<int>(k,0);
        count=k;
        return put(0);
    }
    bool put(int n){
        for(int i=0;i<pocket.size();i++){
            if(pocket[i]+ns[n]>target)continue;//try another
            //try put it;
            pocket[i]+=ns[n];
            if(n==ns.size()-1)return true;
            if(put(n+1))return true;
            pocket[i]-=ns[n];
            if(pocket[i]==0) return false;
        }return false;
    }       
};
