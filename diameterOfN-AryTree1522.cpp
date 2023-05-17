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
    int ans = 0;
    int go (Node* n) {
        if(n->children.size() == 0) return 0;
        int m1 = -1, m2 = -1;
        for (auto& c: n->children) {
            int ch = go(c);
            if (ch > m1) {
                m2 = m1; m1 = ch;
            } else if (ch > m2) m2 = ch;
        }
        ans = max(ans, m1+m2+2);
        return m1+1;
    }
    int diameter(Node* root) {
        if (!root || root->children.size() == 0) return 0;

        go (root);
        return ans;
    }
};
