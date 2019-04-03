class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        sort(A.begin(),A.end());
        int candidate, fit; 
        for (int i = 0; i < B.size(); i++) {
            candidate = INT_MAX;
            for (int j = 0; j < A.size(); j++) {
                if (A[j] > B[i]) {
                    if (candidate > A[j]) {
                        candidate = A[j];
                        fit = j;
                    }
                }
            }
            if (candidate != INT_MAX) {
                ans.push_back(candidate);
                A.erase(A.begin()+fit);
            } else {
                ans.push_back(-1);
            }
        }
        if (!A.empty()) {
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] == -1) {
                    ans[i] = A.back();
                    A.pop_back();
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector <pair <int, int>> B_pair;
        int N = B.size();
        for(int i = 0; i < N; i++)
            B_pair.push_back({B[i], i});
        sort(B_pair.begin(), B_pair.end());
        vector <int> ans(N, -1);
        queue <int> unused;
        int A_index = 0;
        for(int i = 0; i < N && A_index < N; i++)
        {
            int original_index = B_pair[i].second;
            while(A_index < N && A[A_index] <= B_pair[i].first)
            {
                unused.push(A[A_index]);
                A_index++;
            }
            if(A_index < N)
            {
                ans[original_index] = A[A_index];
                A_index++;
            }
        }
        for(int i = 0; i < N; i++)
        {
            if(ans[i] == -1)
            {
                ans[i] = unused.front();
                unused.pop();
            }
        }
        return ans;
    }
};
