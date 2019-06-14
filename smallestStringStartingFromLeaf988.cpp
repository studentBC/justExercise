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
    void go (TreeNode* node, string temp, string& ans) {
        if (!node)return;
        temp+=((char)(node->val+'a'));
        if (!node->left && !node->right) {
            reverse(temp.begin(), temp.end());
            if (ans.size() == 0) {
                ans = temp;
            } else {
                //cout << temp <<"  " << ans << endl;
                bool changed = false;
                for (int i = 0, j = 0; i < ans.size() && j < temp.size(); ++i,++j) {
                    //cout << ans[i] <<"   " << temp[j] << endl;
                    if (ans[i] > temp[j]) {
                        ans = temp;
                        changed = true;
                        break;
                    } else if (ans[i] < temp[j]) {
                        changed = true;break;
                    }
                }
                if (!changed && temp.size() < ans.size()) ans = temp;
            }
        }
        //cout << ans << endl;
        go (node->left, temp, ans);
        go (node->right, temp, ans);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "", temp = "";
        go (root,temp,ans);
        return ans;
    }
};
//the fatest method
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
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return res;
    }
    void dfs(TreeNode* root, string str) {
        if(!root)   return;
        str = (char)('a' + root->val) + str;
        if(!root->left && !root->right) {
            res = !res.size() || res > str ? str : res;
            return;
        }  
        dfs(root->left, str);
        dfs(root->right, str);
    }
private:
    string res;
};
