public class Solution {
    public IList<string> CommonChars(string[] words) {
        List<List<int>>count = new List<List<int>>();
        foreach (string s in words) {
            List<int> temp = new List<int>(Enumerable.Repeat(0, 26));
            for (int i = 0; i < s.Length; i++) {
                temp[s[i]-'a']++;
            }
            count.Add(temp);
        }
        int total = words.Length;
        List<string>ans = new List<string>();
        for (int i = 0; i < 26; i++) {
            int c = total+1;
            for (int j = 0; j < total; j++) {
                c = Math.Min(count[j][i], c);
            }
            for (int j = 0; j < c; j++) {
                ans.Add(((char)(i+'a')).ToString());
            }
        }
        return ans;
    }
}
