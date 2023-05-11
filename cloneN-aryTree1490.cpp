/*
Given a root of an N-ary tree, return a deep copy (clone) of the tree.

Each node in the n-ary tree contains a val (int) and a list (List[Node]) of its children.

class Node {
    public int val;
    public List<Node> children;
}
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
*/

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
    Node* ans;
    void go (Node*& n, Node*& c) {
        if (!n) return;
        c->val = n->val;
        for (auto& it: n->children) {
            Node* child = new Node(it->val);;
            c->children.push_back(child);
            go (it, child);
        }
    }
    Node* cloneTree(Node* root) {
        if (!root) return NULL;
        ans = new Node(-1);
        go (root, ans);
        return ans;
    }
};


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
//46 ms solution
class Solution {
public:
    Node* cloneTree(Node* root) {
        if (root == NULL)
            return NULL;

        queue<pair<Node *, Node *>> q;
        Node* clonedRoot = new Node(root->val);

        q.push(make_pair(root, clonedRoot));

        while(!q.empty()) {
            Node * node = q.front().first;
            Node * clondedNode = q.front().second;

            q.pop();

            for (Node * child : node->children) {
                Node * clonedChild = new Node(child->val);
                clondedNode->children.push_back(clonedChild);

                q.push(make_pair(child, clonedChild));
            }
        }

        return clonedRoot;
    }
};
