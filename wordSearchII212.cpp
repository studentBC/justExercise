class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> next= std::vector<TrieNode*>(26, nullptr);
        string word="";
    };
    int step[5] = {0,-1, 0, 1, 0};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        TrieNode* root = build(words);
        //cout <<"here";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                   /*for (int a = 0; a < board.size(); a++) {
                        for (int b = 0; b < board[a].size(); b++) {
                            cout << board[a][b] <<", ";
                        }
                       cout << endl;
                   }*/
                //vector<vector<char>>temp = board;
                go (i, j, board, root, ans);
            }
        }
        return ans;
    }
    void go (int i, int j, vector<vector<char>>& board, TrieNode* p, vector<string>& ans) {
        if (i < 0 || i >= board.size() || j < 0 || j>= board[0].size()) return;
        char c = board[i][j];
        
        //cout << c <<", ";
        if (c == '$' || p->next[c-'a'] == NULL) return;
        p = p->next[c-'a'];
        if (p->word.size()) {
                ans.push_back(p->word);
                p->word = "";
        }
        //cout <<"jere";
        board[i][j] = '$';
        int x, y;
        for (int a = 0; a < 4; a++) {
            x = i+step[a];
            y = j +step[a+1];
            //if (x < 0 || x >= board.size() || y < 0 || y>= board[0].size()) continue;
            go (x, y, board, p, ans);
        }
        board[i][j] = c;
    }
    TrieNode* build (vector<string>& words) {
        TrieNode* root = new TrieNode;
        for (string& s: words) {
            TrieNode* p = root;
            for (char c : s) {
                int i = c-'a';
                if (p->next[i] == NULL) {
                    p->next[i] = new TrieNode;
                }
                p = p->next[i];
            }
            p->word = s;
        }

        return root;
    }
};
