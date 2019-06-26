class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 0;
        int unit = 0;
        for (int c:S) {
            unit+=widths[c-'a'];
            if (unit > 100) {
                line++;
                unit = widths[c-'a'];
            } else if (unit == 100) {
                line++;
                unit = 0;
            }
        }
        return {line+1,unit};
    }
};
//the fatest method
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int current = 0;
        int line = 0;
        for(auto c: S)
        {
            int leng = widths[c-'a'];
            if(leng+current>100)
            {
                ++line;
                current = leng;
            }
            else
                current+=leng;
        }
        return vector<int>{line+1,current};
    }
};
