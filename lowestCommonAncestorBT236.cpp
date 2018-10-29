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
    void find(TreeNode* node, int target, vector<TreeNode*>& ancestor, bool* found) {
        //cout<<*found << endl;
        if (node == NULL || *found) {
            return;
        }
   
        if (!*found) {
            //cout<<"push: " << node->val << endl;
            ancestor.push_back(node);
        }

        if (node->val == target) {
            *found = true;
        }

        find(node->left,target,ancestor,found);
        find(node->right,target,ancestor,found);

        if (!*found) {
            //cout<<"pop: " << ancestor[ancestor.size()-1]->val << endl;
            ancestor.pop_back();
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool* found = new bool(false);
        vector<TreeNode*>ancestor;
        vector<TreeNode*>Ancestor;
        find(root, p->val, ancestor, found);
        //cout<<"----------------------" << endl;
        *found = false;
        find(root, q->val, Ancestor, found);
        int plen = ancestor.size() , qlen = Ancestor.size();
        if (plen > qlen) {
            for (int i = plen -1; i > -1; i--) {
                for (int j = qlen-1; j > -1; j--) {
                    if (ancestor[i]->val == Ancestor[j]->val) {
                        return ancestor[i];
                    }
                }
            }
        } else {
            for (int i = qlen -1; i > -1; i--) {
                for (int j = plen-1; j > -1; j--) {
                    if (ancestor[j]->val == Ancestor[i]->val) {
                        return ancestor[i];
                    }
                }
            }
        }
        return NULL;
        
    }
    

};
