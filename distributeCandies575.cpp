class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int kind = 0, stop = candies.size() >> 1, count = 0;
        sort(candies.begin(), candies.end());
        int prev = INT_MAX;
        for (int i:candies) {
            if (i != prev) {
                kind++;
            } else {
                count++;
            }
            prev = i;
        }
        if (count < stop) {
            return (stop - count)+count;
        }
        return kind;
    }
};
//the fatest method
class Solution {
public:
    inline int distributeCandies(vector<int>& candies) {
        ios::sync_with_stdio(false);cin.tie(NULL);
        bitset<200005> bs;
        size_t numCandies = 0;
        for(const auto &candy : candies){
            if(bs.test(candy + 100000) == 0){
                numCandies++;
                bs.set(candy + 100000);
            }
        }
        return min(numCandies, candies.size()/2);
    }
};
