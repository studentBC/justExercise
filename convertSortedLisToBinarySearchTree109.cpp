/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* go (int start, int end, vector<int>& value) {
        if (start > end || start >= value.size() || end < 0) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(value[mid]);
        root->left = go (start, mid-1, value);
        root->right = go (mid+1, end, value);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>value;
        for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next) {
            value.emplace_back(ptr->val);
        }
        return go (0, value.size()-1, value);
    }
};
//the fatest solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);
        
        auto slow = head;
        auto fast = head;
        auto pre = slow;
        
        while (fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        
        auto root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
