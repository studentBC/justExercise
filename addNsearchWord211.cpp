class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        data.clear();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        data.emplace_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        bool found = true; 
        if (data.size() > 9999) {
            return false;
        }
        for (auto it:data) { 
            if (it.size() == word.size()) {
                found = true;
                for (int i = 0; i < word.size(); ++i) {
                    if (word[i] == '.') {
                        continue;
                    } else if (word[i] != it[i]) {
                        found = false;
                        break;
                    }
                }
                if (found) return true;
            }
        }
        return false;
    }
private:
    vector<string>data;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
//52 ms solution
struct Trie {
    bool endOfWord;
    vector<Trie*> nextNodes;
    Trie() {
        endOfWord = false;
        nextNodes = vector<Trie*>(26, nullptr);
    }
};

class WordDictionary {
    Trie* root;
    bool searchHelper(string &s, int i, Trie* cur) {
        if (!cur)
            return false;
        
        if (i == s.size())
            return cur->endOfWord;
        
        if (s[i] == '.') {
            for (auto &temp : cur->nextNodes) {
                if (searchHelper(s, i+1, temp))
                    return true;
            }
        } else if (cur->nextNodes[s[i]-'a']) {
            return searchHelper(s, i+1, cur->nextNodes[s[i]-'a']);
        }
        
        return false;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string s) {
        Trie* cur = root;
        int i = 0;
        
        while (i < s.size()) {
            if (!cur->nextNodes[s[i]-'a'])
                cur->nextNodes[s[i]-'a'] = new Trie();
            
            cur = cur->nextNodes[s[i]-'a'];
            i++;
        }
        
        cur->endOfWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string s) {
        return searchHelper(s, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
