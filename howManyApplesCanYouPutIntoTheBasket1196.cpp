class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0, weight = 5000, i = 0;
        while (i < arr.size() && weight-arr[i] >= 0) {
            weight-=arr[i];
            i++;
            ans++;
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        for (int i = 0, s = 5000; i < arr.size(); ++i) {
            s -= arr[i];
            if (s < 0) {
                return i;
            }
        }
        
        return arr.size();
    }
};
