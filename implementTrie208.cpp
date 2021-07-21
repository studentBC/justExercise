struct TrieNode {
	struct TrieNode* child[26];
	bool Isend;
};
class Trie {
public:
	struct TrieNode* root = NULL;
    /** Initialize your data structure here. */
    Trie() {
   		root = new TrieNode;
		root->Isend = false;
		for (int i = 0; i < 26; i++) root->child[i] = NULL;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
		struct TrieNode* node = root;
        //if (!node) cout <<"empty";
		int i;
        for (char c : word) {
			i = c-'a';
			if (!node->child[i]) {
				node->child[i] = new TrieNode;
				node->child[i]->Isend = false;
				for (int j = 0; j < 26; j++) node->child[i]->child[j] = NULL;
			} 
			node = node->child[i];
		}
		node->Isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		struct TrieNode* node = root;
		int i;
        for (char c : word) {
			i = c-'a';
			if (node->child[i]) node = node->child[i];
			else return false;
		}
		return node->Isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
    	struct TrieNode* node = root;
		int i;
        for (char c : prefix) {
			i = c-'a';
			if (node->child[i]) node = node->child[i];
			else return false;
		}
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
