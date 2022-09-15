//https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) {
            return 0;
        }
        vector<string> words;
        unordered_set<string> lookup{endWord};
        words.emplace_back(beginWord);
        int res = 1;
        while (!words.empty()) {
            for (const auto & w : words) {
                dict.erase(w);
            }
            unordered_set<string> tmp;
            ++res;
            for (auto & w : words) {                                
                for (auto & ch : w) {
                    char cur = ch;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        ch = c;
                        if (lookup.count(w)) {
                            return res;                            
                        }
                        if (dict.count(w)) {
                            tmp.emplace(w);
                        }
                    }
                    ch = cur;
                }
            }
            if (tmp.size() > lookup.size()) {
                swap(tmp, lookup);
            }
            words.assign(tmp.begin(), tmp.end());
        }
        return 0;
    }
};
//the fatest method
class Solution {
public:
    int get_id(unordered_map<string, int> &id, int &index, string &word, vector<string> &vec) {
        if (!id.count(word)) {
            vec.push_back(word);
            id[word] = index++;       
        }
        return id[word];
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> exists;
        unordered_map<string, int> id;
        int n = wordList.size();
        int index = 0;
        vector<int> dp(n + 2, 0), used(n + 2, 0);
        vector<string> vec;
        for (string word : wordList) exists.insert(word);
        get_id(id, index, beginWord, vec);
        get_id(id, index, endWord, vec);
        for (string word : wordList) get_id(id, index, word, vec);
        queue<int> q;
        q.push(0);
        used[0] = 1;
        dp[0] = 1;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            string word = vec[v];
            for (int i = 0; i < word.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == word[i]) continue;
                    string cur = word.substr(0, i) + c + word.substr(i + 1);
                    if (exists.count(cur)) {
                        int nxt = id[cur];
                        if (!used[nxt]) {
                            used[nxt] = 1;
                            q.push(nxt);
                            dp[nxt] = dp[v] + 1;
                        }
                    }
                }
            }
        }
        
        return dp[1];
    }
};
//my bfs solution beat 6%
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>>graph;
        wordList.push_back(beginWord);
        int len = wordList.size(), count, ans = INT_MAX;
        
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (wordList[i].size() == wordList[j].size()) {
                    count = 0;
                    for (int k = 0; k < wordList[i].size(); k++) {
                        if (wordList[i][k] != wordList[j][k]) count++;
                    }
                    if (count == 1) {
                        graph[wordList[i]].insert(wordList[j]);
                        graph[wordList[j]].insert(wordList[i]);
                    }
                }
            }
        }
        queue<pair<string, int>>pos;
        unordered_set<string>visited;
        pos.push({beginWord, 1});
        while (!pos.empty()) {
            pair<string, int> next = pos.front();
            //cout << next.first << " , ";
            pos.pop();
            if (next.first == endWord) ans = min(ans, next.second);
            count = next.second+1;
            for (string s : graph[next.first]) {
                if (visited.find(s) == visited.end()) {
                    pos.push({s, count});
                    visited.insert(s);
                }
            }
        }
        return ans == INT_MAX?0:ans;
    }
};
