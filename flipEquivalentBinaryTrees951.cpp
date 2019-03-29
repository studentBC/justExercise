class Solution {
public:
    void go (TreeNode* n1, TreeNode* n2, bool& ans) {
        if (!n1 || !n2 || !ans) {
            if (!n1 && !n2) {
                
            } else {
                ans = false;
            }
            return;
        }
        if (n1->left && n2->left && n1->right && n2->right) {
            if (n1->left->val != n2->left->val) {
                if (n1->left->val == n2->right->val && n1->right->val == n2->left->val) {
                    TreeNode* temp = n2->left;
                    n2->left = n2->right;
                    n2->right = temp;
                } else {
                    ans = false;
                    return;
                }
            }
        } else if (n1->left && !n1->right && n2->right && !n2->left) {
            if (n1->left->val == n2->right->val) {
                TreeNode* temp = n2->left;
                n2->left = n2->right;
                n2->right = temp;
            } else {
                ans = false;
                return;
            }
        } else if (!n1->left && n1->right && !n2->right && n2->left) {
            if (n2->left->val == n1->right->val) {
                TreeNode* temp = n2->left;
                n2->left = n2->right;
                n2->right = temp;
            } else {
                ans = false;
                return;
            }
        }
        go (n1->left, n2->left, ans);
        go (n1->right, n2->right, ans);
        return;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        bool ans = true;
        go (root1,root2,ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        
        return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)) || 
                (flipEquiv(root1->right, root2->right) && flipEquiv(root1->left, root2->left));
    }
};
