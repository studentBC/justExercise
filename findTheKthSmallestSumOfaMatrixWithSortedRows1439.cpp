class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
 		vector<int>row = mat[0];
		int len;
		for (int i = 1; i < mat.size(); i++) {
			vector<int>temp;
			for (int j = 0; j < mat[i].size(); j++) {
				for (int n: row) {
					temp.push_back(mat[i][j]+n);
				}
			}
			sort(temp.begin(), temp.end());
			len = min (k, int(temp.size()));
			row.resize(len);
			for (int j = 0; j < len; j++) row[j] = temp[j];
		}
		return row.back();
    }
};


/*because k is small, we can come up with an easy solution, we calculate all the possible results row by row, sort the result array, trim the result array to k size, the answer is the k-1 element.*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row = mat[0];
        for(int i = 1; i < mat.size(); ++i) {
            vector<int> nr;
            for(int j = 0; j < mat[i].size(); ++j) {
                
                for(auto n : row) {
                    nr.push_back(mat[i][j] + n);
                }
            }
            sort(nr.begin(), nr.end());
            row.resize(min(k, int(nr.size())));
            for(int x = 0; x <min(k, int(nr.size())) ;++x) {
                row[x] = nr[x];
            }
        }
        return row[k-1];
    }
};
//44ms solution
class Solution {
public:
    void DFS(int p, int cur, int sum, int &n, int k, vector<vector<int>> &mat) {
        if (p == mat.size()) {
            ++n;
            return;
        }
        if (n >= k) {
            return;
        }
        for (int m : mat[p]) {
            if (cur + m <= sum) {
                DFS(p + 1, cur + m, sum, n, k, mat);
            } else {
                return;
            }
        }
        return;
    }
    bool check(int sum, int k, vector<vector<int>> &mat) {
        int n = 0;
        DFS(0, 0, sum, n, k, mat);
        if (n >= k) {
            return true;
        } else {
            return false;
        }
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int min_sum = 0;
        for (int i = 0; i < mat.size(); ++i) {
            min_sum += mat[i][0];
            for (int j = 1; j < mat[i].size(); ++j) {
                mat[i][j] -= mat[i][0];
            }
            mat[i][0] = 0;
        }
        int L = 1, R = 1E6;
        while (L < R) {
            int M = (L + R) / 2;
            if (check(M, k, mat)) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        return L + min_sum;
    }
};
