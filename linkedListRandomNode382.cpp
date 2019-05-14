/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
		srand(time(nullptr));
        for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next) {
			data.emplace_back(ptr->val);
		}
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int choose = rand()%data.size();
		return data[choose];
    }
private:
	vector<int>data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;

    Solution(ListNode* _head) {
        head = _head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int count = 0;
        int v = head->val; // water pool size = 1
        ListNode* cur = head;
        while (cur) {
            if ((rand() % ++count) < 1) {
                v = cur->val;
            }
            cur = cur->next;
        }
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
