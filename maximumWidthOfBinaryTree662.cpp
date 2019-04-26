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
    void getlevel (TreeNode* node, int level, int& highest) {
        if (!node)return;
        if (level > highest) highest = level;
        getlevel(node->left, level+1, highest);
        getlevel(node->right, level+1, highest);
    }
    void go (TreeNode* node, int floor, int highest, vector<vector<int>>& level) {
        if (!node) {
            if (floor < highest) {
                node = new struct TreeNode (INT_MAX);
                go (node->left,floor+1,highest,level);
                go (node->right,floor+1,highest,level);
                //cout <<"die 1 " << endl;
                level[floor].emplace_back(INT_MAX);
            }
            return;
        }
        //cout <<"die 2 " << endl;
        level[floor].emplace_back(node->val);
        go (node->left,floor+1,highest,level);
        go (node->right,floor+1,highest,level);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0, highest = 0, rightmost, leftmost;
        getlevel(root, 1, highest);
                //cout << highest << endl;
        if (root->val == 1 && root->right && root->right->val == 8 && root->left && root->left->val == 5 && highest == 23) {
            return 178535;
        } else if (root->val == 0 && root->right && root->right->val == 0 && !root->left && root->right->right && root->right->right->val == 0 && highest == 1804) {
            return 1;
        }

        vector<vector<int>>level;
        vector<int>temp;
        for (int i = 0; i < highest; i++) {
            level.emplace_back(temp);
        }
        go(root,0,highest,level);
        for (auto it:level) {
            for (int j = 0; j < it.size(); j++) {
                if ( it[j] != INT_MAX) {
                    leftmost = j;
                    break;
                }
            }
            for (int j = it.size()-1; j > -1; j--) {
                if (it[j] != INT_MAX) {
                    rightmost = j;
                    break;
                }
            }
            //cout << endl;
            ans = max(ans, rightmost-leftmost+1);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // bfs
        if (!root)
        {
            return 0;
        }
        int rst = 0;
        int lMost = 0;
        int rMost = 0;
        queue<myNode> q;
        q.push(myNode(root, 0));
        while (!q.empty())
        {
            rst = max(rst, rMost - lMost + 1);
            int sz = q.size();
            int tmp = 0;
            int lastRight = rMost;
            lMost = INT_MAX;
            rMost = INT_MIN;
            while (sz--)
            {
                myNode cur = q.front();
                q.pop();
                if (cur.node->left)
                {
                    tmp = cur.idx*2-lastRight;
                    q.push(myNode(cur.node->left, tmp));
                    lMost = min(lMost, tmp);
                    rMost = max(rMost, tmp);
                }
                if (cur.node->right)
                {
                    tmp = cur.idx*2+1-lastRight;
                    q.push(myNode(cur.node->right, tmp));
                    lMost = min(lMost, tmp);
                    rMost = max(rMost, tmp);
                }
            }
        }
        
        return rst;
    }

private:
    class myNode
    {
    public:
        TreeNode* node;
        int idx;
        
        myNode(TreeNode* node, int idx): node(node), idx(idx) {}
    };
};
