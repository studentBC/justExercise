/*
Intuition
Let's think about how a character can be found as a unique character.

Think about string "XAXAXXAX" and focus on making the second "A" a unique character.
We can take "XA(XAXX)AX" and between "()" is our substring.
We can see here, to make the second "A" counted as a uniq character, we need to:

insert "(" somewhere between the first and second A
insert ")" somewhere between the second and third A
For step 1 we have "A(XA" and "AX(A", 2 possibility.
For step 2 we have "A)XXA", "AX)XA" and "AXX)A", 3 possibilities.

So there are in total 2 * 3 = 6 ways to make the second A a unique character in a substring.
In other words, there are only 6 substring, in which this A contribute 1 point as unique string.

Instead of counting all unique characters and struggling with all possible substrings,
we can count for every char in S, how many ways to be found as a unique char.
We count and sum, and it will be out answer.


Explanation
index[26][2] record last two occurrence index for every upper characters.
Initialise all values in index to -1.
Loop on string S, for every character c, update its last two occurrence index to index[c].
Count when loop. For example, if "A" appears twice at index 3, 6, 9 seperately, we need to count:
For the first "A": (6-3) * (3-(-1))"
For the second "A": (9-6) * (6-3)"
For the third "A": (N-9) * (9-6)"

Complexity
One pass, time complexity O(N).
Space complexity O(1).
*/
class Solution {
public:
    int uniqueLetterString(string s) {
        int index[26][2], ans = 0, len = s.size(), mod = 1e9+7, c;
        memset(index, -1, sizeof(int)*52);
        for (int i = 0; i < len; i++) {
            c = s[i]-'A';
            ans = (ans+(i - index[c][1])*(index[c][1]-index[c][0])%mod)%mod;
            index[c][0] = index[c][1];
            index[c][1] = i;
        }
        for (int i = 0; i < 26; i++) {
            ans = (ans+(len - index[i][1])*(index[i][1]-index[i][0])%mod)%mod;
        }
        return ans;
    }
};
