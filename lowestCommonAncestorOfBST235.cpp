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
    void go (TreeNode* node, int big, int small, TreeNode** ans) {
        if (!node||*ans)return;
        if (node->val <= big && node->val >= small) {
            //cout << node->val << "  " << node <<endl;
            *ans = node;
            //node = ans;
            //cout << ans << endl;
            return;
        }
        go (node->left, big, small, ans);
        go (node->right, big, small, ans);
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode** ans = (TreeNode**)calloc(1,sizeof(TreeNode*));
        *ans = NULL;
        if (p->val > q->val) {
            go (root, p->val, q->val, ans);
        } else if (p->val < q->val) {
            go (root, q->val, p->val, ans);
        } else {
            return p;
        }
        //cout << ans << endl;
        return *ans;
    }
};
//the fatest method
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if(!p)
            return q;
        if(!q)
            return p;
        /*if(p->left == q || p->right == q)
            return p;
        if(q->left == p || q->right == p)
            return q;*/
        if((p->val <= root->val && q->val >= root->val) || 
           (p->val >= root->val && q->val <= root->val))
            return root;
        
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        
        return lowestCommonAncestor(root->right, p, q);
    }
};
