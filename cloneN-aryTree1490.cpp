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
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        queue<Node*>next, copy;
        Node* ans = new Node(root->val);
        next.push(root);
        copy.push(ans);
        while (!next.empty()) {
            Node* tmp = next.front();
            Node* prev = copy.front();
            next.pop();
            copy.pop();
            for (auto& it: tmp->children) {
                next.push(it);
                Node* tmp = new Node(it->val);
                prev->children.push_back(tmp);
                copy.push(tmp);
            }
        }
        return ans;
    }
};
//the 52 ms solution
class Solution {
public:
    Node* cloneTree(Node* root) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if (root == NULL) {
            return NULL;
        }
        
        auto copy = new Node(root->val);
        for (auto& node : root->children) {
            copy->children.push_back(cloneTree(node));
        }
        
        return copy;
    }
};
