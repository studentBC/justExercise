class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>>graph = {{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
        int sum = 0;
        vector<vector<int>> memo(N+1, vector<int>(10, 0));
        for (int i = 0; i <= 9; i++)
            sum = (sum + go (N-1, i, graph, memo)) % 1000000007;
        return sum;
    }
    int go(int N, int pos, vector<vector<int>> graph, vector<vector<int>> memo) {
        if (N == 0)
            return 1;
        if (memo[N][cur] != null)
            return memo[N][cur];
        int cnt = 0;
        for (int nei : graph[cur])
            cnt = (cnt + helper(N-1, nei, graph, memo)) % 1000000007;
        memo[N][cur] = cnt;
        return cnt;
    }
};
//the fatest method
class Solution {
public:
	int knightDialer(int N) {
        if(N==1)return 10;
		long long mod = 1000000007, key0 = 1, key1379 = 4, key28 = 2, key46 = 2;

		for (int i = 1; i < N; i++) {
			long long a = key46, b = (key46 + key28) * 2 % mod, c = key1379, d = (key1379 + key0 * 2) % mod;
			key0 = a, key1379 = b, key28 = c, key46 = d;
		}

		return (key0 + key1379 + key28 + key46) % mod;
	}
};
//4 ms solution
#define hell 1000000007
vector<vector<int>> dp(5000,vector<int>(10,0));
class Solution {
    
    int graph[4][3]={{1,2,3},
                     {4,5,6},
                     {7,8,9},
                     {-1,0,-1}};
    
    int X[8]={-2,-2,-1,-1,1,1,2,2};
    int Y[8]={-1,1,-2,2,2,-2,1,-1};
    
public:
    int util(int i,int j,int req){
        if(dp[req][graph[i][j]])
            return dp[req][graph[i][j]];
        
        int ans=0;
        for(int k=0;k<8;k++){
            int x=i+X[k],y=j+Y[k];
            if(x<4 && x>=0 && y<3 && y>=0 && graph[x][y]!=-1)
                ans= (ans %hell + util(x,y,req-1)%hell)%hell;
        }
        return dp[req][graph[i][j]]=ans%hell;
        
    }
    
    
    
    int knightDialer(int N) {
        // dp.resize(N,vector<int>(10,0));
        for(int i=0;i<=9;i++)
            dp[0][i]=1;
        
        int ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(graph[i][j]!=-1){
                    ans = (ans%hell + util(i,j,N-1)%hell)%hell;
                }
            }
        }
        return ans%hell;
    }
};
