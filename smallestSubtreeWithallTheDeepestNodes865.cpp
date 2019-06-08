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
    void go (TreeNode* node, vector<TreeNode*>& leaf, int deep, int& deepest) {
        if (!node) return;
        if (deep > deepest) {
            deepest = deep;
            leaf.clear();
            leaf.emplace_back(node);
        } else if (deep == deepest) {
            leaf.emplace_back(node);
        }
        go (node->left, leaf, deep+1, deepest);
        go (node->right, leaf, deep+1, deepest);
    }
    void get (TreeNode* node, int target, vector<TreeNode*>& temp, bool& found) {
        if (!node || found) return;
        temp.emplace_back(node);
        if (node->val == target) {
            found = true;
        }
        get (node->left, target, temp, found);
        get (node->right, target, temp, found);
        if(!found) temp.pop_back();
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) {
            return root;
        }
        int deepest = 0,t;
        vector<TreeNode*> leaf;
        go (root,leaf, 1, deepest);
        bool found = false;
        vector<vector<TreeNode*>>paths;
        for (TreeNode* n:leaf) {
            vector<TreeNode*>temp;
            found = false;
            get(root,n->val,temp,found);
            //for (TreeNode* t:temp)  cout << t->val <<" , ";
            paths.emplace_back(temp);
            temp.clear();
            //cout << endl;
        }
        map<int,int>points;
        auto it = points.begin();
        for (int i = 0; i < paths.size(); ++i) {
            for (int j = paths[i].size()-1; j > -1; j--) {
                it = points.find(paths[i][j]->val);
                if (it == points.end()) {
                    points.insert(pair<int,int>(paths[i][j]->val,1));
                } else {
                    it->second++;
                }
            }
        }
        for (int i = paths[0].size()-1; i > -1; i--) {
            if (points.find(paths[0][i]->val)->second == paths.size()) {
                return paths[0][i];
            }
        }
        return nullptr;
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
    TreeNode *mfunc(TreeNode *root, int &d) {
        if (!root) return NULL;
        ++d;
        int ld = d;
        TreeNode *lnode = mfunc(root->left, ld);
        int rd = d;
        TreeNode *rnode = mfunc(root->right, rd);
        d = max(ld, rd);
        if ((d == ld) && (d == rd)) return root;
        if (d == ld) return lnode;
        return rnode;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int d = 0;
        return mfunc(root, d);
    }
};
