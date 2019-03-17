class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0, prev;
        vector<int>ans;
        for (int j = 0;j < A.size(); j++) {
            if (A[j]%2 == 0)sum+=A[j];
        }
        for (int i = 0; i < queries.size(); i++) {
            if (A[queries[i][1]] % 2 == 0) {
                prev = A[queries[i][1]];
                A[queries[i][1]]+=queries[i][0];
                if (A[queries[i][1]] % 2 == 0)
                    sum+=queries[i][0];
                else 
                    sum-=prev;
            } else {
                //cout << A[queries[i][1]] << " become ";
                A[queries[i][1]]+=queries[i][0];
                //cout << A[queries[i][1]] << endl;
                if (A[queries[i][1]] % 2 == 0)
                    sum+=A[queries[i][1]];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
