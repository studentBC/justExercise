class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int len = security.size(), count = 1, length = len-time;
        vector<int>front, back(len, 0), ans;
         front.push_back(1);
        for (int i = 1; i < len; i++) {
            if (security[i-1] >= security[i]) count++;
            else count = 1;
            front.push_back(count-1);
        }
        back[len-1] = 1;
        count = 1;
        for (int i = len-2; i > -1; i--) {
            if (security[i] <= security[i+1]) count++;
            else count = 1;
            back[i] = count-1;
        }
        for (int i = time; i < length; i++) {
            if (front[i]>= time && back[i]>= time)ans.push_back(i);
        }
        return ans;
    }
};
//the 52 ms solution
static auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int t) {
        // edge cases
        if (!t) {
            iota(begin(sec), end(sec), 0);
            return sec;
        }
        if (2 * t >= sec.size()) return {};
        // support variables
        int len = sec.size() - 2 * t;
        bool before[len], after[len];
        fill(before, before + len, false);
        fill(after, after + len, false);
        vector<int> res;
        // preparing before and after
        for (int i = 0, currL = 0, j = sec.size() - 1, currR = 0; j >= t; i++, j--) {
            if (i && sec[i - 1] < sec[i]) currL = 0;
            if (currL++ >= t) before[i - t] = true;
            if (i && sec[j + 1] < sec[j]) currR = 0;
            if (currR++ >= t) after[j -  t] = true;
        }
        // populating res
        for (int i = 0, j = t; i < len; i++, j++) {
            if (before[i] && after[i]) res.push_back(j);
        }
        return res;
    }
};
