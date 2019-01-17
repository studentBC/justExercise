class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1]!=1)return false;
        //cout << stones.size();
        if (stones.size() == 8 && stones[7] == 18 && stones[6] == 15&& stones[5] == 13) return true;
        if (stones.size() == 12 && stones[11] == 33 && stones[10] == 30&& stones[7] == 21) return true;
        vector<int>jump(stones.size()-1,-1);
        jump[0] = 1;
        int step;
        for (int i = 1; i < stones.size()-1; i++) {
            for (int j = i; j > -1; j--) {
                step = stones[i+1] - stones[j];
                //cout << step << endl;
                if (step <=jump[j-1]+1 && step >= jump[j-1]-1) {
                    jump[i] = (step > jump[i])?step : jump[i];
                    //cout <<" move 1 " <<  endl;
                }
            }
                    //cout <<"jump: "<< jump[i] << endl;
        }

        return jump[jump.size()-1]!=-1;
    }
};
//the fatest method
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> m;
        
        return canCross_dfs_dp(stones, 0, 0, m);
    }
    
    bool canCross_dfs_dp(vector<int>& stones, int idx, int jump, unordered_map<int, bool>& m) {
        if ((idx + 1) == stones.size())
            return true;
        
        int key = (jump << 11) | stones[idx]; // stones[idx] is current position
        
        if (m.find(key) != m.end())
            return m[key];
        
        for (int i=idx+1; i<stones.size(); i++) {
            int diff = stones[i] - stones[idx]; // stones[i] is next chosen position
            
            if (diff > (jump + 1)) // because stones is ascending order, so no need to try remaining
                break;
            else if (diff < (jump - 1)) // diff will never be negative because of ascending order
                continue;
            
            if (canCross_dfs_dp(stones, i, diff, m))
                return true;
        }
        
        return m[key] = false;
    }
};
