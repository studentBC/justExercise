/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	void go (TreeNode*& node, vector<int>& ans) {
		if (!node) return;
		if (node->left && node->right == NULL) {
			ans.push_Back(node->left);
		} else if (node->right && node->left == NULL) {
			ans.push_Back(node->right);
		}
		go (node->left, ans);
		go (node->right, ans);
		return;
	}
    vector<int> getLonelyNodes(TreeNode* root) {
 		vector<int>ans;
		go (root, ans);
		return ans;
    }
};
//8 ms solution
// Solution by kretash :)
#pragma clang optimize on
static int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution 
{
    void traverse( TreeNode* node, vector<int>& results )
    {
        if( node == nullptr )
            return;
        
        if( node->left == nullptr || node->right == nullptr )
        {
            if( node->left != nullptr )
                results.push_back( node->left->val );
            else if( node->right != nullptr )
                results.push_back( node->right->val );
        }
        
        traverse( node->left, results );
        traverse( node->right, results );
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) 
    {
        vector<int> r = {};
        traverse( root, r );
        return r;
    }
};
