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

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        vector<vector<int>>temp = levelOrder(root);
        for (int i = 0; i < temp.size(); i++) {
            ans.push_back(temp[i][temp[i].size()-1]);
        }
        return ans;
    }

};
//the fatest method
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == NULL)    return ret;
        queue<TreeNode*> myq;
        myq.push(root);
        while(!myq.empty())
        {
            int s = myq.size();
            ret.push_back(myq.front()->val);
            
            for(int i = 0; i < s; i++)
            {
                TreeNode* tmp = myq.front();  myq.pop();
                if(tmp->right != NULL)  myq.push(tmp->right);
                if(tmp->left != NULL)  myq.push(tmp->left);    
            }
        }
        return ret;
    }
};
