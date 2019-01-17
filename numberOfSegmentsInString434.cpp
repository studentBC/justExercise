class Solution {
public:
    int countSegments(string s) {
        if (s.size() == 0) return 0;
        int count = 1 , start = s.size();
        char prev = '$';bool enter = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i]!=' ') {
                start = i;
                enter = false;
                break;
            }
        }
        if (enter) return 0;
        for (int i = start; i < s.size(); i++) {
            if (s[i] == ' ' && s[i]!=prev) {
                count++;
            } 
            prev = s[i];
        }
        if (s[s.size()-1] == ' ')count--;
        return count;
    }
};

