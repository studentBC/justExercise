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
    int numComponents(ListNode* head, vector<int>& G) {
 		vector<int>loc;
		int i = 0 , count = 0, prev = INT_MAX;
		for (int j = 0; j < G.size(); j++) {
			i = 0;
			for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next) {
				if (G[j] == ptr->val) {
					loc.emplace_back (i);
					break;
				}
				i++;
			}
		}
		sort(loc.begin(), loc.end());
		for (int i = 0; i < loc.size(); i++) {
			if (prev != loc[i]-1) count++;
			prev = loc[i-1];
		}
		return count;
    }
};
//the fatest method
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if (head == NULL) {
            return 0;
        }
        
        vector<unsigned char> group(1250, 0);
        int c = G.size();
        for (int v:G) {
            group[v/8] |= 1<<(v%8);
        }
        
        while (head->next != NULL) {
            int b0 = 1<<(head->val%8);
            int b1 = 1<<(head->next->val%8);
            if ((group[head->val/8]&b0) && 
                (group[head->next->val/8]&b1)) {
                c--;
            }
            head = head->next;
        }
        
        return c;
    }
};
