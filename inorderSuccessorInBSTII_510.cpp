/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node.

Note:

If the given node has no in-order successor in the tree, return null.
It's guaranteed that the values of the tree are unique.
Remember that we are using the Node type instead of TreeNode type so their string representation are different.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
	void get (Node* node, Node*& root) {
		if (!node) return;
		if (!node->parent) root = node;
		get(node->parent);
	}
	void go (Node* node, int target, int& small, Node*& ans) {
		if (!node) return;
		if (node->val > target && node->val < small) {
			small = node->val;
			ans = node;
		}
		go (node->left, target, small, ans);
		go (node->right, target, small, ans);
	}
    Node* inorderSuccessor(Node* node) {
 		Node* ans = nullptr, *root = nullptr;
		int target = node->val;
		get(node, root);
		go (root, target, INT_MIN, ans);
		return ans;
    }
};
//the fatest method
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;   
        }
        while (node->parent && node == node->parent->right) node = node->parent;
        return node->parent;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
//concept solution
class Solution {
    public Node inorderSuccessor(Node x) {
        if (x.right == null) {
            Node result = x.parent;
            while (result != null && result.val < x.val) {
                result = result.parent;
            }
            return result;
        } else {
            Node result = x.right;
            while (result.left != null) {
                result = result.left;
            }
            return result;
        }
    }
}
