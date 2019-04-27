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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int total = 0 , run;
        ListNode* ptr = root, *prev = root;
        for (ptr = root; ptr!=NULL; ptr = ptr->next) {
            total++;
        }
        vector<ListNode*>ans;
        run = total/k;
        ptr = root;
        if (total <= k) {
            for (int i = 0; i < k; i++) {
                if (ptr) {
                    ans.emplace_back(ptr);
                    ptr = ptr->next;
                    ans[i]->next = NULL;
                } else {
                    ans.emplace_back(nullptr);
                }
            }
        } else if (total % k != 0) {
            //while (total > 0) {
                int left = total%k;
                for (int j = 0; j < left; j++) {
                    ans.emplace_back(ptr);
                    for (int i = -1; i < run; i++) {
                        prev = ptr;
                        ptr = ptr->next;
                    }
                    prev->next = NULL;
                    total-=run;
                }
                left = k-left;
                for (int j = 0; j < left; j++) {
                    ans.emplace_back(ptr);
                    for (int i = 0; i < run; i++) {
                        prev = ptr;
                        ptr = ptr->next;
                    }
                    prev->next = NULL;
                    total-=run;
                    total--;
                }
            //}
        } else {
            while (total > 0) {
                ans.emplace_back(ptr);
                for (int i = 0; i < run; i++) {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = NULL;
                total-=run;
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int length = 0;
        ListNode* node = root;
        while (node) {
            ++length;
            node = node->next;
        }
        vector<ListNode*> result;
        ListNode* prev;
        if (length < k) {
            node = root;
            while (node) {
                result.push_back(node);
                prev = node;
                node = node->next;
                prev->next = NULL;
            }
            while (length < k) {
                result.push_back(NULL);
                ++length;
            }
        } else {
            int group = k;
            k = length / group;
            int r = length % group;
            node = root;
            while (node) {
                int count = k;
                if (r > 0) ++count, --r;
                result.push_back(node);
                while (count > 0) {
                    prev = node;
                    node = node->next;
                    --count;
                }
                prev->next = NULL;
            }
        }
        
        return result;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
