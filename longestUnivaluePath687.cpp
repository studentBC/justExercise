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
    int go (TreeNode* node, int& ans) {
        if (!node) return 0;
        int left = go (node->left, ans);
        int right = go (node->right, ans);
		int ls = 0, rs = 0;
		if (node->left && node->left->val == node->val) {
			ls+=(left+1);
		}
		if (node->right && node->right->val == node->val) {
			rs+=(right+1);
		}
		ans = max (ans,(ls+rs));
		return max (ls, rs);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        go (root,ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int sq=q.size();
        int i=0;
        TreeNode* t=NULL;
        vector<TreeNode*> temp={};
        stack<vector<TreeNode*>> sta;
        while(!q.empty())
        {
            sq=q.size();
            temp={};
            for(i=0;i<sq;i++)
            {
                t=q.front();
                q.pop();
                temp.push_back(t);
                if(t->left)
                {
                    q.push(t->left);
                    if(t->val != t->left->val)
                    {
                        t->left=NULL;
                    }
                }
                if(t->right)
                {
                    q.push(t->right);
                    if(t->val != t->right->val)
                    {
                        t->right=NULL;
                    }
                }
            }
            sta.push(temp);
        }
        int ret=0;
        while(!sta.empty())
        {
            temp=sta.top();
            sta.pop();
            sq=temp.size();
            for(i=0;i<sq;i++)
            {
                t=temp[i];
                //cout<<i<<" "<<t->val<<" ";
                if(t->left && t->right)
                {
                    t->val=1+max(t->left->val,t->right->val);
                    ret=max(ret,t->left->val+t->right->val);
                }
                else if(t->left && !t->right)
                {
                    t->val=1+t->left->val;
                    ret=max(ret,t->val-1);
                }
                else if(t->right && !t->left)
                {
                    t->val=1+t->right->val;
                    ret=max(ret,t->val-1);
                }
                else
                {
                    t->val=1;
                }
            }
        }
        return ret;
    }
};

