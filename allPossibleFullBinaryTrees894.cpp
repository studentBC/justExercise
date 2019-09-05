/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
basic concept

I recursively found the possible children of each node at each level. At every level I subtracted 1 from N since this node counts as a node. (N is given as 1 to 50) If N==1 I returned a node with no children. for every i where i is the number of left children I called allPossibleFBT(i) and allPossibleFBT(N-i) for the remaining children on the opposite side. Then I iterate through all possible combinations of children setting the current node's left and right children, and add it to the result list.
*/
vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*>ans;
        if (N%2 == 0) return ans;
        if (N == 1) {
            TreeNode* temp = new TreeNode(0);
            ans.emplace_back(temp);
            return ans;
        }
        N--;
        for (int i = 1; i < N; i+=2) {
            vector<TreeNode*>left = allPossibleFBT(i);
            vector<TreeNode*>right = allPossibleFBT(N-i);
            for (TreeNode* tl : left) {
                for (TreeNode* tr : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = tl;
                    root->right = tr;
                    ans.emplace_back(root);
                }
            }
        }
        return ans;
    }
//the fatest solution
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0)
        {
            return {};
        }
        vector<vector<TreeNode*>> v(N + 1);
        v[1] = { new TreeNode(0) };
        for(int n = 3; n<=N; n+=2)
        {
            for(int l = 1; l<n; l+=2)
            {
                int r = n-1-l;
                for(auto* lt: v[l])
                {
                    for(auto* rt: v[r])
                    {
                        auto* t = new TreeNode(0);
                        t->left = lt;
                        t->right = rt;
                        v[n].push_back(t);
                    }
                }
            }
        }
        return v[N];
    }
};
