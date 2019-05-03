class Solution {
public:
    bool check (int start, int end, vector<int>& leagle) {
        bool ok = false;
        for (int i = start; i <= end; i++) {
            if (leagle[i] == 2) {
                return false;
            } else if (leagle[i] == 1) {
                ok = true;
            }
        }
        return ok;
    }
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<pair<int,int>>roll;
        int count = 0 , start;
        bool touch = false, first = true;
        A.emplace_back(R+1);
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < L) {
                if (first) {
                    start = i;
                    first = false;
                }
            } else if (A[i] > R) {
                if (touch)roll.emplace_back(pair<int,int>(start,i-1));
                touch = false;
                first = true;
            } else {
                if (first) {
                    start = i;
                    first = false;
                }
                touch = true;
            }
        }
		vector<int>leagle(A.size(),1);
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < L) {
                leagle[i] = 0;
            } else if (A[i] > R) {
                leagle[i] = 2;
            }
        }
        for (auto it:roll) {
            for (int i = it.first; i<= it.second; i++) {
                for (int j = i; j <= it.second; j++) {
                    if (check(i,j,leagle)) count++;
                }
            }
        }
        return count;
    }
};
//the fatest method
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0, s=-1, l=-1;
        
        for(int i=0; i<A.size(); i++){
            if(A[i]>R){s=i; l=i; continue;}
            if(A[i]>=L)l=i;
            ans+=(l-s);
        }
        return ans;
    }
};
