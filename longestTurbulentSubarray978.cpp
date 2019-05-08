class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size() < 2) return 1;
        vector<int>sign(A.size()-1,0);
		bool found = false;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) {
                sign[i-1] = 1;
				found = true;
            } else if (A[i] == A[i-1]) {
                sign[i-1] = -1;
            } else {
				found = true;
			}
        }
		if (!found) return 1;
        int count = 1, ans = 0;
        for (int i = 0; i < sign.size(); i++) {
            /*if (sign[i]) {
                cout <<" true , ";
            } else {
                cout <<" false , ";
            }*/
            count = 1;
            for (int j = i+1; j < sign.size(); j++) {
                if (sign[j] == sign[j-1] || sign[j] == -1 || sign[j-1] == -1) {
                    break;
                } else {
                    count++;
                }
            }
            ans = max(count,ans);
        }
        return ans+1;
    }
};
//the fatest method
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
        if(!A.size()) return 0;
        bool greater = false;
        int currentSize = 1;
        int longestSize = 0;
        for(int i = 0; i < A.size()-1; i++)
        {
            if(greater && A[i] > A[i + 1])
            {
                currentSize++;
            }
            else if(!greater && A[i] < A[i + 1])
            {
                currentSize++;
            }
            else
            {
                greater = A[i] > A[i + 1];
                if(currentSize > longestSize)
                {
                    longestSize = currentSize;
                }
                currentSize = (A[i] == A[i+1]) ? 1 : 2;
            }
            greater = !greater;
        }
        if(currentSize > longestSize)
        {
            longestSize = currentSize;
        }
        return longestSize;
    }
};
