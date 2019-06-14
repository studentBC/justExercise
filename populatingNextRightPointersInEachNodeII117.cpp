/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>nodes;
        nodes.push(root);
        Node* temp;
        while (!nodes.empty()) {
            queue<Node*>Nodes;
            temp = nullptr;
            do {
                if (temp) {
                    temp->next = nodes.front();
                }
                temp = nodes.front();
                nodes.pop();
                if (temp->left) Nodes.push(temp->left);
                if (temp->right) Nodes.push(temp->right);
            } while (!nodes.empty());
            temp->next = nullptr;
            nodes = Nodes;
        }
        return root;
    }
};
//the fatest method
class Solution {
public:
    vector<vector<Node*>> bfs(Node* root){
        vector<vector<Node*>> results;
        if(root != nullptr){
            queue<Node*> m_queue;
            m_queue.push(root);
            while(!m_queue.empty()){
                int count = m_queue.size();
                vector<Node*> result;
                while(count--){
                    Node* n = m_queue.front();
                    m_queue.pop();
                    result.push_back(n);
                    if(n->left != nullptr){
                        m_queue.push(n->left);
                    }
                    if(n->right != nullptr){
                        m_queue.push(n->right);
                    }
                }
                results.push_back(result);
            }
        }
        return results;
    }
    Node* connect(Node* root) {
        vector<vector<Node*>> results = bfs(root);
        for(vector<Node*> result: results){
            for(int i = 1; i < result.size();i++){
                result[i-1]->next = result[i];
            }
        }
        return root;
    }
};
