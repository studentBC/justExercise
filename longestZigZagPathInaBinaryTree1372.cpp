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
    vector<int> go (TreeNode* node) {
		if (!node) return {-1,-1,-1};
		vector<int>left = go (node->left), right = go (node->right);
		int ans = max (max(left[1], right[0])+1, max(left[2], right[2]));
		return {left[1]+1, right[0]+1, ans};
    }
    int longestZigZag(TreeNode* root) {
        return go (root)[2];
    }
};

Explanation
Recursive return [left, right, result], where:
left is the maximum length in direction of root.left
right is the maximum length in direction of root.right
result is the maximum length in the whole sub tree.


Complexity
Time O(N)
Space O(height)



Explanation:
When traversing binary tree if you took "left" child to reach node and now visiting "right" child, you found 1 more depth path. So we keep track of the previous direction based on boolean true (considered as right direction) and false (considered as a left direction).
When going left (node.left) if the previous direction was right you get depth+1 else you hit 2 left nodes in a row, so you start from ZERO again, same for right child direction.

    int longestZigZag(TreeNode* root) {
        return dfs(root)[2];
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) return { -1, -1, -1};
        vector<int> left = dfs(root->left), right = dfs(root->right);
        int res = max(max(left[1], right[0]) + 1, max(left[2], right[2]));
        return {left[1] + 1, right[0] + 1, res};
    }

//168 ms solution
class Solution {
public:
    int m = 0;
    void find_max(TreeNode *n, int c, int v)
    {
        if(n == NULL) return ;
        else 
        {
            if(c == 0)
            {
                m = max(m, v);
                find_max(n->left, 0, 1);
                find_max(n->right, 1, v + 1);
            }
            else 
            {
                m = max(m, v);
                find_max(n->left, 0, v + 1);
                find_max(n->right, 1, 1);
            }
        }
    }
    int longestZigZag(TreeNode* root) {
        
        find_max(root->left, 0, 1);
        find_max(root->right, 1, 1);
        
        return m;
    }
};

//the fatest solution
static int faster_streams = []() {
	std::ios::sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();
class Solution {
public:
   int maxv = INT16_MIN;
    int longestZigZag(TreeNode* root) {
        if (nullptr == root) {
            return -1;
        }
        maxv = max(maxv, 1 + std::max(
            longestZigZag_dirc(root->left, false),
            longestZigZag_dirc(root->right, true)
        ));
        return maxv;
    }
    int longestZigZag_dirc(TreeNode* root,bool b) {
        if (root == nullptr) {
            return -1;
        }
        if (b) {
            maxv = max(maxv, 1 + longestZigZag_dirc(root->right, b));
            return (1 + longestZigZag_dirc(root->left, !b));
        }
        maxv = max(maxv, 1 + longestZigZag_dirc(root->left, b));
        return (1 + longestZigZag_dirc(root->right, !b));
    }
};
