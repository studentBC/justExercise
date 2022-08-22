class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,pair<string, string>>>data;
        for (int i = 0; i < indexes.size(); i++) {
            data.emplace_back(pair<int,pair<string, string>>(indexes[i], pair<string, string>(sources[i], targets[i])));
        }
        sort(data.begin(), data.end());
        for (int i = 0; i < indexes.size(); i++) {
            indexes[i] = data[i].first;
            sources[i] = data[i].second.first;
            targets[i] = data[i].second.second;
            //cout << indexes[i] <<" , " << sources[i] <<" , " << targets[i] << endl;
        }
        bool valid;
        int k;
        for (int i = 0; i < indexes.size(); i++) {
            valid = true; k = 0;
            for (int j = indexes[i]; j < S.size() && k < sources[i].size(); j++,k++) {
                if (S[j] != sources[i][k]) {
                    valid = false;
                    break;
                }
            }
            if (valid && k == sources[i].size()) {
                for (int j = indexes[i]; j < indexes[i]+sources[i].size(); j++) {
                    S[j] = '$';
                }
            } else {
                indexes[i] = -1;
            }
        }
        //cout << S << endl;
        string ans;
        for (int i = 0, j = 0; i < S.size(); i++) {
            if (i == 0 && S[i] == '$') {
                while (indexes[j] == -1) j++;
                ans+=targets[j];
                for (int k = indexes[j]; k < indexes[j]+sources[j].size(); k++) S[k] = '@';
                j++;
            } else if (i && S[i-1] != '$' && S[i] == '$') {
                //cout <<"start at " << j << endl;
                while (indexes[j] == -1) j++;
                ans+=targets[j];
                for (int k = indexes[j]; k < indexes[j]+sources[j].size(); k++) S[k] = '@';
                j++;

            } else if (S[i] != '$' && S[i] != '@') {
                ans+=S[i];
            }
            //cout << ans <<" , ";
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int l = indexes.size();
        if (l == 0) return S;
        int start = 0, end = 0;
        for (int i=0;i<l;i++) {
            start = indexes[i];
            int j = 0;
            for (;j<sources[i].size();j++) {
                if (sources[i][j] != S[j+start]) {
                    break;
                }
            }
            // match
            if (j == sources[i].size()) {
                S = S.substr(0, start) + targets[i] + S.substr(start + sources[i].length());
                for (int k = i+1;k<indexes.size();k++) {
					// update bigger than current indexes[i]
                    if (indexes[k] > indexes[i]) {
                        indexes[k] += targets[i].length() - sources[i].length();
                    }
                }
            }
        }
        
        return S;
    }
};
//my beat 44% solution
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<string>ans;
        vector<int>len;
        int length;
        string answer;
        vector<int>temp;
        map<int, pair<string, string>>ss;
        for (int i = 0; i < indices.size(); i++) {
            ss[indices[i]] = {sources[i], targets[i]};
        }
        // for (int i = 0; i < 3; i++) {
        //     cout << temp[i] <<" : " << sources[i] <<" , " << targets[i]<<endl;
        //     //indices[i] = temp[i];
        // }
        for (auto& it : ss) {
            length = (int)it.second.first.size();
            string target = s.substr (it.first, length);
            if (it.second.first == target) {
                ans.push_back(it.second.second);
                len.push_back(length);
                for (int j = it.first, k = 0; k < len.back(); j++, k++) {
                    s[j] = '$';
                }
            }
        }
        int i = 0, end = s.size(), j = 0;
        while (i < end) {
            if (s[i] != '$') {
                answer.push_back(s[i]);
                i++;
            } else {
                answer+=ans[j];
                i+=len[j];
                j++;
            }
        }
        return answer;
    }
};
