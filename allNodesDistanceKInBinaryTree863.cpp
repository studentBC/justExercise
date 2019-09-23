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
    void go(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (!node) return;
        if (graph.find(node) == graph.end()) {
            if (parent)  {
                graph[node].emplace_back(parent);
                graph[parent].emplace_back(node);
            }
            go(node->left, node, graph);
            go(node->right, node, graph);
        }
    }   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, vector<TreeNode*>>graph;
        go (root, NULL, graph);
        vector<int>ans;
        unordered_set<TreeNode*>visited;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(target, 0));
        visited.insert(target);
        TreeNode* next;
        while (!q.empty()) {
            next = q.front().first;
            visited.insert(next);
            if (K == q.front().second) {
                ans.emplace_back(q.front().first->val);
            } else if (K < q.front().second) {
                return ans;
            }

            for (TreeNode* tn : graph[next]) {
                if (visited.find(tn) != visited.end()) continue;
                q.push(make_pair(tn, q.front().second+1));
            }

            q.pop();
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
    void getNodesAtDistanceKBelow(TreeNode* root, int K, vector<int>& res) {
        if (!root) return;
        if (K == 0) {
            res.push_back(root->val);
            return;
        }
        getNodesAtDistanceKBelow(root->left, K-1, res);
        getNodesAtDistanceKBelow(root->right, K-1, res);
    }
    pair<bool, int> getNodesAtDistanceKAbove(TreeNode* root, TreeNode* target, int K, vector<int>& res) {
        if (!root) return {false, -1};
        if (root == target) return {true, 1};
        auto left = getNodesAtDistanceKAbove(root->left, target, K, res);
        auto right = getNodesAtDistanceKAbove(root->right, target, K, res);
        if (left.first || right.first) {
            int dist = left.first ? left.second : right.second;
            if (dist == K) {
                res.push_back(root->val);
            } else if (dist < K) {
                getNodesAtDistanceKBelow(left.first ? root->right : root->left, K-dist-1, res);
            }
            return {true, dist+1};
        }
        return {false, -1};
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        getNodesAtDistanceKBelow(target, K, result);
        if (root != target && K > 0) {
            getNodesAtDistanceKAbove(root, target, K, result);
        }
        return result;
    }
};
