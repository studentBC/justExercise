/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    void go (vector<Node*>& nodes, Node* head) {
        if (!head)return;
        for (Node* ptr = head; ptr!= NULL; ptr = ptr->next) {
            nodes.emplace_back(ptr);
            if (ptr->child) {
                go (nodes,ptr->child);
            }  
        }  
    }
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        vector<Node*>nodes;
        go (nodes,head);
        /*
        for (Node* ptr:nodes) {
            cout << ptr->val <<" , ";
        }*/
        int end = nodes.size()-1;
        for (int i = 0; i < end; i++) {
            nodes[i]->next = nodes[i+1];
            nodes[i+1]->prev = nodes[i];
            nodes[i]->child = NULL;
        }
        nodes[end]->next = NULL;
        nodes[end]->child = NULL;
        return nodes[0];
    }
};
//the fatest method
class Solution {
public:
Node* flattenutil(Node* head) // this function returns the last node of the list..it is called by the function flattenlist()..
{
	Node* temp = head;
	Node* prev = NULL;
        while(temp)
        {
 		Node* t = temp->next;
		if (temp->child)
		{
			Node* temp_last = flattenutil(temp->child); // temp_last returns the last node on the list pointed by temp_child.
			temp->next = temp->child;
			temp->child = NULL;
			temp->next->prev = temp;
			temp_last->next = t;
			if (t)
			{
				t->prev = temp_last;
			}
			temp = temp_last;
			prev = temp->prev;
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	} 

	return prev;
}

Node* flatten(Node* head) // this function returns the head node of the list..
{
	Node* last  = flattenutil(head);
	return head;
}
};
