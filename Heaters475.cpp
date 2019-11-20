class Solution {
public:
    bool cover (vector<int> houses, vector<int> heaters, int radius) {
        for (int i = heaters.size() -1; i > -1 && houses.size(); i--) {
            while (houses.size() && houses.back() <= heaters[i]+radius && houses.back() >= heaters[i] - radius) houses.pop_back();
        }
        return houses.empty();
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort (houses.begin(), houses.end());
        sort (heaters.begin(), heaters.end());
        int left = 0, right = INT_MAX, mid, r = INT_MAX, l = 0;
        while (left <= right) {
            mid = (left+right)/2;
            if (cover(houses, heaters, mid)) {
                r = min (r, mid);
                right = mid -1;
            } else {
                l = max (l, mid);
                left = mid+1;
            }
        }
        //cout << left <<" , " << right ;
        for (int i = l; i <= r; i++) {
            if (cover(houses, heaters, i)) return i;
        }
        return left;
    }
};
//the fatest solution
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
       int ans = 0;        
       // const size_t size = heaters.size();
       // const auto last = heaters.end();
       sort(heaters.begin(), heaters.end());
        for( int house :houses){
            int minDist = numeric_limits<int>::max();
            auto it=lower_bound(begin(heaters),end(heaters),house);
            if(it!=end(heaters)) minDist= ::min(minDist,abs(*it-house));
            if(it!=begin(heaters)){
                --it;
                minDist= ::min(minDist,abs(*it-house));
            }
                              
            ans = max(ans,minDist);
        }
        /*
       for (auto n: houses) {
           int r = lower_bound(heaters.begin(), last, n) - heaters.begin();
           int right = (r == size)?maximum:heaters[r]-n;
           int left = (r > 0)?n-heaters[r-1]:maximum;
           ans = max(ans, min(right,left));
       }
       */
       return ans;
    }
};
