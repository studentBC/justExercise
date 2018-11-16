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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>nodes;
        queue<int>level;
        //cout << level.front() << endl;
        vector<vector<int>>answer;
        vector<int>ans;
        TreeNode* anode;
        int count = 1, prev = 0;
        if (!root)return answer;
        nodes.push(root);
        level.push(count);

        while(!nodes.empty()) {
            anode = nodes.front();
            nodes.pop();
            count = level.front();
            level.pop();
            //handle node value
            ans.push_back(anode->val);
            //cout << count << " , " << level.front() << endl;
            if (level.empty() || level.front()!=count ) {
                answer.push_back(ans);
                ans.clear();
            } 
            
            count++;
            if (anode->left) {
            	nodes.push(anode->left);
                level.push(count);
            }
            if (anode->right) {
                nodes.push(anode->right);
                level.push(count);
            }

        }
		for (int i = 1; i < answer.size(); i+=2) {
			reverse(answer[i].begin(),answer[i].end());
		}
        return answer;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        // check empty
        if(!root) return res;
        que.push(root);
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            vector<int> temp(size, 0);
            int index;
            if(level%2==0){
                index = 0;
            } else {
                index = size-1;
            }
            for(int i=0;i<size;i++){
                TreeNode* cur = que.front();
                que.pop();
                temp[index] = cur->val;
                if(level%2==0){
                    index++;
                } else {
                    index--;
                }
                if(cur->left){
                    que.push(cur->left);
                }
                if(cur->right){
                    que.push(cur->right);
                }
            }
            res.push_back(temp);
            level++;
        }
        return res;
    }
};
