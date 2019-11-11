class Solution {
public:
    bool contain (string& word, unordered_map<char,int> point) {
        for (char c:word) {
            if (point[c]) point[c]--;
            else return false;
        }
        return true;
    }
    void go (int start, int sum, int& ans, vector<string>& words, unordered_map<char,int>point, vector<int>& score, vector<bool>used) {
        for (int i = start; i < words.size(); i++) {
            if (!used[i] && contain(words[i], point)) {
                for (char c: words[i]) {
                    sum+=score[c-'a'];
                    point[c]--;
                }
                used[i] = true;
                ans = max(ans, sum);
                go (start+1, sum, ans, words, point, score, used);
                for (char c: words[i]) {
                    sum-=score[c-'a'];
                    point[c]++;
                }
                used[i] = false;
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>point;
        vector<bool>used(words.size(), false);
        for (int i = 0; i < letters.size(); i++) {
            if (point[letters[i]]) {
                point[letters[i]]++;
            } else {
                point[letters[i]] = 1;
            }
        }
        int ans = 0;
        go (0, 0, ans, words, point, score, used);
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& scores) {
        sort(words.begin(), words.end(), [](const string & a, const string & b) {
            return a.length() < b.length();
        });
        int chars[26] = {0};
        for(char ch : letters) chars[ch - 'a']++;
        const int n = words.size();
        vector<int> values;
        for(auto & word : words) {
            int val = 0;
            for(char ch : word) val += scores[ch - 'a'];
            values.push_back(val);
        }
        vector<vector<pair<int, int>>> ws((int) words.size());
        for(int i = 0; i < (int)words.size(); ++i) {
            string word = words[i];
            int temp[26] = {0};
            for(char ch : word) {
                temp[ch -'a']++;
            }
            for(int j = 0; j < 26; ++j) {
                if (temp[j] != 0) ws[i].emplace_back(j, temp[j]);
            }
        }
        int ans = 0;
        dfs(0, ws, ans, 0, chars, values);
        return ans;
    }

private:
    void dfs(int idx, vector<vector<pair<int, int>>> & ws, int & ans, int cur_score, int chars[], vector<int> & values) {
        
        if (idx == ws.size()) {
            ans = max(ans, cur_score);
            // if (cur_score == 63) {
            //     for(int i = 0; i < 4; ++i) {
            //         cout << i << " " << chars[i] << endl;
            //     }
            //     cout << endl;
            // }
            return;
        }
        int mx = 100000;
        for(auto & p : ws[idx]) {
            mx = min(mx, chars[p.first] / p.second);
        }
        for(int use = 0; use <= min(mx, 1); ++use) {
            // update chars
            for(auto & p : ws[idx]) {
                chars[p.first] -= use * p.second;
            }
            dfs(idx + 1, ws, ans, cur_score + values[idx] * use, chars, values);
            
            for(auto & p : ws[idx]) {
                chars[p.first] += use * p.second;
            }
        }
        
    }
};

