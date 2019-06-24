class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.compare(b) == 0) return -1;
        return max (b.size(), a.size());
    }
};
//the fatest method
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a==b?-1:max(a.size(),b.size());
    }
};
