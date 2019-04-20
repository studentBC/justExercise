/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void go (Node* node, vector<int>& ans) {
        if (!node)return;
        for (int i = 0; i < node->children.size(); i++) {
            go (node->children[i],ans);
        }
        ans.emplace_back (node->val);
        return;
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        go (root,ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> postorder;
        recursivedfs(root, postorder);
        return postorder;
    }
    
    void recursivedfs(Node* root, vector<int>& postorder) {
        if (!root) return;
        for (int i = 0; i < (root -> children).size(); i++) {
            recursivedfs((root -> children)[i], postorder);
        }
        postorder.push_back(root -> val);
    }
};
