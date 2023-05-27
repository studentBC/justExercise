class Solution {
public:
    bool check (double d, vector<int>& stations, int k) {
        int used = 0;
        for (int i = 0; i < stations.size()-1; i++) {
            used+=(int)(stations[i+1]-stations[i])/d;
        }
        return used <= k;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        double lo = 0, hi = 1e8, mid;
        while (hi-lo > 1e-6) {
            mid = (lo+hi)/2;
            if (check(mid, stations, k)) hi = mid;
            else lo = mid;
        }
        return lo;
    }
};
