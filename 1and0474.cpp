class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
 		vector<vector<int>>count (m+1,vector <int>(n+1,0));       
		int one , zero;
		for (int i = 0; i < strs.size(); i++) {
			one = zero = 0;
			for (int a = 0; a < strs[i].size(); a++) {
				if (strs[i][a] == '1') {
					one++;
				} else {
					zero++;
				}
			}
			//cout << "1: " << one << " 0 " << zero << endl;
			for (int j = m; j >= zero; j--) {
				for (int k = n; k >= one; k--) {
					count[j][k] = max(count[j][k], count[j-zero][k-one]+1);
				}
			}
		}
		return count[m][n];
    }
};
//the correct one
int findMaxForm(vector<string>& strs, int m, int n) {
  vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
  int numZeroes, numOnes;

  for (auto &s : strs) {
    numZeroes = numOnes = 0;
    // count number of zeroes and ones in current string
    for (auto c : s) {
      if (c == '0')
	numZeroes++;
      else if (c == '1')
	numOnes++;
    }

    // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
    // from the first few strings up to the current string s
    // Catch: have to go from bottom right to top left
    // Why? If a cell in the memo is updated(because s is selected),
    // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
    // If we go from top left to bottom right, we would be using results from this iteration => overcounting
    for (int i = m; i >= numZeroes; i--) {
	for (int j = n; j >= numOnes; j--) {
          memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
	}
    }
  }
  return memo[m][n];
}
//the fatest method
/*
Learnings:
This is an instantiation of the 0-1 knapsack problem. However the bounds on the number of 1s and 0s make it tractable
By ordering the values in the dp mat that we update, we can use just a SINGLE matrix!

WORTH INVESTIGATING:
Greedy heuristic based approach

*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //const unsigned int s = strs.size();
        
        array<tuple<int,int>, 601> res;//amount of 0 and 1 for each string
        size_t ind_ar = 0;
        for (auto it = strs.begin(); it != strs.end(); ++it){
            int z = 0, o = 0;
            //cout << *it << " ";
            for (size_t i = 0; i < it->size(); ++i){
                switch ((*it)[i]){
                    case '1':
                        ++o;
                        break;
                    case '0':
                        ++z;
                        break;
                    default:
                        break;
                }
            }
            //cout << z << " " << o << endl;
            res[ind_ar] = make_tuple(z, o);
            ++ind_ar;
        }
        array<tuple<int,int>,601>::iterator it = &res[strs.size()];
        //common sum increasing
        sort(res.begin(), it,[m, n](tuple<int,int> a, tuple<int,int>b){
            if (get<0>(a) + get<1>(a) == get<0>(b) + get<1>(b)){
                if (m <= n) return get<0>(a) < get<0>(b);
                else return get<1>(a) < get<0>(b);
            }
            else return(get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b));
        });
        // for (auto i = 0; i < strs.size(); ++i){
        //     cout << get<0>(res[i]) << " " << get<1>(res[i]) << endl;
        // }
        int result = 0;
        ind_ar = 0;
        int mc = m, nc = n;
        while ((mc > 0 || nc > 0) && ind_ar < strs.size()){
            if (mc - get<0>(res[ind_ar]) >= 0 && nc - get<1>(res[ind_ar]) >=0){
                mc-=get<0>(res[ind_ar]);
                nc-=get<1>(res[ind_ar]);
                result+=1;
            }
            ind_ar+=1;
        }
        // cout << result <<endl;
        // cout << endl;
        //sum zeroes increasing
        int result1 = 0;
        mc = m; nc = n;
        sort(res.begin(), it,[](tuple<int,int> a, tuple<int,int>b){
            return (get<0>(a) < get<0>(b));
        });
        // for (auto i = 0; i < strs.size(); ++i){
        //     cout << get<0>(res[i]) << " " << get<1>(res[i]) << endl;
        // }
        ind_ar = 0;
        while ((mc > 0 || nc > 0) && ind_ar < strs.size()){
            if (mc - get<0>(res[ind_ar]) >= 0 && nc - get<1>(res[ind_ar]) >=0){
                mc-=get<0>(res[ind_ar]);
                nc-=get<1>(res[ind_ar]);
                result1+=1;
            }
            ind_ar+=1;
        }
        // cout << result1 << endl;
        // cout << endl;
        //sum ones increasing
        int result2 = 0;
        mc = m; nc = n;
        sort(res.begin(), it,[](tuple<int,int> a, tuple<int,int>b){
            return (get<1>(a) < get<1>(b));
        });
        // for (auto i = 0; i < strs.size(); ++i){
        //     cout << get<0>(res[i]) << " " << get<1>(res[i]) << endl;
        // }
        ind_ar = 0;
        while ((mc > 0 || nc > 0) && ind_ar < strs.size()){
            if (mc - get<0>(res[ind_ar]) >= 0 && nc - get<1>(res[ind_ar]) >=0){
                mc-=get<0>(res[ind_ar]);
                nc-=get<1>(res[ind_ar]);
                result2+=1;
            }
            ind_ar+=1;
        }
        // cout << result2 << endl;
        // cout << endl;
        int r = max(result, result1);
        r = max(r, result2);
        return r; 
    }
};

/*
// DP solution

class Solution {
public:
    int count(string s)
    {
        int res=0;
        for(char c:s)
        {
            if(c=='0')
                res++;
        }
        return res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size(),res=0;
        int dp[m+1][n+1]; // can use just a single matrix since we are building up the counts in a bottom up fashion
        memset(dp,0,sizeof(dp));
        for(string t:strs)
        {
            int a=count(t),b=t.size()-a;
            if(a>m || b>n) continue;
            for(int i=m-a;i>=0;i--)
            {
                for(int j=n-b;j>=0;j--)
                {
                    if(dp[i][j]>0)
                    {
                        dp[i+a][j+b]=max(dp[i+a][j+b],dp[i][j]+1);
                        res=max(res,dp[i+a][j+b]);
                    }
                }
            }
            if(a<=m && b<=n && dp[a][b]==0)
                dp[a][b]=1;
            res=res==0?1:res;
        }
        return res;
    }
};
*/

/*
// My solution:

typedef vector<int> vint;
typedef vector<vint> dpmat;
typedef vector<dpmat> dpmats;
typedef pair<int, int> pint;
class Solution {
public:
    
    pint get_counts(string& s){
        int zc=0, oc=0;
        for(char c:s){
            if(c=='0')
                zc++;
            else
                oc++;
        }
        return pint(zc, oc);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(strs.size()==0)
            return 0;
        dpmats dp(strs.size()+1, dpmat(m+1, vint(n+1, 0)));
        for(int sid=1; sid<=strs.size(); sid++){
            pint sc = get_counts(strs.at(sid-1));
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n; k++){
                    if(j>=sc.first && k>=sc.second){
                        // case when you can include the current number
                        dp.at(sid).at(j).at(k) = max(dp.at(sid-1).at(j).at(k), 1+dp.at(sid-1).at(j-sc.first).at(k-sc.second));
                    }
                    else{
                        // case when you can't include the current number
                        dp.at(sid).at(j).at(k) = dp.at(sid-1).at(j).at(k);
                        
                    }
                }
            }
        }
        return dp.at(strs.size()).at(m).at(n);
    }
};
*/

/*
Brute force:
Consider every possible subset of strings and check if the totals for 0s and 1s add up. Choose the largest subset
Time: O(2^N)

Problem with this approach:
Multiple ways to end up with the same maximum number of 0s and 1s chosen after processing the first k elements. We only care about the method with the most number of strings
We are guaranteed that at most 100 0s and 100 1s will exist

DP approach:

Let dp[i][j][k] be the maximum number of strings you can select by considering the first i strings, so as to have AT MOST j 0s and k 1s
Under this definition, the final answer is dp[len(ip)][m][n]

dp[0][j][k] = 0 for all j, k

dp[i][j][k] = {

                max(dp[i-1][j][k], 1+dp[i-1][j-#0s(ip[i])][k-#1s(ip[j])]) for #0s(ip[i])<=j<=m, #1s(ip[i])<=k<=n; --> basically, choosing to either include the current number or not
                dp[i-1][j][k] otherwise; --> case when you can't include the current number

              }

Time complexity:
O(N*100*100)

Space complexity:
O(100*100)

Note: This DP formulation only works since the values are bounded


Potential greedy approach:
Sort numbers based on max(#0s, #1s) in ascending order. Break ties by preferring numbers with fewer 1s of n<m, or fewer 0s if m<n. In general, sort shorter strings earlier
- Should the ordering change dynamically?
Greedily take numbers once sorted in this order

m=5, n=10

1, 0, 11, 0011, 000, 00111, 001111 --> can't greedily take in order

Ideal answer:
1, 0, 11, 00111, 001111

Greedy answer:
1,0,11,0011

1, 1, 1, 1, 0, 00, 11, 110, 001, 0111 --> shorter strings should be considered first

Dp approach:
Knapsack problem
*/
