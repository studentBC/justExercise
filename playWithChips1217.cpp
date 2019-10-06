class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        unordered_set<int>pos;
        int cost, ans = INT_MAX;
        for (int i = 0; i < chips.size(); i++) {
            if (pos.find(chips[i]) == pos.end()) {
                cost = 0;
                for (int j = 0; j < chips.size(); j++) {
                    if (chips[j] != chips[i]) {
                        if (abs(chips[j]-chips[i])%2) {
                            cost++;
                        }
                    }
                }
                pos.insert(chips[i]);
                ans = min(ans,cost);
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0;
        int even = 0;
        for(int i = 0; i < chips.size(); i++){
            if(chips[i] % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }
        return min(odd, even);
    }
};
