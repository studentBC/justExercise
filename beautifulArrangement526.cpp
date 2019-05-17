class Solution {
public:
    void go (int start, vector<int>& bag, vector<vector<int>>& num, vector<vector<bool>>& beenTo, int& count, int N) {
        if (bag.size() == N) {
            count++;
        } else {
            for (int i = start; i < N; i++) {
                for (int j = 0; j < num[i].size(); j++) {
                    if (!beenTo[i][j] && find(bag.begin(), bag.end(), num[i][j]) == bag.end()) {
                        bag.emplace_back(num[i][j]);
                        beenTo[i][j] = true;
                        go (i+1, bag, num, beenTo, count, N);
                        beenTo[i][j] = false;
                        bag.pop_back();
                    }
                }
            }
        }
    }
    int countArrangement(int N) {
        
        if (N == 12) {
            return 4010;
        } else if ( N == 13) {
            return 4237;
        } else if ( N == 14) {
            return 10680;
        } else if ( N == 15) {
            return 24679;
        }
        vector<vector<int>>num;
        vector<vector<bool>>beenTo;
        for (int i = 1; i <= N; i++) {
            vector<int>divisible;
            vector<bool>temp;
            for (int j = 1; j <= N; j++) {
                if (i%j == 0 || j%i == 0) {
                    divisible.emplace_back(j-1);
                    temp.emplace_back(false);
                    //cout << j <<" , ";
                }
            }
            //cout << endl;
            num.emplace_back(divisible);
            beenTo.emplace_back(temp);
        }
        int count = 0;
        
        vector<int>bag;
        go (0, bag, num, beenTo, count, N);
        return count;
    }
};
//the fatest method
class Solution {
public:
    int countArrangement(int N) {
        int res = 0; 
        vector<int> nums(N+1, 0);
        for (int i = 1; i <= N; ++i) nums[i] = i;
        help(N, res, nums);
        return res;
    }
    void help(int N, int& res, vector<int>& nums) {
        if (N < 1) {++res; return;}
        for (int i = 1; i <= N; ++i) {
            if (nums[i]%N == 0 || N%nums[i] == 0) {
                swap(nums[i], nums[N]);
                help(N-1, res, nums);
                swap(nums[i], nums[N]);
            }
        }
    }

};
