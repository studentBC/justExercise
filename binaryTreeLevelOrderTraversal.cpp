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
        vector<vector<int>>ans;
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
        return ans;
    }
};
//fatest method
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
};
