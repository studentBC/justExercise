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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) { 
            TreeNode* ancestor = new TreeNode(v);
            ancestor->left = root;
            return ancestor;
        }
        queue<TreeNode*>node;
        queue<int>level;
        node.push(root);
        level.push(1);
        int curlevel;TreeNode* cn, * temp;
        bool found;
        while (node.size() && level.front() < d) {
            curlevel = level.front();
            cn = node.front();
            level.pop();node.pop();
            if (curlevel+1 == d) {
                found = false;
                if (cn->left) {
                    temp = cn->left;
                    cn->left = new TreeNode(v);
                    cn->left->left = temp;
                    node.push(cn->left);
                    level.push(d);
                }  else {
                    cn->left = new TreeNode(v);
                    node.push(cn->left);
                    level.push(d);
                }
                if (cn->right) {
                    temp = cn->right;
                    cn->right = new TreeNode(v);
                    cn->right->right = temp;
                    node.push(cn->right);
                    level.push(d);
                } else {
                    cn->right = new TreeNode(v);
                    node.push(cn->right);
                    level.push(d);
                }
            }
            if (cn->left) {
                node.push(cn->left);
                level.push(curlevel+1);
            }
            if (cn->right) {
                node.push(cn->right);
                level.push(curlevel+1);
            }
        }
        return root;
    }
};
//the fatest method there exists an interesting method a function in a function
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (!root) return new TreeNode(v);
        if (1 == d) {
            auto t = new TreeNode(v);
            t->left = root;
            return t;
        }
        
        auto add = [](vector<TreeNode*> l, int v) {
            for (auto &c: l) {
                auto old = c->left;
                c->left = new TreeNode(v);
                c->left->left = old;
                
                old = c->right;
                c->right = new TreeNode(v);
                c->right->right = old;
            }
        };
        
        vector<TreeNode*> level{root};
        vector<TreeNode*> last_level;
        vector<TreeNode*> temp;
        int cnt = 1;
        while (!level.empty()) {
            temp.clear();
            cnt++;
            
            for (auto &c: level) {
                if (c->left) temp.push_back(c->left);
                if (c->right) temp.push_back(c->right);
            }
            
            if (d == cnt) add(level, v);
            if (temp.size()) last_level = temp;
            level.swap(temp);
        }
        
        return root;
    }
};
