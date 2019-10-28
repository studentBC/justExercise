/*
	The basic idea is here:
	Say we have 2 arrays, PRE and IN.
	Preorder traversing implies that PRE[0] is the root node.
	Then we can find this PRE[0] in IN, say it's IN[5].
	Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
	Recursively doing this on subarrays, we can build a tree out of it

    Our aim is to find out the index of right child for current node in the preorder array
    We know the index of current node in the preorder array - preStart (or whatever your call it), it's the root of a subtree
    Remember pre order traversal always visit all the node on left branch before going to the right ( root -> left -> ... -> right), therefore, we can get the immediate right child index by skipping all the node on the left branches/subtrees of current node
    The inorder array has this information exactly. Remember when we found the root in "inorder" array we immediately know how many nodes are on the left subtree and how many are on the right subtree
    Therefore the immediate right child index is preStart + numsOnLeft + 1 (remember in preorder traversal array root is always ahead of children nodes but you don't know which one is the left child which one is the right, and this is why we need inorder array)
    numsOnLeft = root - inStart.
*/
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
    TreeNode* go (int pre, int ino, int end, vector<int>& preorder, vector<int>& inorder) {
        if (pre >= preorder.size() || ino > end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre]);
        int next;
        for (int i = ino; i <= end; i++) {
            if (inorder[i] == preorder[pre]) {
                next = i;
                break;
            }
        }
        root->left = go (pre+1, ino, next-1, preorder, inorder);
        root->right = go (pre+next-ino+1, next+1, end, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return go (0, 0, preorder.size()-1, preorder, inorder);
    }
};
//the fatest solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        return helper(0, 0, inorder.size()-1, preorder, inMap);
        
    }
    
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, map<int,int>& inMap){
        if(preStart > preorder.size()-1 || inStart > inEnd){return NULL;}
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inIndex = inMap[root->val];
        
        root->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inMap);
        root->right = helper(preStart + inIndex-inStart + 1, inIndex + 1, inEnd, preorder, inMap);
        return root;
    }
};
