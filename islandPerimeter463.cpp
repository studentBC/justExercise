class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0 , sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                        sum = 0;
                    //check up
                    if (i>=1 && grid[i-1][j] == 1) {
                        sum++;
                    }
                    //down
                    if (i+2<=grid.size() && grid[i+1][j] == 1) {
                        sum++;
                    }
                    //left
                    if (j>=1 && grid[i][j-1] == 1) {
                        sum++;
                    }
                    //right
                    if (j+2<=grid[i].size() && grid[i][j+1] == 1) {
                        sum++;
                    }
                    //cout <<i <<" , "<<j<<" : " << sum << endl;
                    if (sum == 1) {
                        ans+=3;
                    } else if (sum == 2) {
                        ans+=2;
                    } else if (sum == 0) {
                        ans+=4;
                    } else if (sum == 3) {
                        ans+=1;
                    }
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, repeat=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0; j<grid[i].size();++j)
                {
                    if(grid[i][j]==1)
                    {
                        count ++;
                        if(i!=0 && grid[i-1][j] == 1) ++repeat;
                        if(j!=0 && grid[i][j-1] == 1) ++repeat;
                    }
                }
        }
        return 4*count-repeat*2;
    }
};
