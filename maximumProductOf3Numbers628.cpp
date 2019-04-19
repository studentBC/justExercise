class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int>positive;
        vector<int>negative;
		int tmp1 , tmp2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]>-1) {
                positive.emplace_back(nums[i]);
            } else {
                negative.emplace_back(nums[i]);
            }
        }
        sort (positive.begin(), positive.end(), greater<int>());
        sort (negative.begin(), negative.end());
        if (negative.size() == 0) {
            return positive[0]*positive[1]*positive[2];
        } else if (positive.size() == 2) {
            if (negative.size() > 1) {
                return positive[0]*negative[0]*negative[1];
            } else {
                return positive[0]*negative[0]*positive[1];
            }
            
        } else if (positive.size() == 1) {
            return positive[0]*negative[0]*negative[1];
        } else if (positive.size() == 0) {
            return negative[negative.size()-3]*negative[negative.size()-2]*negative[negative.size()-1];
        } else {
			tmp1 = negative[0]*negative[1]*negative[2];
			tmp2 = positive[0]*positive[1]*positive[2];
			if (tmp1 > tmp2) return tmp1;
			return tmp2;
		}
        return positive[0]*positive[1]*positive[2];
    }
};
//the fatest method
class Solution {

    
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3)
            return nums[0]*nums[1]*nums[2];
        
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN; 
        int min1 = INT_MAX, min2 = INT_MAX; 
        
        for(auto i: nums){
            if( i >= max1 )
            {
                max3 = max2; 
                max2 = max1; 
                max1 = i;
            } 
            else if (i >= max2)
            {
                max3 = max2; 
                max2 = i;
            }
            else if( i > max3 )
            {
                max3 = i; 
            }; 
            
            if( i <= min1 )
            {
                min2 = min1; 
                min1 = i;
            }
            else if( i < min2 )
            {
                min2 = i;
            }; 
        };
        
        return(max(max1*max2*max3, min1*min2*max1));
    };
};
    static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

