class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        char split_char = ',';
        vector<vector<string>> str;
        for (string s: transactions) {
            std::istringstream split(s);
            std::vector<std::string> tokens;
            for (std::string each; std::getline(split, each, split_char); tokens.push_back(each));
            str.emplace_back(tokens);
        }
        unordered_set<string>temp;
        for (int i = 0; i < str.size(); i++) {
            if ( stoi(str[i][2]) > 1000) temp.insert(transactions[i]);
            for (int j = 0; j < str.size(); j++) {
                if (i!=j && str[i][0] == str[j][0] && str[i][3] != str[j][3] && abs(stoi(str[i][1]) - stoi(str[j][1])) <= 60) {
                    temp.insert(transactions[i]);
                    temp.insert(transactions[j]);
                }
            }
        }
        vector<string> ans(temp.begin(), temp.end());
        return ans;

    }
};
//24 ms solution
class Solution {
public:

    vector<string> invalidTransactions(vector<string>& A) {
        int n = A.size();
        map < string, vector < pair < int, pair < string, int > > > > M;
        for(int i = 0;i < n;++i) {
            string x;
            vector < string > info;
            for(int j = 0;j <= A[i].size();++j) {
                if(A[i][j] == ',' or j == A[i].size()) {
                    info.push_back(x);
                    x.clear();
                } else {
                    x += A[i][j];
                }
            }
            int t = stoi(info[1]);
            int amount = stoi(info[2]);
            
            M[info[0]].push_back({t, {info[3], amount}});
        }
        
        vector < string > ans;
        for(auto it = M.begin();it != M.end();++it) {
            string name = it->first;
            auto &adj = it -> second;
            // sort(adj.begin(), adj.end());
            for(int j = 0;j < adj.size();++j) {
                if(adj[j].second.second > 1000) {
                    ans.push_back(name + "," + to_string(adj[j].first) + "," + to_string(adj[j].second.second) + "," + adj[j].second.first);
                    continue;
                }
                for(int k = 0;k < adj.size();++k) {
                    if(abs(adj[j].first - adj[k].first) < 61 and adj[j].second.first != adj[k].second.first) {
                        ans.push_back(name + "," + to_string(adj[j].first) + "," + to_string(adj[j].second.second) + "," + adj[j].second.first);
                        break;
                    }
                }
            }
        }
        
        return ans;
    }
};
