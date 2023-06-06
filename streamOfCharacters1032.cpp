class StreamChecker {
public:
    string ss;
    int len = 0;
    vector<string>w;
    StreamChecker(vector<string>& words) {
        w = words;
    }
    
    bool query(char letter) {
        ss.push_back(letter);
        len++;
        for (string& s: w) {
            if (s.size() <= len) {
                bool valid = true;
                for (int i = len-1, j = s.size()-1; j > -1; i--, j--) {
                    if (ss[i]!=s[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

class TrieNode {
    public:
        TrieNode *n[26];
        bool strPresent;
        TrieNode() {
            for(int i = 0; i < 26; i++) {
                this->n[i] = NULL;
                this->strPresent = false;
            }
        }
};
string inputStr;
class StreamChecker {
    TrieNode *root;

    void buildTrie(string &str) {
        TrieNode *current = root;
        for(int i = 0; i < str.size(); i++) {
            int val = str[i] - 'a';
            if(current->n[val] == NULL) {
                current->n[val] = new TrieNode();
            }
            current = current->n[val];
        }
        current->strPresent = true;
        inputStr = "";
    }

    bool searchTrie(string &str) {
        TrieNode *current = root;
        for(int i = str.size()-1; i >= 0; i--) {
            int val = str[i] - 'a';
            current = current->n[val];
            if(current == NULL) return false;
            if(current->strPresent) return true;
        }
        return false;
    }

public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode;

        for(auto &str : words) {
            reverse(str.begin(), str.end());
            buildTrie(str);
        }
    }

    bool query(char letter) {
        inputStr += letter;
        return searchTrie(inputStr);

    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
