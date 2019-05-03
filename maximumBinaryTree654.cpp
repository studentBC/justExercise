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
    int findMax (vector<int>& nums, int start, int end) {
        int big = -1, index = -1;
        for (int i = start; i < end; i++) {
            if (big < nums[i]) {
                index = i;
                big = nums[i];
            }
        }
        return index;
    }
    TreeNode* go (int start, int end, vector<int>& nums) {
        int index = findMax(nums,start,end);
        if (index == -1) return nullptr;
        TreeNode* root = new TreeNode(nums[index]);
        nums[index] = -1;
        root->left = go(start,index,nums);
        root->right = go(index+1,end,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return go (0,nums.size(), nums);
    }
};
//the 64ms method
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
		stack<TreeNode *> values;
		vector<TreeNode *> nodes(nums.size());
		int index = 0, maximum = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			TreeNode *node = nullptr;
			nodes[i] = new TreeNode(nums[i]);
			while (values.size() && nums[i] > values.top()->val) {
				node = values.top();
				values.pop();
			}
			nodes[i]->left = node;
			values.push(nodes[i]);
			if (nums[i] > maximum) {
				maximum = nums[i];
				index = i;
			}
		}
		while (values.size())
			values.pop();
		for (int i = nums.size() - 1; i >= 0; --i) {
			TreeNode *node = nullptr;
			while (values.size() && nums[i] > values.top()->val) {
				node = values.top();
				values.pop();
			}
			nodes[i]->right = node;
			values.push(nodes[i]);
		}
		return nodes[index];
	}
};
