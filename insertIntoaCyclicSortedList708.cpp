/*
Given a node from a cyclic linked list which is sorted in ascending order, write a function to insert a value into the list such that it remains a cyclic sorted list. The given node can be a reference to any single node in the list, and may not be necessarily the smallest value in the cyclic list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the cyclic list should remain sorted.

If the list is empty (i.e., given node is null), you should create a new single cyclic list and return the reference to that single node. Otherwise, you should return the original given node.

The following example may help you understand the problem better:

 



In the figure above, there is a cyclic sorted list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list.

 



The new node should insert between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.


wrong test case:
{"$id":"1","next":{"$id":"2","next":{"$id":"3","next":{"$ref":"1"},"val":5},"val":3},"val":1}
0
{"$id":"1","next":{"$id":"2","next":{"$id":"3","next":{"$ref":"1"},"val":5},"val":3},"val":1}
6


class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal, head);
            head->next= new Node(insertVal, head);
            head->next = head;
            return head;
        } else { 
            bool found = false;
            Node* ptr = head->next,* prev = head, * big, * small, *pres;
            int bb = INT_MIN, ss = INT_MAX;
            int count = 2;
            while (count) {
                if (insertVal >= prev->val && insertVal <= ptr->val) {
                    Node* p = new Node(insertVal);
                    prev->next = p;
                    p->next = ptr;
                    return head;
                } else { 
                    prev = ptr;
                    ptr = ptr->next;
                }
                if (ptr == head) count--;
                if (ptr->val > bb) {
                    bb = ptr->val;
                    big = ptr;
                }
                if (ptr->val < ss) {
                    ss = ptr->val;
                    small = ptr;
                    pres = prev;
                }
            }
            ptr = head->next;
            Node* p = new Node(insertVal);
            if (insertVal >= big->val) {
                p->next = big->next;
                big->next = p;
            } else if (insertVal <= small->val) {
                pres->next = p;
                p->next = small;
            }
        }
        return head;
    }
};
//the fatest method
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *prev, *n = new Node(insertVal, NULL);
        if (!head) {
            n->next = n;
            return n;
        }
        Node **p = &(head->next);
        Node **max = p, **min = p;
        int maxval = head->next->val, minval = head->next->val;
        while ((*p)->val == (*p)->next->val) {
            p = &((*p)->next);
            if (p == &(head->next)) break;
        }
        do {
            if ((*p)->val >= maxval) {
                maxval = (*p)->val;
                max = p;
            }
            if ((*p)->val < minval) {
                minval = (*p)->val;
                min = p;
            }
            p = &((*p)->next);
        } while (p != &(head->next));
        // printf("min: %d, max: %d\n", (*min)->val, (*max)->val);
        if (insertVal <= minval) {
            p = &((*max)->next);
        } else if (maxval <= insertVal) {
            p = &((*max)->next);
        } else {
            // puts("3");
            for (p = min; p != max; p = &((*p)->next)) {
                if ((*p)->val > insertVal) {
                    break;
                }
            }
        }
        n->next = (*p);
        *p = n;
        return head;
    }
};
