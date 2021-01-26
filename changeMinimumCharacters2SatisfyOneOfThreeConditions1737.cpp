/*
Condition 1 and condition 2 are symmetrical, so generally we have 2 operations: make a below b and make a and b only one distince letter.
Operation 1 => make a below b:
We don't need to care how we make it, but there is definately a character, which separates the string a and string b
We can try this boundaray chararacter from b to z, and see how many steps to make string a below it, how many steps to make string b above or equal it. And just return the smallest steps among all boundary characters.
Operation 2 => make a and b only one distince letter:
We just need to count the most frequent character of string(a + b)
The operation we need to take is: a.length() + b.length() - count
*/
class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int>ac(26, 0), bc(26, 0);
        int al = a.size(), bl = b.size(), ans = al+bl;
        for (char c : a) {
            ac[c - 'a']++;
        }
        for (char c : b) {
            bc[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            ans = min(ans, al + bl - ac[i] - bc[i]);
            if (i) {
                ac[i] += ac[i - 1];
                bc[i] += bc[i - 1];
            }
            if (i < 25) {
                ans = min(ans, al - ac[i] + bc[i]);
                ans = min(ans, ac[i] + bl - bc[i]);
            }
        }
        return ans;
    }
};
