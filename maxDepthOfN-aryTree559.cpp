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
    void go (Node* node, int depth, int& ans) {
        if (!node)return;
        depth++;
        if (depth > ans) ans = depth;
        for (int i = 0; i < node->children.size(); i++) {
            go (node->children[i],depth,ans);
        }
    }
    int maxDepth(Node* root) {
        int ans = 0;
        go (root,0,ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        if(root->children.size() == 0)
            return 1;

        int max_depth = 0;
        for(int i=0; i<root->children.size(); i++){
            int d = maxDepth(root->children[i]);
            max_depth = max(max_depth, d);
        }
        return max_depth + 1;
    }
};
