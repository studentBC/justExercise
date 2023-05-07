public class Solution {
    public int BalancedStringSplit(string s) {
        int left = 0, right = 0, ans = 0;
        foreach (char c in s) {
            if (c == 'L') left++;
            else right++;
            if (left == right) {
                ans++;
                left = right = 0;
            }
        }
        return ans;
    }
}
