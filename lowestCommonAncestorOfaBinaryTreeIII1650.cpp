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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*>path;
        while (p) {
            path.insert(p);
            p = p->parent;
        }
        while (q) {
            if (path.find(q)!=path.end()) return q;
            q = q->parent;
        }
        return NULL;
    }
};
//the fatest solution
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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* left = p;
        Node* right = q;
        
        while (left!=right) {
            if (left!=NULL) {
                left = left->parent;
            } else  {
                left = q;
            }
            if (right!=NULL) {
                right = right->parent;
            } else {
                right = p;
            }
        }
        return left;
    }
};
