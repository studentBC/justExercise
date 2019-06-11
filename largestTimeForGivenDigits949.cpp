class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        int hour, min, mh = -1,mm = -1;
        do {
            hour = A[0]*10+A[1];
            min = A[2]*10+A[3];
            if (hour < 24 && min < 60) {
                if (hour > mh) {
                    mh = hour;
                    mm = min;
                } else if (hour == mh && min > mm) {
                    mm = min;
                }
            }  
        } while (next_permutation(A.begin(), A.end()));
        string ans = "";
        if (mh > -1 && mm > -1) {
            if (mh < 10) ans+="0";
            ans+=to_string(mh);
            if (mm < 10) {
                ans+=":0";
            } else {
                ans+=":";
            }
            ans+=to_string(mm);
            return ans;
        } else {
            return "";
        }
    }
};
//the fatest method
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        
        sort(A.begin(),A.end(),greater<int>());
        do if(((A[0]<2)||(A[0]==2)&&A[1]<4)&&A[2]<6) 
            return to_string(A[0])+to_string(A[1])+":"+to_string(A[2])+to_string(A[3]);
        while(prev_permutation(A.begin(),A.end()));
        return "";
    }
};
