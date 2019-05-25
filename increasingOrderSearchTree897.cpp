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
    void go (TreeNode* node, TreeNode* prev, vector<TreeNode *>& nodes) {
        if (!node) {
            return;
        }
        go (node->left, node,nodes);
        nodes.emplace_back(node);
        go (node->right, node,nodes);
        
        //cout << node->val <<" , " << prev->val << endl; 
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode *>nodes;
        TreeNode* start;
        //bool first = true;
        go (root,nullptr,nodes);
        root = start = nodes[0];
        //cout << "start root : "<<(root)->val << endl;
        TreeNode* prev = root;
        for (int i = 1; i < nodes.size(); i++) {
            //cout << nodes[i]->val <<" , ";
            prev->right = nodes[i];
            prev->left = NULL;
            prev = prev->right;
        }
        prev->right = prev->left = NULL;
        
        return root;
    }
};
//the fatest method
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode *prev = NULL,*head;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();
                if(!prev){
                    prev = root;
                    head = root;
                } else {
                    prev->right = root;
                    prev->left = NULL;
                    prev = prev->right;
                }
                root = root->right;
            }
        }
        if(prev) {
            prev->left = NULL;
        }
        return head;
    }
};
