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
    void go (TreeNode* node, TreeNode* parent, int& count) {
        if (!node) return;
        go (node->left, node, count);
        go (node->right, node, count);
        if ( (node->right && node->right->val > -1) || (node->left && node->left->val > -1)) {
            node->val = -1;
            if (node->right) node->right->val = -1;
            if (node->left) node->left->val = -1;
            if (parent) parent->val = -1;
            count++;
        }
        if (!parent && node->val > -1) {
            node->val = -1;
            if (node->right) node->right->val = -1;
            if (node->left) node->left->val = -1;
            count++;
        }
    }
    int minCameraCover(TreeNode* root) {
        int count = 0;
        go (root, nullptr,count);
        return count;
    }
};

/**
 * my original method which cant pass the test ... but it can make me know pointer more (dereference and reference)
 * the actual value save in pointer is address of the obj it points , the dereference is an operator which can use the value which this p	ointer point to
  we can make a conclusion  that 
  & is the address-of operator, and can be read simply as "address of"
  * is the dereference operator, and can be read as "value pointed to by"

 */
class Solution {
public:
    void findmax(TreeNode** node, TreeNode** parent, int& big, TreeNode** & biggest, TreeNode** & bigparent) {
        if (!*node) return;
        //cout << (*node)->val <<" , ";
        int temp = check (*node,*parent);
        if (temp >= big) {
            big = temp;
            biggest = node;
            if (parent) {
                bigparent = parent;
            }
            //cout<<"biggest: " << *biggest << endl;
        }
        findmax(&((*node)->left),node,big,biggest,bigparent);
        findmax(&((*node)->right),node,big,biggest,bigparent);
    }
    int check (TreeNode* node, TreeNode* parent) {
        if (!node) return 0;
        int count = 0;
        if (node->val > -1)count++;
        if (parent && parent->val > -1) count++;
        if (node->left && node->left->val > -1) {
            count++;
            if (!node->left->right && !node->left->left) count+=2;
        }
        if (node->right && node->right->val > -1) {
            count++;
            if (!node->right->right && !node->right->left) count+=2;
        }
        return count;
    }
    void travel (TreeNode* root, int& nodes) {
        if (!root)return;
        nodes++;
        travel(root->left,nodes);
        travel(root->right,nodes);
    }
    int minCameraCover(TreeNode* root) {
        int count = 0, nodes = 0, big = 0;
        travel(root,nodes);
        TreeNode** biggest = NULL;
        TreeNode** bigparent = NULL;
        TreeNode** Node = NULL;
        TreeNode* ptr = nullptr;
        TreeNode** Parent = &ptr;

        while (nodes > 0) {
            Node = &root;
            Parent = &ptr;
            big = 0;
            findmax(Node,Parent,big,biggest,bigparent);
            //cout <<endl<<"found:  "<< *biggest << endl;
            if(*bigparent && (*bigparent)->val > -1) {
                (*bigparent)->val = -1;
                nodes--;
            }
            if ((*biggest)->val > -1) {
                (*biggest)->val = -1;
                nodes--;
            }
            if ( (*biggest)->left && (*biggest)->left->val > -1) {
                (*biggest)->left->val = -1;
                nodes--;
            }
            if ( (*biggest)->right && (*biggest)->right->val > -1) {
                (*biggest)->right->val = -1;
                nodes--;
            }
            count++;
        }
        return count;
    }
};

