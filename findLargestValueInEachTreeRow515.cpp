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
	vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> l;
        int c_l {0};
        int actual_l {0};
        vector<vector<int>> result;
        TreeNode* c;

        vector<int>* level {new vector<int>};

        if (root == NULL) return result;

        q.push(root);
        l.push(c_l);

        while (q.size() > 0){
            c = q.front();
            q.pop();
            c_l = l.front();
            l.pop();
            if (c_l == actual_l){
                level->push_back(c->val);
            }
            else{
                result.push_back(*level);
                level = new vector<int>;
                level->push_back(c->val);
                actual_l++;
            }

            if (c->left != NULL) {
                q.push(c->left);
                l.push(c_l+1);
            }
            if (c->right != NULL){
                q.push(c->right);
                l.push(c_l+1);
            }
            if(q.empty()){
                result.push_back(*level);
            }
        }
        return result;
    }

    vector<int> largestValues(TreeNode* root) {
		vector<vector<int>>temp = levelOrder(root);
		vector<int>ans;
		int max;
		for (int i = 0; i < temp.size(); i++) {
			max = INT_MIN;
			for (int j = 0; j < temp[i].size(); j++) {
				if (max < temp[i][j]) max = temp[i][j];
			}
			ans.push_back(max);
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
vector<int> largestValues(TreeNode* root) {
    vector<int> vec;
    if(not root) {
        return vec;
    }
    queue<TreeNode *> que;
    que.push(root);
    
    while(not que.empty()) {
        size_t sz = que.size();
        int mx = INT_MIN;
        for(int i = 0; i < sz; ++i) {
            auto *node = que.front();
            que.pop();
            mx = max(mx, node->val);
            if(node->left) {
                que.push(node->left);
            }
            if(node->right) {
                que.push(node->right);
            }
        } // end of for
        vec.push_back(mx);
    } // end of while

    return vec;
}
};
