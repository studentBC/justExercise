class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() == 0 && popped.size()!=0) {
            return false;
        } else if (pushed.size() == 0 && popped.size()==0) {
            return true;
        } else if (pushed.size() != 0 && popped.size()==0) {
            return false;
        }
        int pushidx = 1, popidx = 0;
        vector<int>temp;
        temp.push_back(pushed[0]);
        while (1) {
            while ( temp.empty() || (!temp.empty() && temp.back()!= popped[popidx] && pushidx < pushed.size())) {
                temp.push_back (pushed[pushidx]);
                pushidx++;
            }
            if (temp.back() == popped[popidx]) {
                temp.pop_back();
                popidx++;
            } else if (!temp.empty()) {
                temp.pop_back();
            }
            if (temp.empty() && popidx == popped.size()) {
                return true;
            } else if (temp.empty() && popidx != popped.size() && pushidx == pushed.size()) {
                return false;
            } else if (!temp.empty() && popidx == popped.size()) {
                return false;
            }
        }
    }
};
//the fatest method
class Solution {
    //Notes
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> mystack;
        int i=0;
        for(auto p:pushed){
            mystack.push(p); //push the elements in the stack
            //check weather this element pushed was in popped of order  
            while(!mystack.empty() && mystack.top() == popped[i]){
                mystack.pop();
                i++;
            }
        }
        
        return mystack.empty();
    }
};
