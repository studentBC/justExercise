class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int temp = grid.size()*grid[0].size();
        long long sum = 0, ans = 0;
        vector<int>num, possible;
        bool valid;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) num.push_back(grid[i][j]);
        }
        sort(num.begin(), num.end());
        int target=num[temp/2];
        for(int i=temp-1; i>=0; i--) {
            if(abs(num[i]-target)%x!=0)
                return -1;
            else
                ans+=abs(num[i]-target)/x;  
        }
        return ans;
    }
};
