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
    unordered_map<TreeNode*, string>node;
    vector<TreeNode*>ans;
    void go (TreeNode* n, string& s) {
        if(!n) {
            s+="$";
            return;
        }
        s+=to_string(n->val)+",";
        go(n->left, s);
        go(n->right, s);
        
    }
    void Go (TreeNode* n) {
        if(!n) return;
        string s;
        go (n, s);
        node[n] = s;
        Go(n->left);
        Go(n->right);
    }
    static bool compare(pair<string, TreeNode*>& a, pair<string, TreeNode*>& b) {
        if (a.first.size() == b.first.size()) return a < b;
        return a.first.size() > b.first.size();
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        Go (root);
        vector<pair<string, TreeNode*>>nn;
        for (auto& it : node) {
            nn.push_back({it.second, it.first});
        }
        sort(nn.begin(), nn.end(), compare);
        TreeNode*start = NULL;
        unordered_set<string>uniq;
        for (int i = 0; i < nn.size(); i++) {
            for (int j = i+1; j < nn.size(); j++) {
                if (nn[i].first.size() < nn[j].first.size()) break;
                if (nn[i].first == nn[j].first) {
                    start = nn[i].second;
                    if (!uniq.count(nn[i].first)) {
                        ans.push_back(start);
                        uniq.insert(nn[i].first);
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
