class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
            if (s[i] != s[j]) return false; // Exit and return error if not match
        }

        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        if (words.size() < 2) return ans;
        unordered_map<string,int>mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string str1 = words[i].substr(0,j);
                string str2 = words[i].substr(j);
                if (isPalindrome(str1)) {
                    string rstr2 = str2;
                    reverse(rstr2.begin(), rstr2.end());
                    if (mp.find(rstr2)!=mp.end() && mp[rstr2] != i) {
                        vector<int>temp;
                        temp.emplace_back(mp[rstr2]);
                        temp.emplace_back(i);
                        ans.emplace_back(temp);
                    }
                }
                if (isPalindrome(str2)) {
                    reverse(str1.begin(), str1.end());
                    if (mp.find(str1)!=mp.end() && mp[str1] != i && str2.size()) {
                        vector<int>temp;
                        temp.emplace_back(i);
                        temp.emplace_back(mp[str1]);
                        ans.emplace_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};
//the fatest solution
//class Trie {
    struct Node {
        array<Node*,26> branch{nullptr};
        int wordId = -1;
        Node *getBranch(char ch) {
            return branch[ch-'a'];
        }
        void setBranch(char ch, Node *node) {
            branch[ch-'a'] = node;
        }
        bool isTerm() { return wordId != -1; }
    };

    Node *fwRoot, *bkRoot;

public:
    Trie() {
        fwRoot = new Node;
        bkRoot = new Node;
    }

    void insertBackward(string &word, int wordId) {
        auto p = bkRoot;
        for (int i = int(word.size())-1; i >= 0; --i) {
            char ch = word[i];
            if (!p->getBranch(ch)) {
                p->setBranch(ch, new Node);
            }
            p = p->getBranch(ch);
        }
        p->wordId = wordId;
    }

    void insertForward(string &word, int wordId) {
        auto p = fwRoot;
        for (char ch : word) {
            if (!p->getBranch(ch)) {
                p->setBranch(ch, new Node);
            }
            p = p->getBranch(ch);
        }
        p->wordId = wordId;
    }

    void findPP(
            vector<string> &words, int wordId, vector<vector<int>> &res,
            unordered_map<uint64_t,pair<int,int>> &tmpRes)
    {
        auto p = bkRoot;
        string &word = words[wordId];
        // words[p->wordId] is empty string
        if (p->isTerm() && isPalindrome(word, 0, int(word.size())-1) && p->wordId != wordId) {
            //putResult(res, wordId, p->wordId);
            res.push_back({wordId, p->wordId});
        }
        int i = 0;
        for (; i < word.size(); ++i) {
            p = p->getBranch(word[i]);
            if (p) {
                if (p->isTerm() && isPalindrome(word, i+1, int(word.size())-1) && p->wordId != wordId) {
                    if (word.size() == words[p->wordId].size()) {
                        putResult(tmpRes, wordId, p->wordId);
                    } else {
                        res.push_back({wordId, p->wordId});
                    }
                }
            } else {
                break;
            }
        }
        if (i == word.size()) {
            // reversed words[wordId] is postfix of (or equals to) other string(s)
            insertForward(word, wordId);
        }

    }

    void findPPByPrefix(
            vector<string> &words, int wordId, vector<vector<int>> &res,
            unordered_map<uint64_t,pair<int,int>> &tmpRes)
    {
        auto p = fwRoot;
        string &word = words[wordId];
        // words[p->wordId] is empty string
        if (p->isTerm() && isPalindrome(word, 0, int(word.size())-1) && p->wordId != wordId) {
            res.push_back({p->wordId, wordId});
        }
        for (int i = int(word.size())-1; i >= 0; --i) {
            p = p->getBranch(word[i]);
            if (p) {
                if (p->isTerm() && isPalindrome(word, 0, i-1) and p->wordId != wordId) {
                    if (word.size() == words[p->wordId].size()) {
                        putResult(tmpRes, p->wordId, wordId);
                    } else {
                        res.push_back({p->wordId, wordId});
                    }
                }
            } else {
                break;
            }
        }
    }

    void putResult(unordered_map<uint64_t,pair<int,int>> &res, int id1, int id2) {
        uint64_t hash = static_cast<uint64_t>(id1) << 32;
        hash |= static_cast<uint64_t>(id2);
        res[hash] = make_pair(id1, id2);
    }

    bool isPalindrome(string &word, int i, int j) {
        while (i < j && word[i] == word[j]) {
            ++i;
            --j;
        }
        return i >= j;
    }

};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        for (int _id = 0; _id < words.size(); ++_id) {
            trie.insertBackward(words[_id], _id);
        }

        vector<vector<int>> res;
        unordered_map<uint64_t,pair<int,int>> s;
        for (int _id = 0; _id < words.size(); ++_id) {
            trie.findPP(words, _id, res, s);
        }

        for (int _id = 0; _id < words.size(); ++_id) {
            trie.findPPByPrefix(words, _id, res, s);
        }

        for (auto &p : s) {
            res.push_back({p.second.first, p.second.second});
        }
        return res;
    }
};

auto _ = [](){ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
