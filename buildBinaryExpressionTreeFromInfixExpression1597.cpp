/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool compare (char c1, char c2) {
        if (c1 == '(' || c1 == ')') return false;
        return c1 == '*' || c1 == '/' || c2 == '+' || c2 == '-';
    }
    Node* expTree(string s) {
        vector<Node*>nodes;
        vector<char>op;
        Node* left, *right;
        for (char c : s) {
            if (isdigit(c)) nodes.push_back(new Node(c));
            else if (c == '(') op.push_back(c);
            else if (c == ')') {
                while (!op.empty() && op.back()!='(') {
                    right = nodes.back();
                    nodes.pop_back();
                    left = nodes.back();
                    nodes.pop_back();
                    nodes.push_back(new Node(op.back(), left, right));
                    op.pop_back();
                }
                op.pop_back();
            } else {
                while (!op.empty() &&  compare(op.back(), c) ) {
                    right = nodes.back();
                    nodes.pop_back();
                    left = nodes.back();
                    nodes.pop_back();
                    nodes.push_back(new Node(op.back(), left, right));
                    op.pop_back();
                }
                op.push_back(c);
            }
        }
        while (!op.empty()) {
            right = nodes.back();
            nodes.pop_back();
            left = nodes.back();
            nodes.pop_back();
            nodes.push_back(new Node(op.back(), left, right));
            op.pop_back();
        }
        return nodes.back();
    }
};
