class Solution {
public:
    void go (int start, int count, vector<string>& tmp, vector<string>& web, unordered_set<string>& uniq) {
        if (count == 3) {
            string temp;
            for (int i = 0; i < 3; i++) {
                temp+=tmp[i];
                temp+=" ";
            }
            //cout << temp << endl;
            uniq.insert(temp);
            return;
        }
        //if (start >= web.size()) return;
        for (int i = start; i < web.size(); i++) {
            tmp.push_back(web[i]);
            go (i+1, count+1, tmp, web, uniq);
            tmp.pop_back();
        }
        
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>>uw;
        vector<string>ans;
        for (int i = 0; i < username.size(); i++) {
            uw[username[i]].push_back({timestamp[i], website[i]});
        }
        unordered_map<string, int>count;
        string Ans, tmp;
        int big = 0;
        vector<string>temp;
        for (auto& it: uw) {
            vector<string>web;
            sort(it.second.begin(), it.second.end());
            for (auto& iter : it.second) web.push_back(iter.second);
            unordered_set<string>uniq;
            go (0, 0, temp, web, uniq);
            for (auto& s : uniq) {
                //cout << s << endl;
                count[s]++;
                if (count[s] > big) {
                    big = count[s];
                    Ans = s;
                } else if (count[s] == big && s < Ans) {
                    Ans = s;
                }
            }
        }
        istringstream iss(Ans);
        for (int i = 0; i < 3; i++) {
            iss >> tmp;
            ans.push_back(tmp);
        }
        return ans;
    }
};
