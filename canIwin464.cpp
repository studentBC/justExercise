class Solution {
public:
    bool go (map<int,bool>& dp, vector<bool>& used, int target) {
        //cout << target << endl;
        if (target <= 0) return false;
        int key = transform(used);
        if (dp.find(key) == dp.end()) {
            for (int i = 1; i < used.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    if (!go(dp, used, target-i)) { // other player lose
                        dp.insert(pair<int,bool>(key, true));
                        used[i] = false;
                        return true;
                    }
                    used[i] = false;
                }
            }
            dp.insert(pair<int,bool>(key, false));
        }
        return dp[key];
    }
    int transform (vector<bool> used) {
        int num = 0;
        for (int i = 0; i < used.size(); i++) {
            num <<=1;
            if (used[i]) num = num | 1;
        }
        return num;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        vector<bool>used(maxChoosableInteger+1, false);
        int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        map<int,bool>dp;
        return go (dp, used, desiredTotal);
    }
};
//the fatest method
class Solution {
    int n;
    vector<char>memory;
    bool recursive(int state, int rsum)
    {
        if(rsum<=0)return 0;
        if(memory[state]<2)return memory[state];
        int pick=n;
        for(int i=1;i<=state;i<<=1,--pick)
        {
            if(state&i)
            {
//                fprintf(stdout, "state=%d  i=%d  %d\n",state, i,state&i);
                if (recursive(state^i,rsum-pick)==0)
                {
                    memory[state]=1;
//                    fprintf(stdout, "%d %d %d\n",state,rsum,memory[state]);
                    return 1;
                }
            }
        }
        memory[state]=0;
//        fprintf(stdout, "%d %d %d\n",state,rsum,memory[state]);
        return 0;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        n=maxChoosableInteger;
        if(n<0)return 0;
        if(desiredTotal<=0)return 1;
        if((n*(n+1)/2)<desiredTotal)return 0;
        memory.resize(1<<n,2);
        return recursive((1<<n)-1,desiredTotal);
    }
};
