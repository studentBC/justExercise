/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    void go (Node*& ptr, Node*& head, unordered_map<Node*, Node*>& visited) {
        if (!head) {
            return;
        } else if (head && visited.find(head)!=visited.end()) {
            ptr = visited[head];
            return;
        }
        ptr = new Node(head->val, nullptr, nullptr);
        visited[head] = ptr;
        go (ptr->next, head->next, visited);
        go (ptr->random, head->random, visited);
    }
    Node* copyRandomList(Node* head) {
        Node* ptr = NULL;
        go (ptr, head, visited);
        return ptr;
    }
private:
    unordered_map<Node*,Node*>visited;
};
//16ms solution

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        
        unordered_map<Node*, Node*> map;
        
        Node* curr = head;
        Node* nHead = NULL;
        while (curr != NULL) {
            Node* node = new Node(curr->val, NULL, NULL);
            
            if (nHead == NULL)
                nHead = node;
            
            map[curr] = node;
            
            curr = curr->next;
        }
        
        curr = head;
        while (curr != NULL) {
            if (curr->next != NULL)
                map[curr]->next = map[curr->next];
            else
                map[curr]->next = NULL;
            
            if (curr->random != NULL)
                map[curr]->random = map[curr->random];
            else
                map[curr]->random = NULL;
            
            curr = curr->next;
        }
        
        return nHead;
    }
};

