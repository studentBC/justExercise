class Solution {
public:
    void go (string start, unordered_set<string>& visited, vector<string>& temp, vector<vector<string>>& synonyms) {
        if (visited.count(start)) return;
        visited.insert(start);
        for (int i = 0; i < synonyms.size(); i++) {
            if (find(synonyms[i].begin(), synonyms[i].end(), start)!=synonyms[i].end()) {
                for (int j = 0; j < synonyms[i].size(); j++) {
                    if (!visited.count(synonyms[i][j])) {
                        temp.emplace_back(synonyms[i][j]);
                        go (synonyms[i][j], visited, temp, synonyms);
                    }
                }
            }
        }
    }
    void helper (int i, vector<string>& candidate, vector<string>& temp, vector<vector<string>>& assemble, vector<vector<string>>& synonym) {
        if (temp.size() == candidate.size()) {
            assemble.emplace_back(temp);
            //for (string s:temp) cout << s <<" , ";
            //cout << endl;

            return;
        }   
            for (int j = 0; j < synonym.size(); j++) {
                if (find(synonym[j].begin(), synonym[j].end(), candidate[i]) != synonym[j].end()) {
                    for (int k = 0; k < synonym[j].size(); k++) {
                        temp.emplace_back(synonym[j][k]);
                        helper (i+1, candidate, temp, assemble, synonym);
                        temp.pop_back();
                    }
                }
            }
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_set<string>used;
        unordered_set<int>pos;
        vector<vector<string>>synonym, assemble;
        for (int i = 0; i < synonyms.size(); i++) {
            for (int j = 0; j < synonyms[i].size(); j++) {
                if (!used.count(synonyms[i][j])) {
                    vector<string>temp;
                    //unordered_set<string>visited;
                    temp.emplace_back(synonyms[i][j]);
                    go (synonyms[i][j], used, temp, synonyms);
                    synonym.emplace_back(temp);
                    //for (string s:temp) cout << s << " , ";
                    //cout << endl;
                }
            }
        }
        istringstream ss(text);
        vector<string>input, candidate, temp, ans;
        int count = 0;
        string word;
        while (ss >> word) {
            //ss >> word;
            //cout << word <<" -> ";
            input.emplace_back(word);
            if (used.count(word)) {
                candidate.emplace_back(word);
                pos.insert(count);
                //cout << count <<" -> ";
            }
            count++;
        }
        helper (0, candidate,  temp, assemble, synonym);
        //cout << input.size() << endl;
        for (int i = 0; i < assemble.size(); i++) {
            string tmp;
            for (int j = 0, k = 0; j < input.size(); j++) {
                if (pos.count(j)) {
                    tmp+=assemble[i][k];
                    k++;
                } else {
                    tmp+=input[j];
                }
                if (j+1 != input.size()) tmp+=" ";
            }
            ans.emplace_back(tmp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        
        unordered_map<string, string> m;
        unordered_set<string> s;
        for (vector<string>& vec: synonyms) {
            string s1 = find(vec[0], m);
            string s2 = find(vec[1], m);
            if (s1 != s2) {
                m[s1] = s2;
            }
            s.insert(vec[0]);
            s.insert(vec[1]);
        }
        
        unordered_map<string, vector<string>> dict;
        for (const string& str: s) {
            dict[find(str, m)].push_back(str);
        }
        for (pair<const string, vector<string>>& p: dict) {
            sort(p.second.begin(), p.second.end());
        }
        
        vector<string> words;
        stringstream ss(text);
        string word;
        while (getline(ss, word, ' ')) words.push_back(word);
        
        vector<string> ret;
        vector<string> cur;
        backtrack(ret, cur, words, 0, dict, m);
        
        return ret;
    }
    
    void backtrack(vector<string>& ret, vector<string>& cur, vector<string>& words, int index, unordered_map<string, vector<string>>& dict, unordered_map<string, string>& m) {
        if (index == words.size()) {
            string s;
            for (string str: cur) {
                s += str + " ";
            }
            s.pop_back();
            ret.push_back(s);
            return;
        }
        
        if (!m.count(words[index])) {
            cur.push_back(words[index]);
            backtrack(ret, cur, words, index+1, dict, m);
            cur.pop_back();
            return;
        }
        
        for (string& s: dict[find(words[index], m)]) {
            cur.push_back(s);
            backtrack(ret, cur, words, index+1, dict, m);
            cur.pop_back();
        }
    }
    
    string find(const string& s, unordered_map<string, string>& m) {
        if (!m.count(s)) m[s] = s;
        else if (m[s] != s) m[s] = find(m[s], m);
        return m[s];
    }
};
