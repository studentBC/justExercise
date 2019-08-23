//wrong test case
//[0,0,1,1,1,0,0]
//0
//[0,0,0,0]
//0
class Solution {
public:
int longestOnes(vector<int>& A, int K) {
        int left = 0, right = 0, ans = 0, count = K;
        if (!K) {
            count = 0;
            for (int i = 0; i < A.size(); i++) {
                if (A[i]) {
                    count++;
                    ans = max(ans, count);
                } else {
                    count = 0;
                }
            }
            return ans;
        }
        if (!A[left]) {
            if (count) {
                count--;
                for (int i = 1; i < A.size(); i++) {
                    if (A[i]) {
                        continue;
                    } else {
                        right = i-1;
                        break;
                    }
                }
                ans = max(ans, right-left+1);
            } else {
                right = left;
            }
        }
        
        while (right+1 < A.size()) {
            right++;
            if (!A[right]) {
                if (count) {
                    count--;
                } else {
                    for (int i = left; i <= right; i++) {
                        if (!A[i]) {
                            left = i+1;
                            break;
                        }
                    }
                }
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
//the fatest method
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0; 
}();

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0;
        int count = K;
        int first = 0;
        
        for(int i=0;i<A.size();i++){
            if(A[i]==0) count--; 
            if(count>=0){
                if(i-first+1>res) res = i-first+1;  
            }else{
                while(A[first]) first++;
                first++;
                count++;
            }
        }
        return res;
    }
};
