class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() < 1) {
            return true;
        } else {
            //increasing
            if (A[A.size()-1] > A[0]) {
                for (int i = 1; i < A.size(); i++) {
                    if (A[i] < A[i-1])return false;
                }
            } else if ( A[A.size()-1] < A[0] ){
                for (int i = 1; i < A.size(); i++) {
                    if (A[i] > A[i-1])return false;
                }
            } else {
                for (int i = 1; i < A.size(); i++) {
                    if (A[i] != A[i-1])return false;
                }
            }
            //decreasing
        }
        return true;
    }
};
//the fatest method
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        ios_base::sync_with_stdio(0);
        int l=A.size();
        bool tr=true;
        int prev=INT_MAX-1000;
        prev=-prev;
        for(int i=0;i<l;i++)
        {
            if(A[i]<prev)
            {
                tr=false;
                break;
            }
            prev=A[i];
        }
        if(tr==true)
        {
            return true;
        }
        tr=true;
        prev=INT_MAX;
        for(int i=0;i<l;i++)
        {
            if(A[i]>prev)
            {
                tr=false;
                break;
            }
            prev=A[i];
        }
        return tr;
    }
};
