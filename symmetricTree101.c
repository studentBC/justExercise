/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool ismirror(struct TreeNode* t1 , struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    if ( t1 && t2 && t1->val == t2->val ) {
        printf("%d\n",t1->val);
        return ismirror(t1->left,t2->right) && ismirror(t1->right,t2->left);
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    return ismirror(root,root);
}
// my solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void go1 (TreeNode* node, vector<int>& temp) {
        if (!node) {
            temp.push_back(200);
            return;
        }
        temp.push_back(node->val);
        go1 (node->left, temp);
        go1 (node->right, temp);
    }
    void go2 (TreeNode* node, vector<int>& temp) {
        if (!node) {
            temp.push_back(200);
            return;
        }
        temp.push_back(node->val);
        go2 (node->right, temp);
        go2 (node->left, temp);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int>one, two;
        if (root->left && root->right) {
            go1 (root->left, one);
            go2 (root->right, two);
            if (one.size()!=two.size()) return false;
            else {
                for (int i = 0; i < one.size(); i++) if (one[i]!=two[i]) return false;
                return true;
            }
        } else if (root->left == NULL && root->right == NULL) return true;
        else return false;
    }
};



//others solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return checkMirror(root->left, root->right);
    }
    bool checkMirror(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL) return true;
        if(left==NULL || right==NULL) return false;
         
        if(left->val != right->val) return false;
        else {
            return checkMirror(left->left, right->right)&&checkMirror(left->right, right-> left);
        }
    }
};
};
