class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        db.clear();
        return;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        db.push_back(word);
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        for (int i = 0; i < db.size(); i++) {
            if (word.compare(db[i]) == 0) {
                return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        bool found = true;
        for (int i = 0; i < db.size(); i++) {
            if (prefix.size() <= db[i].size()) {
                found = true;
                for (int j = 0; j < prefix.size(); j++) {
                    if (prefix[j] != db[i][j]) {
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
    vector<string>db;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
//the fatest method
class Trie {
    set<string> tree;
public:
    /** Initialize your data structure here. */
    Trie() {
        tree.clear();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        tree.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return tree.count(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto it = tree.lower_bound(prefix);
        if(it == tree.end())
            return false;
        if(it->size() < prefix.size())
            return false;
        for(int i = 0; i < prefix.size(); i++) {
            if(prefix[i] != (*it)[i]) {
                return false;
            }
        }
        return true;
    }
};
