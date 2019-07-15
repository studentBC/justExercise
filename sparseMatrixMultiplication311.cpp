/*
 * Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |


 */
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    	vector<vector<int>>ans(A.size(), vector<int>(B[0].size(),0));
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < B[0].size(); ++j) {
				for (int k = 0; k < A[i].size(); ++k) {
					ans[i][j]+=A[i][k]*B[k][j];	
				}
			}
		}
		return ans;
    }
};
//4ms solution
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int mA = A.size(), mB = B.size();
        if(mA == 0 || mB == 0) return vector<vector<int>>();
        int nA = A[0].size(), nB = B[0].size();
        vector<vector<int>> res(mA, vector<int>(nB, 0));
        unordered_map<int, vector<pair<int, int>>> mpA;
        unordered_map<int, vector<pair<int, int>>> mpB;
        for(int i = 0; i < mA; ++i) {
            for(int k = 0; k < nA; ++k) {
                if(A[i][k] != 0) mpA[i].push_back({k, A[i][k]});
            }
        }
        for(int i = 0; i < mB; ++i) {
            for(int k = 0; k < nB; ++k) {
                if(B[i][k] != 0) mpB[i].push_back({k, B[i][k]});
            }
        }
        for(int i = 0; i < mA; ++i) {
            for(int k = 0; k < mpA[i].size(); ++k) {
                int col = mpA[i][k].first;
                int val = mpA[i][k].second;
                for(int j = 0; j < mpB[col].size(); ++j) {
                    int row = mpB[col][j].first;
                    res[i][row] +=  val * mpB[col][j].second;
                }
            }
        }
        return res;
    }
};
//8ms solution
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int M = A.size(), N = B.size(), K = B[0].size();
        vector<unordered_set<int>> m_vs(M, unordered_set<int>()), k_vs(K, unordered_set<int>());
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j]) m_vs[i].insert(j);
            }
        }
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < N; ++j) {
                if (B[j][i]) k_vs[i].insert(j);
            }
        } 
        vector<vector<int>> result(M, vector<int>(K, 0));        
        for (int i = 0; i < M; ++i) {   // M
            for (int j = 0; j < K; ++j) {   // K
                // Pick the one with less non-zero to iterate
                if (m_vs[i].size() <= k_vs[j].size()) {
                    for (auto const index:m_vs[i]) {    // N
                        if (k_vs[j].find(index) != k_vs[j].end()) {
                            result[i][j] += A[i][index] * B[index][j];
                        }   
                    }
                }
                else {
                    for (auto const index:k_vs[j]) {    //  N
                        if (m_vs[i].find(index) != m_vs[i].end()) {
                            result[i][j] += A[i][index] * B[index][j];
                        }   
                    }
                }
            }
        }    
        return result;
    }
};
