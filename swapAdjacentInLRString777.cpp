class Solution {
public:
    
    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        int len = start.size();
        while (i < len || j < len) {
            while (start[i]=='X') i++;
            while(end[j] == 'X') j++;
            if (i == j && i == len) return true;
            if (i == len || j == len) return false;
            if (start[i]!=end[j]) return false;
            if (start[i]=='L' && i < j) return false;
            if (start[i]=='R' && i > j) return false;
            i++;j++;
        }
        return true;
    }
};


