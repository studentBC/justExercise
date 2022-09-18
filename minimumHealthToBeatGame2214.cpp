class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long sum = 1;int big = 0;
        for (int i : damage) {
            big = max(i, big);
            sum+=i;
        }
        sum-=big;
        if (big > armor) return sum+(big-armor);
        else return sum;
    }
};
