/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    unordered_set<Node*>n;
    void go (Node* node) {
        if (!node || !n.count(node)) return;
        n.erase(node);
        for (auto& nn : node->children) {
            go (nn);
        }
        return;
    }
    Node* findRoot(vector<Node*> tree) {
        for (Node* t: tree) n.insert(t);
        for (Node* t: tree) {
            for (auto& nn : t->children) go (nn);
        }
        Node* ans = NULL;
        for (auto& it: n) {
            ans = it;
        }
        return ans;
    }
};
