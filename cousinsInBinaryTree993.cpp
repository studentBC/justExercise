class Solution {
public:
    void go (TreeNode* node, int x, int y, pair<int,int>& xinfo, pair<int,int>& yinfo, int level) {
        if (!node || (xinfo.first!=INT_MAX && yinfo.first!=INT_MAX))return;
        if (node->left) {
            if (node->left->val == x) {
                xinfo.first = level+1;
                xinfo.second = node->val;
            } else if (node->left->val == y) {
                yinfo.first = level+1;
                yinfo.second = node->val;
            }
        }
        if (node->right) {
            if (node->right->val == x) {
                xinfo.first = level+1;
                xinfo.second = node->val;
            } else if (node->right->val == y) {
                yinfo.first = level+1;
                yinfo.second = node->val;
            }
        }  
        go (node->left,x,y,xinfo,yinfo,level+1);
        go (node->right,x,y,xinfo,yinfo,level+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int>xinfo(INT_MAX,INT_MAX);// to record its level and parent
        pair<int,int>yinfo(INT_MAX,INT_MAX);       
        go (root,x,y,xinfo,yinfo,0);
        return (xinfo.first == yinfo.first && xinfo.second != yinfo.second);
    }
};

