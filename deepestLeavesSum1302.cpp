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
	void go (TreeNode* node, int depth, unordered_map<int,vector<int>>& leaves, int& deepest) {
		if (!node) return;
		if (!node->left && !node->right) leaves[depth].push_back(node->val);
		deepest = max(depth, deepest);
		go (node->left, depth+1, leaves, deepest);
		go (node->right, depth+1, leaves, deepest);
		return;
	}
    int deepestLeavesSum(TreeNode* root) {
 		unordered_map<int,vector<int>>leaves;
		int deepest = 0, sum = 0;
		go (root, 0, leaves, deepest);
		for (int i: leaves[deepest]) sum+=i;
		return sum;
    }
};
//the fatest solution
// solution by luisvasquez
// DFS, complexity O(n)

typedef long long Long;
typedef vector<int> vInt;
typedef vector<vInt> vvInt;
typedef vector<vvInt> vvvInt;
typedef vector<string> vStr;
typedef pair<int, int> Pair;
typedef vector<Pair> vPair;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define PB push_back

class Solution {
    vInt h;
   public:
    int deepestLeavesSum(TreeNode* root) {
        h.clear();
        dfs(root, 0);
        return h.back();
    }

    void dfs(TreeNode* cur, int d) {
        if (cur == nullptr) return;
        if (SZ(h) == d) h.PB(0);
        h[d] += cur->val;
        dfs(cur->left, d + 1);
        dfs(cur->right, d + 1);
    }
};
