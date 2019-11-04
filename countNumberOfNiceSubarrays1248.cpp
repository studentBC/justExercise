//the basic concept is exactly(K) = atMost(K) - atMost(K-1)
class Solution {
public:
	int atmost (vector<int>& nums, int k) {
		int ans = 0;
		for (int i = 0, j = 0; j < nums.size(); j++) {
			k-=nums[j]%2;
			while (k < 0) {
				k+=nums[i]%2;
				i++;
			}
			ans+=(j-i+1);
		}
		return ans;
	}
    int numberOfSubarrays(vector<int>& nums, int k) {
    	return atmost(nums,k)  - atmost(nums, k-1);
    }
};
//56 ms solution
static auto c = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        int c = 0; 
        int prefix[nums.size()] = { 0 }; 
        int odd = 0; 

        for (int i = 0; i < nums.size(); i++)  
        { 

            prefix[odd]++; 

            if (nums[i] & 1) 
                odd++; 
            if (odd >= k) 
                c += prefix[odd - k]; 
        } 

        return c; 
    }
};
