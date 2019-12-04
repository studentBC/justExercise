class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
 		vector<bool>ans;
		vector<vector<int>>cnt(s.size()+1, vector<int>(26,0));
        for (int i = 0; i < s.length(); ++i) {
			cnt[i+1].assign(cnt[i].begin(), cnt[i].end());
			++cnt[i+1][s[i]-'a'];
		}
		int sum = 0;
		for (int i = 0; i < queries.size(); i++) {
			sum = 0;
			for (int j = 0; j < 26; j++) {
				sum+=(cnt[queries[i][1]+1][j] - cnt[queries[i][0]][j])%2;
			}
			ans.emplace_back(sum/2 <= queries[i][2]);
		}
		return ans;
    }
};
//others concept
vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int mask = 0;
    vector<int> ps(1);
    for (char c : s)
        ps.push_back(mask ^= 1 << (c - 'a'));

    vector<bool> r;
    for (auto &q : queries) {
        int odds = __builtin_popcount(ps[q[1] + 1] ^ ps[q[0]]);
        r.push_back(q[2] >= odds / 2);
    }
    return r;
}
/*
According to the description and examples, we can deduce that the rearrange implies the input string s can be changed to any sequence to get close to a palindrome. Here close means least times of replacement of chars needed to become a palindrome after rearranging of s.

Obviously, any two same chars can be rearranged to be symmetric part of a palindrome, only the odd count of the chars we need to care. Therefore, when looping through the String s, we need to know if the count of each char in any prefix of the stirng s is odd or not by computing the corrsponding prefix sum, then the same information can be obtained for substring between any two given indices i and j by prefixSum[j] - prefixSum[i].
Sum those chars with odd number of occurrences, and we only need to replace half of them to make all in symmetric pairs.

e.g.,

If we want to make palindrome from s = "abbcccddddeeeee":
In "abbcccddddeeeee", a, b, c, d, and e occur 1, 2, 3, 4, and 5 times, respectively. Among them, a, c and e occur 1, 3, and 5 times.

We can easily rearrange 2 b's, 2c's, 4 d's and 4 e's to a palindrome: bcddeeeeddcb. Now only odd number occurrence chars a, c, and e remaining, and we can place 1 of them, say, e, to the center of the palindrome, and replace either a to c, or c to a to complete the conversion of s to a palindrome: c -> a: abcddeeeeeddcba or a -> c: bccddeeeeddccb.

In short, at least need 3 / 2 = 1 replacement: 3 odd number occurrence of chars a, c, and e divide by 2 equals to 1

Here is the brief description of my algorithm:

Compute the prefix sum by counting the number of chars in substring(0,1), substring(0, 2), ..., substring(0,n);
Use the difference of the prefix sums to get the the number of chars in substring(queries[i][0], queries[i][1]), count those do NOT in symmetric pairs, divided by 2, and compare it with queries[i][2].
*/ 
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        List<Boolean> ans = new ArrayList<>(); 
        int[][] cnt = new int[s.length() + 1][26];
        for (int i = 0; i < s.length(); ++i) {
            cnt[i + 1] = cnt[i].clone(); // copy previous sum.
            ++cnt[i + 1][s.charAt(i) - 'a'];
        }
        for (int[] q : queries) {
            int sum = 0; 
            for (int i = 0; i < 26; ++i) {
                sum += (cnt[q[1] + 1][i] - cnt[q[0]][i]) % 2;
            }
            ans.add(sum / 2 <= q[2]);
        }
        return ans;
    }

//fastest solution
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int> bitmasks{0};
        int mask = 0;
        for(auto &ch : s) {
            mask ^= (1<<(ch-'a'));
            bitmasks.push_back(mask);
        }
       
        vector<bool> results;
        for(auto &q : queries) {
            int m = bitmasks[q[0]] ^ bitmasks[q[1]+1];
            int bits = __builtin_popcount(m)/2;
            results.push_back(bits<=q[2]);
        } 
       
        return results;
    }
};
