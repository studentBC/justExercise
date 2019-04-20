//my brutal force method
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int next, fib, largest = 0, count = 0, prev, prev2;
        for (int i = 0; i < A.size(); i++) {
            for (int j = i+1; j < A.size(); j++) {
                prev2 = A[i]; prev = A[j];
                next = j+1;fib = A[i]+A[j];count = 2;
                while (next < A.size() && A[next] <= fib) {
                    if (A[next] == fib) {
                        prev2 = prev;
                        prev = fib;
                        fib = prev+prev2;
                        count++;
                    }
                    next++;
                }
                if (count > 2 && largest < count) largest = count;
            }
        }
        return largest;
    }
};
//the dp fatest method
class Solution 
{
public:
    int lenLongestFibSubseq(vector<int>& A)
    {
        unordered_set<int> S(A.begin(), A.end());
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = i+1; j < A.size(); ++j)
            {
                int a = A[i], b = A[j];
                long long l = 2;
                if ((res - 2)*b > A.back()) break;
                while (S.count(a + b))
                {
                    b = a + b;
                    a = b - a;
                    ++l;
                }
                res = max(res, l);
            }
        }
        return res > 2 ? res : 0;
    }
};
