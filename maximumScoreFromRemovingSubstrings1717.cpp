class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string big, small;
        if (x > y) {
            big = "ab";
            small = "ba";
        } else {
            big = "ba";
            small = "ab";
        }
        //cout <<big <<" : " << small << endl;
        size_t pos;
        int ans = 0, b = max(x,y), m = min(x,y);
        bool found = true;
        //cout <<s.find(big) << endl;
        while (found) {
            found = false;
            while (s.find(big) != string::npos) {
                s.erase(s.find(big), 2);
                ans += b;
                found = true;
                //cout << pos <<" : " << s << endl;
            }
            while (s.find(small) != string::npos) {
                s.erase(s.find(small), 2);
                ans += m;
                found = true;
            }
        }
        return ans;
    }
};
