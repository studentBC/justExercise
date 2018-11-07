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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        vector<vector<int>>answer;
        vector<int>level;
        queue<TreeNode*>tq;
        queue<int>levelq;
        vector<int>lq;
        vector<int>vq;
        if (root == NULL) {
            return ans;
        }
        int count;
        tq.push(root);
        levelq.push(1);
        //level.push_back(root->val);
        TreeNode* node;
        while(!tq.empty()) {
            node = tq.front();
            tq.pop();
            vq.push_back(node->val);
            count = levelq.front();
            levelq.pop();
            lq.push_back(count);
            /*
            if ( count%2 == 1 ) {
                ans.push_back(level);
                level.clear();
            }
            */
            if (node->left) {
                tq.push(node->left);
                levelq.push(count+1);
                //level.push_back(node->left->val);
            }
            if (node->right) {
                tq.push(node->right);
                levelq.push(count+1);
                //level.push_back(node->right->val);
            }
        }
        int len = lq.size();
        for (int i = 0; i < len; i++) {
                level.push_back(vq[i]);
            if (lq[i]!= lq[i+1]) {
                ans.push_back(level);
                level.clear();
            }
        }

        while (!ans.empty()) {
            answer.push_back(ans.back());
            ans.pop_back();
        }
        return answer;
    }
};
