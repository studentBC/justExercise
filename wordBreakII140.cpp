class Solution {
public:
    void go (int start, string temp, vector<string>& tmp, string& target, vector<string>& wordDict, vector<string>& ans ) {
        if (temp.size() > target.size()) {
            return;
        } else if (temp.size() == target.size()) {
            if (temp == target) {
                string a;
                for (int i = 0; i < tmp.size()-1; i++) {
                    a+=tmp[i];
                    a+=" ";
                }
                a+=tmp.back();
                ans.emplace_back(a);
            }
            return;
        } else {
            for (int i = 0; i < wordDict.size(); i++) {
                if (wordDict[i][0] == target[start]) {
                    tmp.emplace_back(wordDict[i]);
                    string outcome = temp+wordDict[i];
                    go (outcome.size(), outcome, tmp, target, wordDict, ans);
                    tmp.pop_back();
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        vector<string>tmp;
        string temp;
        go (0,temp,tmp,s,wordDict, ans);
        return ans;
    }
};
//concept solution
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s,vector<string>& wordDict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(wordDict.find(s) != wordDict.end()){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(wordDict.find(word) != wordDict.end()){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                prev.emplace_back(result);
            }
        }
        m[s]=result; //memorize
        return result;
    }
};
//the fatest solution
class Solution {
public:
    //Dynamic programming solution
    //O(n^3 + wordDict.space()) time and space complexity in the worst case
    //In general, time and space complexity = O(#chars in answer)
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<vector<int>> breaks(len);
        
        TrieNode *root = new TrieNode();
        for(const string &word : wordDict){
            insertWord(root, word);
        }
        
        for(int i = len - 1; i >= 0; --i){
            TrieNode *current = root;
            int pos = i;
            while(pos < len && current){
                int index = s[pos] - 'a';
                ++pos;
                TrieNode *next = current->next[index];
                if(next && next->is_terminal && (pos == len || !breaks[pos].empty())){
                    breaks[i].push_back(pos);
                }
                current = next;
            }
        }
        
        vector<string> ans;
        vector<int> starts = {0};
        dfsGetAnswers(s, starts, breaks, 0, ans);
        return ans;
    }
    
private:
    class TrieNode{
    public:
        TrieNode *next[26];
        bool is_terminal;
        
        TrieNode(){
            memset(next, NULL, sizeof(next));
            is_terminal = false;
        }
    };
    
    void insertWord(TrieNode *root, const string &word){
        int pos = 0, len = word.size();
        while(pos < len){
            int index = word[pos] - 'a';
            if(root->next[index] == nullptr){
                root->next[index] = new TrieNode();
            }
            root = root->next[index];
            ++pos;
        }
        root->is_terminal = true;
    }
    
    void dfsGetAnswers(const string &s, vector<int> &starts, const vector<vector<int>> &breaks, const int start, vector<string> &ans){
        if(start == s.size()){
            string entry = "";
            for(int i = 1, n = starts.size(); i < n; ++i){
                if(i > 1){
                    entry += ' ';
                }
                entry += s.substr(starts[i-1], starts[i] - starts[i-1]);
            }
            ans.push_back(entry);
            return;
        }
        
        for(const int &next : breaks[start]){
            starts.push_back(next);
            dfsGetAnswers(s, starts, breaks, next, ans);
            starts.pop_back();
        }
    }
};
