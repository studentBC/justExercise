class Solution {
public:
    void go (vector<int>& pos, int n, vector<vector<string>>& ans) {
        if (pos.size() == n) {
            vector<string>temp;
            for (int i = 0; i < n; i++) {
                string tmp;
                for (int j = 0; j < n; j++) {
                    if (pos[i] == j) tmp+="Q";
                    else tmp+=".";
                }
                temp.emplace_back(tmp);
            }
            ans.emplace_back(temp);
        } else {
            for (int i = 0; i < n; i++) {
                if (pos.empty()) {
                        pos.emplace_back(i);
                        go (pos, n, ans);
                        pos.pop_back();
                } else {
                    bool kill = false;
                    //check upper
                    for (int j = 0; j < pos.size(); j++) {
                        if (pos[j] == i) {
                            kill = true;break;
                        }
                    }
                    //check upper right
                    if (!kill) {
                        for (int j = pos.size()-1, p = i+1; j > -1; j--, p++) {
                            if (pos[j] == p) {
                                kill = true;break;
                            }
                        }
                    }
                    //check upper left
                    if (!kill) {
                        for (int j = pos.size()-1, p = i-1; j > -1; j--, p--) {
                            if (pos[j] == p) {
                                kill = true;break;
                            }
                        }
                    }
                    if (!kill) {
                        pos.emplace_back(i);
                        go (pos, n, ans);
                        pos.pop_back();
                    }
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<int> pos;
        go (pos, n, ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string r(n, '.');
        vector<string> m(n, r);
        vector<int> flag(5 * n - 2, 1);
        solve(res, m, 0, n, flag);
        return res;
    }
    void solve(vector<vector<string>>& res, vector<string> &m, int row, int n, vector<int> &flag) {
        if(row == n) {
            res.push_back(m);
            return;
        }
        for(int col = 0; col < n; col++) {
            if(flag[col] && flag[n + col + row] && flag[4 * n - 2 + col - row]) {
                flag[col] = flag[n + col + row] = flag[4 * n - 2 + col - row] = 0;
                m[row][col] = 'Q';
                solve(res, m, row + 1, n, flag);
                m[row][col] = '.';
                flag[col] = flag[n + col + row] = flag[4 * n - 2 + col - row] = 1;
            }
        }
    }
};
