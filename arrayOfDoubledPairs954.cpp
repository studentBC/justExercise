class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int end = arr.size()/2, target, j = 0;
        map<int, int>count;
        for (int i : arr) count[i]++;
        for (auto& it: count) {
            if (it.second > 0) {
                target = it.first*2;
                if (count[target] > 0) {
                    if (it.second >= count[target]) {
                        it.second-=count[target];
                        count[target] = 0;
                    } else {
                        count[target]-=it.second;
                        it.second = 0;
                    }
                } else {
                    if (it.first%2) return false;
                    target = it.first/2;
                    
                    if (!count.count(target) ||count[target] == 0) return false;
                    if (it.second >= count[target]) {
                        it.second-=count[target];
                        count[target] = 0;
                    } else {
                        count[target]-=it.second;
                        it.second = 0;
                    }
                }
            }
            if (it.second) return false;
        }
        return true;
    }
};
