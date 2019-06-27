class MagicDictionary {
public:
    static bool compare (string a, string b) {
        return a.size() < b.size();
    }
    /** Initialize your data structure here. */
    MagicDictionary() {
        dictionary.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        dictionary = dict;
        sort(dictionary.begin(), dictionary.end(), compare);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int count = 0; bool match = true;
        for (int i = 0; i < dictionary.size(); i++) {
            //cout << dictionary[i] << endl;
            if (dictionary[i].size() > word.size()) {
                return false;
            } else if (dictionary[i].size() == word.size()) {
                match = true;count = 0;
                for (int j = 0; j < word.size(); j++) {
                    if (word[j] != dictionary[i][j]) {
                        count++;
                    }
                    if (count > 1) {
                        match = false;break;
                    }
                }
                if (match && count == 1) return true;
            }
        }
        return false;
    }
private:
    vector<string>dictionary;
};
//the fatest method
static vector<long> p_pow{31};



static long hash_(string& s, int idx) {
    long p = 31;
    long m = static_cast<long>(1e7 + 7);
    long h = 0;
    
    for(int i = 0; i<s.size()-idx; i++) {
        
        if(p_pow.size() < i+1) {
            p_pow.push_back(p_pow[i-1] * p % m);
        }
        
        h += p_pow[i] * (s[i+idx]-'a'+1) % m;
        h = h%m;
    }
    
    return h;
}

class TrieNode {

public: 
    unordered_set<long> hashes;
    TrieNode* child[26];
    TrieNode() {
        for(int i = 0; i<26; i++) {
            child[i] = nullptr;
        }
    }

    TrieNode(long h) {
        hashes.insert(h);
        for(int i = 0; i<26; i++) {
            child[i] = nullptr;
        }
    }
};

class MagicDictionary {
private: 
    TrieNode* root;
    
public:
    
    
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void insertTrie(string& s) {
        auto cur = root;
        for(int i = 0; i<s.size(); i++) {
            auto c = s[i];
            TrieNode* x = cur->child[c-'a'];
            auto h = hash_(s, i+1);
            // cout << "hash: " << h << " string: " << s.substr(i+1);
            if(x == nullptr) {
                cur->child[c-'a'] = new TrieNode(h);
            } else {
                x->hashes.insert(h);
            }
            
            
            
            cur = cur->child[c-'a'];
        }
        
        //end
        cur->hashes.insert(0);
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto &s :dict) {
            insertTrie(s);
        }
        
        
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        
        auto cur = root;
        for(int i = 0; i<word.size(); i++) {
            auto h = hash_(word, i+1);
            
            for(int k = 0; k<26; k++) {
                // cout << "K: " << k << endl;
                if('a'+k != word[i]) {
                    if(cur->child[k] != nullptr && cur->child[k]->hashes.count(h)) {
                        return true;
                    }
                }
            }
            
            // cout << "here" << endl;
            cur = cur->child[word[i]-'a'];
            if(cur == nullptr) 
                return false;
            
            
            
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
