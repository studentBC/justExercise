    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int count) {
        if (!root) return 0;
        count ^= 1 << (root->val - 1);
        int res = dfs(root->left, count) + dfs(root->right, count);
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }

/* 
count ^= 1 << (root.val - 1) -> Flips the root.val-1th bit, which here is used to flip between denoting even and odd occurrence.
count & (count - 1) -> Used to check that only a single bit is set - checkout LC 231 for details.
This is used here to make sure that there is only 1 odd occurence.
*/

/*148 ms solution
 * @lc app=leetcode id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 *
 * https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (65.34%)
 * Total Accepted:    7.4K
 * Total Submissions: 11.3K
 * Testcase Example:  '[2,3,1,3,1,null,1]'
 *
 * Given a binary tree where node values are digits from 1 to 9. A path in the
 * binary tree is said to be pseudo-palindromic if at least one permutation of
 * the node values in the path is a palindrome.
 *
 * Return the number of pseudo-palindromic paths going from the root node to
 * leaf nodes.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [2,3,1,3,1,null,1]
 * Output: 2
 * Explanation: The figure above represents the given binary tree. There are
 * three paths going from the root node to leaf nodes: the red path [2,3,3],
 * the green path [2,1,1], and the path [2,3,1]. Among these paths only red
 * path and green path are pseudo-palindromic paths since the red path [2,3,3]
 * can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be
 * rearranged in [1,2,1] (palindrome).
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: root = [2,1,1,1,3,null,null,null,null,null,1]
 * Output: 1
 * Explanation: The figure above represents the given binary tree. There are
 * three paths going from the root node to leaf nodes: the green path [2,1,1],
 * the path [2,1,3,1], and the path [2,1]. Among these paths only the green
 * path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1]
 * (palindrome).
 *
 *
 * Example 3:
 *
 *
 * Input: root = [9]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The given binary tree will have between 1 and 10^5 nodes.
 * Node values are digits from 1 to 9.
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  int odd = 0, res = 0;

public:
  void dfs(TreeNode *root, vector<int> &cnt) {
    if (root == nullptr)
      return;
    int v = root->val;
    cnt[v] += 1;
    odd += cnt[v] & 1 ? 1 : -1;
    dfs(root->left, cnt);
    dfs(root->right, cnt);
    if (root->left == nullptr && root->right == nullptr)
      res += odd <= 1 ? 1 : 0;
    cnt[v]--;
    odd += cnt[v] & 1 ? 1 : -1;
  }

  int pseudoPalindromicPaths(TreeNode *root) {
    vector<int> cnt(10);

    dfs(root, cnt);
    return res;
  }
};

static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
