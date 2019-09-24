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
    static bool compare (pair<int,int>& a, pair<int,int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
    void find (TreeNode* node, int step, int& left, int& right) {
        if (!node) return;
        left = min(left, step);
        right = max(right, step);
        find (node->left, step-1, left, right);
        find (node->right, step+1, left, right);
    }
    void go (TreeNode* node, int step, int height, int target, vector<pair<int,int>>& temp) {
        if (!node) return;
        if (step == target) {
            temp.emplace_back(make_pair(height, node->val));
        }
        go (node->left, step-1, height+1, target, temp);
        go (node->right, step+1, height+1, target, temp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int left = INT_MAX, right = INT_MIN;
        find (root, 0, left, right);
        vector<vector<int>>ans;
        //cout <<"left " << left <<" , right " << right << endl;
        for (int i = left; i <= right; i++) {
            vector<pair<int,int>>temp;
            vector<int>tmp;
            go (root, 0, 0, i, temp);
            sort (temp.begin(), temp.end(), compare);
            for (auto& it: temp) {
                tmp.emplace_back(it.second);
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
//the fatest solution
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
