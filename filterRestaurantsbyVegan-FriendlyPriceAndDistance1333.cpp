class Solution {
public:
    static bool compare (vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>>candidate;
        for (int i = 0; i < restaurants.size(); i++) {
            if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                if (veganFriendly && !restaurants[i][2]) {
                    continue;
                }
                candidate.push_back(restaurants[i]);
            }
        }
        sort(candidate.begin(), candidate.end(), compare);
        vector<int>ans;
        for (int i = 0; i < candidate.size(); i++) ans.push_back(candidate[i][0]);
        return ans;
    }
};
//the fatest solution
static auto fast=[]{ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
#define mod 1000000007
struct customSort
{
   inline bool operator()(vector<int> & vec1,vector<int> & vec2)
   {
       if(vec1[1]>vec2[1])
          return true;
       else if(vec1[1]<vec2[1])
          return false;
       else
          return vec1[0]>vec2[0];
   }
};
class Solution 
{
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) 
    {
        vector<vector<int>> res;
        vector<int> vec(2);
        for(int i=0;i<restaurants.size();i++)
        {
            if((veganFriendly==0||restaurants[i][2]==1)&&restaurants[i][3]<=maxPrice&&restaurants[i][4]<=maxDistance)
            {
               vec[0]=restaurants[i][0];
               vec[1]=restaurants[i][1]; 
               res.push_back(vec); 
            }
        }
        sort(res.begin(),res.end(),customSort());
        vector<int> ans;
        for(int i=0;i<res.size();i++)
            ans.push_back(res[i][0]);
        return ans;
    }
};
