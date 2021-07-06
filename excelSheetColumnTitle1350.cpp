/*
Description
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

1 -> A
2 -> B
3 -> C
 ...
26 -> Z
27 -> AA
28 -> AB

wrong test case: 1352, 676 
*/ 
class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a string
     */
    string convertToTitle(int n) {
        int temp, count = 0, tmp;
        string ans;

        do {
            count++;
        } while (pow(26, count) < n);

        //cout << count;
        for (int i = count-1; i > 0; i--) {
            temp = pow(26, i);
            tmp = n/temp;
            if (tmp*temp == n) tmp--;
            //cout <<" result " << tmp << endl;
            ans+=(tmp-1+'A');
            n = n-(temp*tmp);
        }
        ans+=(n-1+'A');
        return ans;
    }
};
