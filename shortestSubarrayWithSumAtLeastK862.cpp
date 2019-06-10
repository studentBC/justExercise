class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<long>acc;
        long sum = 0;int length = INT_MAX, count = 1;
        for (int num:A) {
            sum+=num;
            acc.emplace_back(sum);
            if (sum >= K) {
                length = min (length, count);
            }
			if (num >= K) return 1;
            count++;
        }
        for (int i = 2; i < acc.size(); i++) {
            for (int j = 1; j < acc.size(); j++) {
                if (acc[j]-acc[i] >= K) {
                    length = min (length, j-i);
                }  
            }  
        }
        if(length == INT_MAX) return -1;
        return length;
    }
};

