/*
 * Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:

Input: s = "aabbcc", k = 3
Output: "abcabc"
Explanation: The same letters are at least distance 3 from each other.

Example 2:

Input: s = "aaabc", k = 3
Output: ""
Explanation: It is not possible to rearrange the string.

Example 3:

Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least distance 2 from each other.

wrong test case:
"a"
0
"aa"
1
"abb"
2
"abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
26
 */
class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k < 2) return s;
        string temp = s, ans="";
        sort(temp.begin(), temp.end());
        char prev = temp[0];
        vector<pair<char,int>>alpha;
        int count = 0, index;
        for (char c:temp) {
            if (c!=prev) {
                alpha.emplace_back(make_pair(prev,count));
                count = 1;
            } else {
                count++;
            }
            prev = c;
        }
        alpha.emplace_back(make_pair(prev,count));
        int most;bool found, leagel;
        for (int i = 0; i < s.size(); i++) {
            //cout << i <<" th " << endl;
            found = false;
            if (i%k == 0) {
                most = 0;
                for (int j = 0; j < alpha.size(); j++) {
                    if (i == 0) {
                        if (alpha[j].second > most) {
                            index = j;found = true;
                            most = alpha[j].second;
                            prev = alpha[j].first;
                        }
                    } else  {
                        leagel = false;
                        if (alpha[j].second >0 && alpha[j].second >= most) {
                            leagel = true;
                            for (int a = i-1; a > -1 && a > i-k; a--) {
                                if (alpha[j].first == ans[a]) {
                                    leagel = false;
                                    break;
                                }
                            }
                        }
                        if (leagel) {
                            index = j;found = true;
                            most = alpha[j].second;
                            prev = alpha[j].first;
                        }
                    }
                }
                if (found) {
                    alpha[index].second--;
                    ans.push_back(prev);
                }
            } else {
                for (int j = 0; j < alpha.size(); j++) {
                    leagel = false;
                    if (alpha[j].second >0) {
                        leagel = true;
                        for (int a = i-1;a > -1 &&  a > i-k; a--) {
                            if (alpha[j].first == ans[a]) {
                                leagel = false;
                                break;
                            }
                        }
                    }
                    if (leagel) {
                        //cout <<"found from " << i-1 <<" to " << i-k << endl;
                        index = j;found = true;
                        alpha[j].second--;break;
                    }
                }
                if (!found) {
                    return "";
                } else {
                    ans.push_back(alpha[index].first);
                }

            }
        }
        return ans;
    }
};
//8ms solution
class Solution {
public:
    string rearrangeString(string S, int k) {
        if(k<=1) return S;
        int n=S.size();
        int m[26]={0};
        for(int i=0;i<26;++i)
            m[i] = i;
        for(char c:S)
            m[c-'a'] += 100;
        sort(m, m+26); // smalle # => large #
        int idx=k-1, tmp=k-2;
        for(int i=0;i<26;++i){
            char c = m[i]%100 + 'a';
            int num = m[i]/100;
            for(int j=0;j<num;++j){
                if(idx >= n) idx=tmp--;
                S[idx] = c;
                idx += k;
            }
        }
        for(int i=1;i<n;++i)
            if(S[i] == S[i-1]) return "";
        return S;
    }
};
/*
This is a greedy problem.
Every time we want to find the best candidate: which is the character with the largest remaining count. Thus we will be having two arrays.
One count array to store the remaining count of every character. Another array to keep track of the most left position that one character can appear.
We will iterated through these two array to find the best candidate for every position. Since the array is fixed size, it will take constant time to do this.
After we find the candidate, we update two arrays.
*/
public class Solution {
    public String rearrangeString(String str, int k) {
        int length = str.length();
        int[] count = new int[26];
        int[] valid = new int[26];
        for(int i=0;i<length;i++){
            count[str.charAt(i)-'a']++;
        }
        StringBuilder sb = new StringBuilder();
        for(int index = 0;index<length;index++){
            int candidatePos = findValidMax(count, valid, index);
            if( candidatePos == -1) return "";
            count[candidatePos]--;
            valid[candidatePos] = index+k;
            sb.append((char)('a'+candidatePos));
        }
        return sb.toString();
    }

   private int findValidMax(int[] count, int[] valid, int index){
       int max = Integer.MIN_VALUE;
       int candidatePos = -1;
       for(int i=0;i<count.length;i++){
           if(count[i]>0 && count[i]>max && index>=valid[i]){
               max = count[i];
               candidatePos = i;
           }
       }
       return candidatePos;
   }
}
