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
    void postT(TreeNode* node, vector<int>& members,vector<vector<int>>& allpath) {
    members.push_back(node->val);
    if (node->right == NULL && node->left == NULL) {
        allpath.push_back(members);
    }
    //printf("node: %d   ",node->val);
   // printf("sum: %d\n",*sum);
    if (node->left) {
        postT(node->left,members,allpath);
    } else if (node->right == NULL) {
        members.pop_back();
        return;
    }
    if (node->right) {
        postT(node->right,members,allpath);
    } else {
        members.pop_back();
        return;
    }
    members.pop_back();
    
    return;
}
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        vector<int>members;
        vector<vector<int>>allpath;
        postT(root,members,allpath);
        int allsize = allpath.size();
        int sum = 0,digitplace;
        for (int i = 0; i < allsize; i++) {
            int len = allpath[i].size();
            digitplace = len-1;
            for (int j = 0; j < len; j++) {
                sum+=allpath[i][j]*pow(10,digitplace);
                digitplace--;
            }
        }
        return sum;
    }
};
