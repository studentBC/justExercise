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
	void go (TreeNode* node, vector<int>&temp) {
		if (!node)return;
		temp.push_back(node->val);
		go(node->left,temp);
		go(node->right,temp);
		return;
	}
    int getMinimumDifference(TreeNode* root) {
		vector<int>temp;
 		go(root, temp);
		sort(temp.begin(),temp.end());
		int prev = temp[0], min = INT_MAX , minus;
		for (int i = 1; i < temp.size(); i++) {
			minus = temp[i]-prev;
			if (minus < min) {
				min = minus;
			}
			prev = temp[i];
		}
		return min;
    }
};
//fatest method
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
    int preVal = -1, minDiff = INT_MAX;
    void inorder(TreeNode* root){
        if(root == nullptr)
            return;
        inorder(root->left);
        if(preVal != -1)
            minDiff = min( minDiff, abs(root->val-preVal));
        preVal = root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};

static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
