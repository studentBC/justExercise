class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int freqA[6] = {0};
        int freqB[6] = {0};
        for (int i = 0; i < A.size(); i++) {
            freqA[A[i]-1]++;
        }
        for (int i = 0; i < B.size(); i++) {
            freqB[B[i]-1]++;
        }
        int count = 0;
        bool correct = false;int min = INT_MAX, ans = INT_MAX;
        for (int i = 0; i < 6; i++) {
            min = INT_MAX;
            if (freqA[i]+freqB[i] >= A.size()) {
                //cout << "we choose: " << i+1 << endl;
                //if (freqA[i] > freqB[i]) {
                    count = 0;
                    correct = true;
                    for (int j = 0; j < A.size(); j++) {
                        if (A[j]!=i+1) {
                            if (B[j]!=i+1) {
                                correct = false;
                                break;
                            } else {
                                count++;
                                //cout << A[j] << " , " << B[j] << "  count:  " << count << endl;
                            }
                        }
                    }
                    if (correct && count < min) min = count;
                    //cout <<"min A: " << min << endl;
                //} else {
                    count = 0;
                    correct = true;
                    for (int j = 0; j < B.size(); j++) {
                        if (B[j]!=i+1) {
                            if (A[j]!=i+1) {
                                correct = false;
                                break;
                            } else {
                                count++;
                            }
                        }
                    }
                    if (correct && count < min) min = count;
                    //cout <<"min B: " << min << endl;
                //}
                if (ans > min) ans = min;
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};

//the fatest method
class Solution 
{
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) 
    {
        int a = 0, b = 0, n = A.size();
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != A[0] and B[i] != A[0]) break;
            if (A[i] != A[0]) a++;
            if (B[i] != A[0]) b++;
            if (i == n - 1) return min(a, b);
        }
        a = 0, b = 0;
        
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != B[0] and B[i] != B[0]) break;
            if (A[i] != B[0]) a++;
            if (B[i] != B[0]) b++;
            if (i == n - 1) return min(a, b);
        }
        return -1;
    }
};
