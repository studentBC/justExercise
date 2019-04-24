class Solution {
public:
    void goRemark (int i, int j, vector<vector<int>>& grid, int& land, bool& encounter) {
        if (i<0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != 1) {
            if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size() && grid[i][j] == 0) encounter = true;
            return;
        }
        land++;
        grid[i][j] = -1;
        //cout << "go " << i << " , " << j << endl;
        goRemark (i,j+1,grid,land,encounter);
        goRemark (i-1,j,grid,land,encounter);
        goRemark (i,j-1,grid,land,encounter);
        goRemark (i+1,j,grid,land,encounter);
    }
    void go (int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& been2, int& land) {
        if (i<0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] != 1 || been2[i][j]) return;
        land++;
        been2[i][j] = true;
        //cout << "go " << i << " , " << j << endl;
        go (i,j+1,grid,been2,land);
        go (i-1,j,grid,been2,land);
        go (i,j-1,grid,been2,land);
        go (i+1,j,grid,been2,land);
    }
    int largestIsland(vector<vector<int>>& grid) {
        vector<pair<int,int>>connect;
        int count = 0 , ans = 0, land;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    count = 0; 
                    if (i>0 && grid[i-1][j] == 1) {
                        count++;
                    }   
                    if (j>0 && grid[i][j-1] == 1) {
                        count++;
                    }   
                    if (i+1<grid.size() && grid[i+1][j] == 1) {
                        count++;
                    }   
                    if (j+1<grid[0].size() && grid[i][j+1] == 1) {
                        count++;
                    }   
                    if (count > 1) {
                        land = 0;
                        grid[i][j] = 1;
                        vector<vector<bool>>been2(grid.size(), vector<bool>(grid[0].size(),false));
                        go (i,j,grid,been2,land);
                        if (land > ans) ans = land;
                        grid[i][j] = 0;
                    } else if (ans < 1) {
                        ans = 1;
                    }
                }   
            }
        }
        //cout <<  " get out here  " << endl;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    land = 0;
                    bool encounter = false;
                    goRemark (i,j,grid,land, encounter);
                    if (encounter) ++land;
                    if (land > ans) ans = land;
                }
            }
        }
        return ans;
    }
};

//the fatest method
class Solution {
public:
    int a[50][50]={0};//对岛分类编号
    int area[700]={0};//不同编号的岛对应不同的面积
    int islandnum=0;//编号
    void search(vector<vector<int>>& grid,int x,int y)
    {
        int X=grid.size();
        int Y=grid[0].size();
        if(grid[x][y]==1&&a[x][y]==0)
        {
            area[islandnum]++;//累计相同编号的岛的陆地
            a[x][y]=islandnum;//给陆地附上编号
            if(x-1>=0)  search(grid,x-1,y);//四个方向
            if(x+1<X)  search(grid,x+1,y);
            if(y-1>=0)  search(grid,x,y-1);
            if(y+1<Y)  search(grid,x,y+1);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {    
        int X=grid.size();
        int Y=grid[0].size();
        for(int i=0;i<X;i++)
        {
            for(int j=0;j<Y;j++)
            {
                if(grid[i][j]==1&&a[i][j]==0)
                {
                    islandnum++;//找到的第一个岛，应该从编号1开始
                    search(grid,i,j);
                }
            }
        }
        int b[4]={0};//海的四个方向的岛的编号，上下左右
        int maxsum=0,sum;
        for(int i=0;i<X;i++)
        {
            for(int j=0;j<Y;j++)
            {
                if(grid[i][j]==0)
                {
                    sum=1;//毕竟填海嘛，面积得从1算起
                    if(i-1<0)  b[0]=0;
                    else b[0]=a[i-1][j];//上没有越界，则附值上方的岛的编号
                    if(i+1>=X)  b[1]=0;
                    else b[1]=a[i+1][j];//同理
                    if(j-1<0)  b[2]=0;
                    else b[2]=a[i][j-1];//同理
                    if(j+1>=Y)  b[3]=0;
                    else b[3]=a[i][j+1];//同理
                    for(int k=0;k<4;k++)
                    {
                        if(b[k]!=0)
                        {
                            sum+=area[b[k]];//加上该方向的岛的编号的面积
                            for(int l=k+1;l<4;l++)
                            {
                                if(b[l]==b[k])  b[l]=0;//保证四个方向不会出现相同编号的岛
                            }
                            //b[k]=0;
                        }
                        if(sum>maxsum)  maxsum=sum;
                    }
                }
            }
        }
        if(maxsum==0)  maxsum=X*Y;//没有海的情况下
        return maxsum;
    }
};
