class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) return 0;
        int size = A.size();
        int max = INT_MIN, sum = 0, count = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum = 0;
            count = i;
            for (int j = 0; j < A.size(); ++j) {
                if (count>= size) {
                    sum+=((count-size)*A[j]) ;
                } else {
                    sum+=(count*A[j]);
                }
                count++;
            }
            if (max < sum) max = sum;
        }
        return max;
    }
};
//the fatest method
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        int maxCount;
        int preCount = 0;
        int total = 0;
        for(int i=0; i<n; i++){
            total += A[i];
            preCount += i*A[i];
        }
        maxCount = preCount;
        
        int curCount;
        for(int i=1; i<n; i++){
            curCount = preCount + total - n*A[n-i];
            maxCount = max(maxCount, curCount);
            preCount = curCount;
            curCount = 0;
        }
            
        return maxCount;
    }
};
