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
    int ans = 0;
    bool check (TreeNode* node, int small, int big, int& sum) {
        if (!node) return true;
        if (node->val < small || node->val > big) return false;
        sum+=node->val;
        return  check (node->left, small, node->val-1, sum) && check(node->right, node->val+1, big, sum);
    }
    void go (TreeNode* node) {
        if (!node) return;
        go (node->left);
        int sum = 0;
        if (check(node, INT_MIN, INT_MAX, sum)) ans = max (ans, sum);
        go (node->right);
        return;
    }
    int maxSumBST(TreeNode* root) {
        go (root);
        return ans;
    }
};


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
    int maxSum;
    
    pair<int, int> checkIsBst(TreeNode* root) {
        if (root == nullptr) 
            return make_pair(1, 0);
        
        pair<int, int> lres = checkIsBst(root->left);
        pair<int, int> rres = checkIsBst(root->right);
        pair<int, int> curr = {0, 0};
        
        if (
            (lres.first == 1 && rres.first == 1) && 
            (
                (root->left == nullptr && root->right == nullptr) || 
                (root->left != nullptr && root->right == nullptr && root->val > root->left->val) || 
                (root->left == nullptr && root->right != nullptr && root->val < root->right->val) || 
                (root->left != nullptr && root->right != nullptr && root->val > root->left->val && root->val < root->right->val)
            )
        ) 
        {
            // The tree rooted at this current node is BST
            curr.first = 1;
            curr.second = (lres.second + rres.second + root->val);
            // if (curr.second < 0) {
            //     curr.second = 0;
            // }
            maxSum = max(maxSum, curr.second);
        } else {
            curr.first = 0;
            curr.second = 0;
        }
        return curr;
    }
public:
    
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        maxSum = 0;
    }
    
    int maxSumBST(TreeNode* root) {
        checkIsBst(root);
        return maxSum;
    }
};
