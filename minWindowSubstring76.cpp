class Solution {
public:
    bool contain (int start, int end, string s, string t) {
        bool found;
        for (int i = 0; i < t.size(); i++) {
            found = false;
            for (int j = start; j <= end; j++) {
                if (s[j] == t[i]) {
                    s[j] = '$';
                    found = true;
                    break;
                }
            }
            if (!found)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int length , ans = INT_MAX , start=0 , end=-1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = t.size()-1; j < s.size(); j++) {
                if (contain(i,j,s,t)) {
                    length = j-i+1;
                    if (length < ans) {
                        ans = length;
                        start = i, end = j;
                    }
                }
            }
        }
        string answer = "";
        for (int i = start; i <= end ;i++) {
            answer+=s[i];
        }
        return answer;
    }
};
//the fatest method
class Solution {
public:
    string minWindow(string s, string t) {
        int count = t.length(); 
        vector<int> map(256, 0); // ascii
        for(char tt: t)
            map[tt]++;
        
        int b = 0; // begin
        int e = 0; // end
        int beginIdx = 0; // begin index of the window
        int length = INT_MAX; // length of the window
        
        char c;
        while(e < s.length()) {
            c = s[e];
            e++;                     // move e forward 
            map[c]--;                // 
            if(map[c] >= 0) count--; // minus means the character is not in string t
            while(count == 0) {      // when all characters are found in S
                if(e - b < length) { // minimum window size update
                    beginIdx = b;
                    length = e - b;
                }
                c = s[b];
                map[c]++;               // by moving begin, we recover map[c] for previouse begin
                if(map[c] > 0) count++; // map[c] must be larger than 0
                b++;                    // move b forward.
            }
        }
        if(INT_MAX == length) return "";
        else return s.substr(beginIdx, length); // begin, length
    }

};

