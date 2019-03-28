class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<pair<int,int>>record;
        int count = 1, ans = 0, sum = 0;
        pair<int,int>node;
        for (int i = 0; i < A.size(); i++) {
            count = 1;
			//to form a monotonic increasing queue use run length encoding
            while (!record.empty() && record.top().first >= A[i]) {
                node = record.top();
				record.pop();
                count+=node.second;
                sum-=node.first*node.second;
            }
            record.push(pair<int,int>(A[i],count));
            sum+=A[i]*count;
            ans+=sum;
            ans%=1000000007;
        }
        return ans;
    }
};

