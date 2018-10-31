/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*>tq;
        queue<int>levelq;
        vector<int>lq;
        vector<TreeLinkNode*>vq;
        if (root == NULL) {
            return ;
        }
        int count;
        tq.push(root);
        levelq.push(1);
        TreeLinkNode* node;
        while(!tq.empty()) {
            node = tq.front();
            tq.pop();
            vq.push_back(node);
            count = levelq.front();
            levelq.pop();
            lq.push_back(count);
            /*
            */
            if (node->left) {
                tq.push(node->left);
                levelq.push(count+1);
            }
            if (node->right) {
                tq.push(node->right);
                levelq.push(count+1);
            }
        }
        int len = lq.size() -1;
        for (int i = 0; i < len; i++) {
            if (lq[i]!= lq[i+1]) {
                vq[i]->next = NULL;
            } else {
                vq[i]->next = vq[i+1];
            }
        }
		vq[len]->next = NULL;
        return ;   
    }

};
//fatest method
    void connect(TreeLinkNode *root) {
        if(root == NULL)    return;
        if(root->left == NULL && root->right == NULL)   return;
        TreeLinkNode* left = root->left;
        TreeLinkNode* right = root->right;
        while(left)
        {
            left->next = right;
            left = left->right;
            right = right->left;
        }
        connect(root->left);
        connect(root->right);
    }
