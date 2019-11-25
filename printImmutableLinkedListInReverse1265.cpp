/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        vector<ImmutableListNode*>nodes;
        for (ImmutableListNode* ptr = head; ptr!=NULL; ) {
            //cout << ptr->val <<" , ";
			nodes.emplace_back(ptr);
            ptr = ptr->getNext();
        }
		
        for (int i = nodes.size()-1; i > -1; i--) {
        	nodes[i]->printValue();
		}
    }
};
//the fatest solution
/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        stack<ImmutableListNode *> ST;
        ImmutableListNode* node = head;
        while(node) {
            ST.push(node);
            node = node->getNext();
        }
        while(!ST.empty()) {
            ST.top()->printValue();
            ST.pop();
        }
    }
};
