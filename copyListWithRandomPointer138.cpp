/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>graph;
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(-1);
        for (Node*ptr = head, *pt = ans; ptr!=NULL; ptr = ptr->next) {
            pt->next = new Node(ptr->val);
            //cout << pt->val <<", ";
            graph[ptr] = pt->next;
            pt = pt->next;
        }
        for (Node*ptr = head, *pt = ans->next; ptr!=NULL; ptr = ptr->next) {
            if (ptr->random == NULL) {
                pt->random = nullptr;
            } else pt->random = graph[ptr->random];
            pt = pt->next;
        }
        return ans->next;
    }
};
