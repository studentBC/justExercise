/*
Basic

You need to know the difference between subarray and subsequence.
Subarray need to be consecutive。
Subsequence don't have to be consecutive.
*/
class Solution {
public:
    bool isPalindrome(string str)
    {
        // Start from leftmost and rightmost corners of str
        int l = 0;
        int h = str.size() - 1;

        // Keep comparing characters while they are same
        while (h > l)
        {
            if (str[l++] != str[h--])
            {
                //printf("%s is Not Palindrome", str);
                return false;
            }
        }
        return true;
        //printf("%s is palindrome", str);
    }
    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0;
        else if (isPalindrome(s)) return 1;
        return 2;
    }
};
