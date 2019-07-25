/*
 * You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

Example:

Input: "4(2(3)(1))(6(5))"
Output: return the tree root node representing the following tree:

       4
     /   \
    2     6
   / \   /
  3   1 5

Note:

    There will only be '(', ')', '-' and '0' ~ '9' in the input string.
    An empty tree is represented by "" instead of "()".
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int get (int index, string s) {
        parenthesis.push(s[index]);
        int next;
        for (int j = index+1; j < s.size() && !parenthesis.empty(); j++) {
            if (s[j] == '(') {
                parenthesis.push(s[index]);
            } else if (s[j] == ')') {
                parenthesis.pop();
            } else {
                continue;
            }
            next = j;
        }
        return next;
    }
    TreeNode* str2tree(string s) {
        if (s.size()==0) return nullptr;
        string num = "";
        bool found = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                index = i;
                found = true;
                break;
            } else {
                num+=s[i];
            }   
        }   
        if (!found) {
            //cout <<"new "<<num << endl;
            TreeNode* rt = new TreeNode(stoi(num));
            return rt;
        }   
        next = get(index, s);
        string left, right;
        if (index+1 >= s.size()) {
            left = ""; 
        } else { 
            left = s.substr(index+1, next-index-1);
        }   
        if (next+2 >= s.size()) {
            right = "";
        } else {
            right = s.substr(next+2, s.size()-next-3);
        }   
        //cout << "next is " << next << endl;
        //cout <<"root: "<<num <<"   left:  " << left  << "  right is " << right<< endl;
        TreeNode* root = new TreeNode(stoi(num));
        root->left = str2tree(left);
        //index = next;
        //next = get(index,s);
        //cout <<"go to new right "<< right << endl;
        root->right = str2tree(right);
        return root;
    }

private:
    queue<char>parenthesis;
    int index, next;
};
//the fatest method
class Solution {
public:
    TreeNode *ss(const string &s, int &i) {
        if (i == s.size()) {
            return nullptr;
        }
        
        if (s[i] == ')') {
            return nullptr;
        }
        
        int val = atoi(s.c_str() + i);
        TreeNode *n = new TreeNode(val);
        while (s[i] == '-' || (s[i] >= '0' && s[i] <= '9')) { ++i; }
        
        if (s[i] == '(') {
            n->left = ss(s, ++i);
        }
        
        if (s[i] == '(') {
            n->right = ss(s, ++i);
        }
        
        if (s[i] == ')') {
            ++i;
        }
        return n;
    }

    TreeNode* str2tree(string s) {
        int i = 0;
        return ss(s, i);
    }
};
//beat 97% method
public TreeNode str2tree(String s) {
    if (s == null || s.length() == 0) return null;
    int firstParen = s.indexOf("(");
    int val = firstParen == -1 ? Integer.parseInt(s) : Integer.parseInt(s.substring(0, firstParen));
    TreeNode cur = new TreeNode(val);
    if (firstParen == -1) return cur;
    int start = firstParen, leftParenCount = 0;
    for (int i=start;i<s.length();i++) {
        if (s.charAt(i) == '(') leftParenCount++;
        else if (s.charAt(i) == ')') leftParenCount--;
        if (leftParenCount == 0 && start == firstParen) {cur.left = str2tree(s.substring(start+1,i)); start = i+1;}
        else if (leftParenCount == 0) cur.right = str2tree(s.substring(start+1,i));
    }
    return cur;
}

