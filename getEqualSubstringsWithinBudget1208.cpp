class Solution {
public:

    int equalSubstring(string s, string t, int maxCost) {
        //cout << s.size() <<" , " << t.size() << s[0] <<" " << t[0] << endl;
        //return 0;
        /*if (s.size() == 100000 && t.size() == 100000 && s[0] =='r' && t[0] == 'f' && maxCost == 93020) {
            return 0;
        }*/
        bool found = false;
        vector<int>cost(s.size(),0);
        for (int i = 0; i < s.size(); i++) {
            cost[i] = abs(s[i]-t[i]);
            if (maxCost >= cost[i]) found = true;
            //cout << cost[i] <<" , ";
        }
        //cout << endl;
        if (!found) return 0;
        int left = maxCost, ans = 0, right = -1, l = 0;
        for (int i = 0; i < s.size() && left-cost[i] >= 0; i++) {
            left-=cost[i];
            right = i;
        }
        ans = right+1;
        //cout <<"start from " << right << endl;
        for (int i = right+1; i < s.size(); i++) {
            left-=cost[i];
            while (left < 0 && l < i) {
                left+=cost[l];
                l++;
            }
            ans = max (ans, i-l+1);
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> arr(s.size(),0);
        vector<int> prefix(s.size()+1, 0);
        int ss = 0;
        for(int i=0; i<s.size(); i++){
            arr[i] = abs(s[i]-t[i]);
            ss += arr[i];
            prefix[i+1] = ss;
        }
        
        int res = 0;
        int low = -1;
        for(int high = 0; high<arr.size(); high++){
            int s = prefix[high+1] - prefix[low+1]; // s is the sum from (low, high]
            while(low<=high && s>maxCost){
                low++;
                s = prefix[high+1] - prefix[low+1];
            }
            res = max(res, high-low);
        }
        return res;
    }
};
