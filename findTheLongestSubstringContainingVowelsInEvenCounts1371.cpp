Explanation
cur records the count of "aeiou"
cur & 1 = the records of a % 2
cur & 2 = the records of e % 2
cur & 4 = the records of i % 2
cur & 8 = the records of o % 2
cur & 16 = the records of u % 2
seen note the index of first occurrence of cur

Note that we don't really need the exact count number,
we only need to know if it's odd or even.

If it's one of aeiou,
'aeiou'.find(c) can find the index of vowel,
cur ^= 1 << 'aeiou'.find(c) will toggle the count of vowel.

But for no vowel characters,
'aeiou'.find(c) will return -1,
that's reason that we do 1 << ('aeiou'.find(c) + 1) >> 1.

Hope this explain enough.

Complexity
Time O(N), Space O(1)

Let me try to explain a bit more. Is the count of "aeiou" matters? No, indeed. Only the mod of count will contribute to the result. Consider at index i, we have below counting mods where '+' means even and '-' means odd.

a e i o u
+ - + - +
Then what we should do is just find another same mods pattern "+-+-+" with index j (j < i), then the sequence between (j, i] is guaranteed to have all vowels' counting even (while other patterns are definitely not qualified). To make the sequence longest, we should find the smallest j and that's why Map::putIfAbsent is used.

cur ^= 1 << ("aeiou".indexOf(s.charAt(i)) + 1 ) >> 1;
This concise code is just inversing a certain bit of cur:

                                       a       e       i       o       u       other
"aeiou".indexOf(s.charAt(i)) + 1       1       2       3       4       5       0
1 << tmp                               2       4       8      16      32       1
(1 << tmp) >> 1                        1       2       4       8      16       0
So cur ^= something should be cur ^= 1, cur ^= 2, cur ^= 4, and so on.


We can use 5 bits to represent the parity of the number of occurrences of vowels. For example, we can use 0/1 for even/odd numbers, then if we have 4a, 3e, 2i, 1o, 0u, the representation would be 01010. As we scan through the array, we can update the representation in O(1) time by using the XOR operation, and then store the index where every different representation first appeared. When we encounter a representation, say 01010 again at index j, we can look back on the index i where 01010 first appeared, and we know that the substring from i to j must be a valid string, and it is the longest valid substring that ends at j.




    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m{{0, -1}};
        int res = 0, n = s.length(), cur = 0;
        for (int i = 0; i < n; i++) {
            cur ^= 1 << string("aeiou").find(s[i]) + 1 >> 1;
            if (!m.count(cur)) m[cur] = i;
            res = max(res, i - m[cur]);
        }
        return res;
    }

//the 20 ms solution
class Solution {
public:
    int findTheLongestSubstring(string s) {
        constexpr int kCharCount = 0x100;
        array<int, kCharCount> symbols{};
        symbols['a'] = 1;
        symbols['e'] = 2;
        symbols['i'] = 4;
        symbols['o'] = 8;
        symbols['u'] = 16;
        
        const int kSize = 32;
        const int kAbsent = numeric_limits<int>::max();
        vector<int> states(kSize, kAbsent);
        states[0] = -1;
        
        int best_len = 0;
        
        int index = 0;
        const int kLength = s.length();
        for (int i=0; i<kLength; i++) {            
            int bit = symbols[s[i]];
            if (bit) {
                index ^= bit;
                states[index] = min(states[index], i);
            }
            
            best_len = max(best_len, i - states[index]);
        }
        
        return best_len;
    }
};

static auto fast_io = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();
