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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        return go(postorder.size()-1, 0, inorder.size()-1, postorder, inMap);
    }
    
    TreeNode* go(int pos, int ins, int inEnd, vector<int>& postorder, map<int,int>& inMap) {
        if(pos < 0 || ins > inEnd){return NULL;}
        
        TreeNode* root = new TreeNode(postorder[pos]);
        int inIndex = inMap[root->val];
        
        root->left = go(pos - (inEnd -inIndex +1), ins, inIndex - 1, postorder, inMap);
        root->right = go(pos - 1 , inIndex + 1, inEnd, postorder, inMap);
        return root;
    }
};
//the fatest solution
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
private:
    TreeNode* helper(vector<int>& postorder, int lPost, int rPost, 
                 vector<int>& inorder, int lIn, int rIn,
                 unordered_map<int,int>& mp)
    {
        if(lPost > rPost || lIn > rIn)
            return nullptr;
        int i = mp[postorder[rPost]];
        TreeNode* cur = new TreeNode(postorder[rPost]);
        cur->left = helper(postorder,lPost, lPost+(i-lIn)-1 ,inorder,lIn,i-1,mp);
        cur->right = helper(postorder,lPost+(i-lIn),rPost-1,inorder,i+1,rIn,mp);
        return cur;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;
        
        return helper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};


