/*
Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
*/
//reach TLE 
class Solution {
public:
    bool check (vector<string>& temp) {
        for (int i = 0; i < temp.size(); i++) {
            for (int j = 0; j < temp[i].size(); j++) {
                if (temp[i][j] != temp[j][i]) return false;
            }   
        }   
        return true;
    }
    void go (int start, vector<string>& temp, vector<string>& words, int count, vector<vector<string>>& ans) {
        if (count == start) {
            if (check(temp)) ans.push_back(temp);
            return;
        }   
        for (int i = 0; i < words.size(); i++) {
            if (words[i][0] == temp[0][start]) {
                temp.push_back(words[i]);
                go (start+1, temp, words, count, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>>ans;
        for (string s: words) {
            vector<string>temp;
            temp.push_back(s);
            go (temp, words, s.size(), ans);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words[0].size();
        square.resize(n);
        for (string word : words)
            for (int i=0; i<n; i++)
                fulls[word.substr(0, i)].push_back(word);
        build(0);
        return squares;
    
    }
    int n;
    unordered_map<string, vector<string>> fulls;
    vector<string> square;
    vector<vector<string>> squares;
    void build(int i) {
        if (i == n) {
            squares.push_back(square);
            return;
        }
        string prefix;
        for (int k=0; k<i; k++)
            prefix += square[k][i];
        for (string word : fulls[prefix]) {
            square[i] = word;
            build(i + 1);
        }
    }
};
//40 ms solution
class Solution {
    
    struct TrieNode {
        vector<int> prefix;
        TrieNode* childs[26];
        TrieNode () {
            memset(childs, 0, sizeof(childs));
        }
    };
    
    TrieNode* build(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode* p = root;
            for (int j = 0; j < words[i].size(); j++) {
                if (p->childs[words[i][j]-'a'] == NULL) {
                    p->childs[words[i][j]-'a'] = new TrieNode();
                }
                p = p->childs[words[i][j]-'a'];
                p->prefix.push_back(i);
            }
        }
        return root;
    }
    void helper(vector<vector<string>>& ans, vector<string>& board, vector<string>& words, TrieNode* root, int row) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        TrieNode* p = root;
        for (int i = 0; i < row; i++) {
            //cout<<board[i][row]<<endl;
            if (p->childs[board[i][row]-'a'] == NULL) return;
            p = p->childs[board[i][row]-'a'];
        }
        for (int i:p->prefix) {
           // cout<<"prefix is "<<words[i]<<endl;
            board[row] = words[i];
            helper(ans, board, words, root, row+1);
        }
    }
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words[0].size();
        TrieNode* root = build(words);
        vector<vector<string>> ans;
        vector<string> board(n);
        for (int i = 0; i < words.size(); i++) {
            board[0] = words[i];
            helper(ans, board, words, root, 1);
        }
        return ans;
    }
};
