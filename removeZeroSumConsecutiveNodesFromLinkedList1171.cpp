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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* ptr ,* prev;
        vector<int>num;
        for (ptr = head; ptr != NULL; ptr= ptr->next) {
            num.emplace_back(ptr->val);
        }
        bool found = true;
        int sum = 0;
        while (found && num.size()) {
            found = false;
            for (int i = 0; i < num.size(); i++) {
                sum = 0;
                for (int j = i; j < num.size(); j++) {
                    sum+=num[j];
                    if (sum == 0) {
                        found = true;
                        //cout << i <<" , "<< j << endl;
                        num.erase(num.begin()+i, num.begin()+j+1);
                        break;
                    }
                }
                if (found)break;
            }
        }
        if (num.size() == 0) return nullptr;
        prev = ptr = head;
        for (int i = 0; i < num.size(); i++,ptr = ptr->next) {
            ptr->val = num[i];
            //cout << num[i] <<" , ";
            prev = ptr;
        }
        prev = prev->next = nullptr;
        return head;
    }
};
//the 12 ms solution
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* root =new ListNode(0);
        root->next=head;
        
        unordered_map<int,ListNode*>um;
        um[0]=root;
        
        int ac=0;
        
        while(head!=NULL){
            ac+=head->val;
            
            //found value
            if(um.find(ac)!=um.end()){
                ListNode* prev= um[ac];
                ListNode* start= prev;
                
                //delete bad references
                int aux = ac;
                while(prev!=head){
                    prev=prev->next;
                    aux+=prev->val;
                    if(prev!=head)um.erase(aux);
                }
                
                
                start->next = head->next;
            }else{
                um[ac]= head;
            }
            
            head=head->next;
        }
        
        return root->next;
    }
};
