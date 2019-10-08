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
	void go (TreeNode* node, unordered_set<int>& number) {
		if (!node)return;
		number.insert(node->val);
		go (node->left, number);
		go (node->right, number);
		return;
	}
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
		unordered_set<int>one , two;
		go (root1, one);
		go (root2, two);
		for (int i: one) {
			if (two.find(target-i)!=two.end()) return true;
		}
		return false;
    }
};
//16 ms solution
static auto fast=[]{ios_base::sync_with_stdio(false); cin.tie(nullptr);return 0;}();

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (nullptr == root1 || nullptr == root2)   return false;
        int v1, v2;

        for (; root1; root1 = root1->left)  s1_.push(root1);
        for (; root2; root2 = root2->right)  s2_.push(root2);

        while (!s1_.empty() && !s2_.empty()) {
            v1 = s1_.top()->val;
            v2 = s2_.top()->val;
            if (v1 + v2 == target)  return true;
            if (v1 + v2 > target)   getNextT2();
            else    getNextT1();
        }

        return false;
    }

protected:
    void getNextT1() {
        if (s1_.empty())    return;
        TreeNode* t = s1_.top();
        s1_.pop();
        if (!t->right)  return;
        for (t = t->right; t; t = t->left)  s1_.push(t);
    }

    void getNextT2() {
        if (s2_.empty())    return;
        TreeNode* t = s2_.top();
        s2_.pop();
        if (!t->left)   return;
        for (t = t->left; t; t = t->right)  s2_.push(t);
    }

private:
    stack<TreeNode*> s1_;
    stack<TreeNode*> s2_;
};
