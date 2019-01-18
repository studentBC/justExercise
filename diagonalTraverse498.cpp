class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if (matrix.size() == 0)return ans;
        int vertex = matrix.size()<<1-1;
        int count = 1;
        vector<int>temp;
        int next;
        int si = 0 , sj = 0;
        for (int i = 0; i < matrix[0].size(); i++) {
            si = 0;
            sj = i;
            //left down to right top
            if (count%2 == 1) {
                for (int j = 0; j < count; j++) {
                    if (si>=matrix.size() || si <0 || sj >= matrix[0].size() || sj < 0) {
                        //cout <<"jump" << endl;
                        break;
                    }
                    temp.push_back(matrix[si][sj]);
                    si++;
                    sj--;
                    
                }
                while(!temp.empty()) {
                    ans.push_back(temp.back());
                    temp.pop_back();
                }
                next = 1;
            } else {
                for (int j = 0; j < count; j++) {
                    if (si>=matrix.size() || si <0 || sj >= matrix[0].size() || sj < 0) {
                        //cout <<"jump" << endl;
                        break;
                    }
                    ans.push_back(matrix[si][sj]);
                    si++;
                    sj--;
                    
                }
                next = 0;
            }
            count++;
        }
        //count-=2;
        for (int i = 1; i < matrix.size(); i++) {
            si = i;
            sj = matrix[0].size()-1;
            if (count%2 == 1) {
                for (int j = matrix.size(); j > 0; j--) {
                    if (si>=matrix.size() || si <0 || sj >= matrix[0].size() || sj < 0) {
                        //cout <<"jump" << endl;
                        break;
                    }
                    temp.push_back(matrix[si][sj]);
                    si++;
                    sj--;
                    
                }
                while(!temp.empty()) {
                    ans.push_back(temp.back());
                    temp.pop_back();
                }
            } else {
                for (int j = matrix.size(); j > 0; j--) {
                    if (si>=matrix.size() || si <0 || sj >= matrix[0].size() || sj < 0) {
                        //cout <<"jump" << endl;
                        break;
                    }
                    ans.push_back(matrix[si][sj]);
                    si++;
                    sj--;
                    
                }
            }
            count++;
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), k = 0;
        vector<int> res(m * n);
        // i+j = c, m[i][j], next is m[i-1][j+1] or m[i+1][j-1]
        for (int c = 0; c < m + n - 1; ++c) {
            int low = max(0, c - n + 1), high = min(c, m - 1);
            if (c % 2 == 0) {
                for (int i = high; i >= low; --i) {
                    res[k++] = matrix[i][c - i];
                }
            } else {
                for (int i = low; i <= high; ++i) {
                    res[k++] = matrix[i][c - i];
                }
            }
        }
        return res;
    }
};
