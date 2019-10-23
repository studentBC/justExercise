/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    void go (Node*& ptr, Node* node, unordered_map<Node*, Node*>& visited) {
        if (!node) {
            return;
        } else if (visited.find(node) != visited.end()) {
            ptr = visited[node];
            return;
        }
        vector<Node*>nodes;
        ptr = new Node(node->val, nodes);
        visited[node] = ptr;
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* tmp = NULL;
            ptr->neighbors.emplace_back(tmp);
            go (ptr->neighbors[i], node->neighbors[i], visited);
        }  
    }
    Node* cloneGraph(Node* node) {
        Node* head;
        unordered_map<Node*, Node*>visited;
        go (head, node, visited);
        return head;
    }
};
