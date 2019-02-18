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
private:
    map<string,int>subtree;
    vector<TreeNode*>ans;
public:
    void serialize (TreeNode* node, string& outcome) {
        if (!node) {
            outcome+="#";
            return;
        }
        outcome+=(to_string(node->val)+",");
        serialize(node->left, outcome);
        serialize(node->right, outcome);
        return;
    }
    void go (TreeNode* node) {
        if (!node)return;
        string outcome = "";
        serialize (node, outcome);
        //cout << outcome << endl;
        auto it = subtree.find(outcome);
        if (it == subtree.end()) {
            subtree.insert(pair<string,int>(outcome,1));
        } else {
            it->second++;
            if (it->second == 2) {
                //cout << "enter its value: "<< node->val << endl;
                ans.push_back(node);
            }
        }
        go (node->left);
        go (node->right);
        return;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        go (root);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> counts;
        
        dfs(root, res, counts);
        
        return res;
    }
    
    string dfs(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& counts)
    {
        if(!root)
            return "#";
        
        string s = to_string(root->val) + 
            dfs(root->left, res, counts) + 
            dfs(root->right, res, counts);
        
        if(++counts[s] == 2)
        {
            res.push_back(root);
        }
        
        return s;
    }
};


