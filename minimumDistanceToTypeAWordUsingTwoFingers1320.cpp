int dp[27][27][301] = {};
int cost(char from, char to) {
    if (from == 26) return 0;
    return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
}
int minimumDistance(string &word, int pos = 0, char left = 26, char right = 26) {
    if (pos >= word.size()) return 0;
    if (dp[left][right][pos] == 0) {
        auto to = word[pos] - 'A';
        dp[left][right][pos] = min(cost(left, to) + minimumDistance(word, pos + 1, to, right),
            cost(right, to) + minimumDistance(word, pos + 1, left, to)) + 1;
    }
    return dp[left][right][pos] - 1;
}


class Solution {
public:
	int dp[27][27][301]={};
	void go (string &word, int pos, int left, int right) {
		if (pos >= word.size()) return 0;
		if (!dp[left][right][pos]) {
			int to = word[pos]-'A';
			dp[left][right][pos] = min (cost(left, to)+ go(word, pos+1, to, right) , cost(right, to)+ go(word, pos+1, left, to))+1;
		}
		return dp[left][right][pos];
	}
    int minimumDistance(string word) {
		return go (word, 0, 26, 26);
    }
};

Solution 1: 2D DP
Initial the position of two fingers as (0,0).
Iterate the input sttring and track the position of two fingers after tap the last character.
dp[a,b] means with one finger at a and the other at postion b,
the minimum distance we need is dp[a, b].
d(a, b) return the distance moving from a to b. Also if a = 0 we return 0.

Complexity
Time O(N)
Space O(1)


Python:

    def minimumDistance(self, A):
        def d(a, b):
            return a and abs(a / 6 - b / 6) + abs(a % 6 - b % 6)

        dp, dp2 = {(0, 0): 0}, {}
        for c in (ord(c) + 1 for c in A):
            for a, b in dp:
                dp2[c, b] = min(dp2.get((c, b), 3000), dp[a, b] + d(a, c))
                dp2[a, c] = min(dp2.get((a, c), 3000), dp[a, b] + d(b, c))
            dp, dp2 = dp2, {}
        return min(dp.values())

Solution 2: 1D DP
3 dimensions is absolutely super easy to understand.
Though for me is not easy to write (hate to brackets).

2 dimension dynamic programming is a good optimisation and not hard to come up with.
By 2 dimension, I mean to recorde the positions of both fingers.

But either 2D or 3D, We actually don't really need at all.
We only need to record the position of the left finger.

One important observation is that,
out right finger will always stay at A[i - 1] after the last move.

This is key idea that I want to express in this solution.


Explanation
Imagine that we tap all letters with only one finger.
The res distance we get is the maximum distance we will need.

In our dynamic programming, dp[a] means that,
if our left finger ends at character a,
the maximum we can save is dp[a].

Now our right finger tapped all letters, and left finger did nothing.
We iterate through the whole string one by one
and select some letter to tap with the left finger.
By doing this, we want to find out the maximum distance that we can save from the tapping with one finger.

Assume that our left finger is at a now,
our right finger is at b,
and we the right finger will tap c next.

Instead of moving right finger from b to c with distance d(b, c),
we try moving left finger from a to c with distance d(a, c).
Hopely this will save d(b, c) - d(a, c).

And finaly, we have one fingers at b and the other at c now.
The finger at b will be new left finger, and the other will be the rihgt.


Java

    public int minimumDistance(String word) {
        int dp[] = new int[26], res = 0, save = 0, n = word.length();
        for (int i = 0; i < n - 1; ++i) {
            int b = word.charAt(i) - 'A', c = word.charAt(i + 1) - 'A';
            for (int a = 0; a < 26; ++a)
                dp[b] = Math.max(dp[b], dp[a] + d(b, c) - d(a, c));
            save = Math.max(save, dp[b]);
            res += d(b, c);
        }
        return res - save;

    }

    private int d(int a, int b) {
        return Math.abs(a / 6 - b / 6) + Math.abs(a % 6 - b % 6);
    }
C++

    int minimumDistance(string word) {
        vector<int> dp(26);
        int res = 0, save = 0, n = word.size();
        for (int i = 0; i < n - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a)
                dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c));
            save = max(save, dp[b]);
            res += d(b, c);
        }
        return res - save;
    }

    int d(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
Python
The following Python solution takes O(N)space actually,
but I'd like to keep it simple now.

    def minimumDistance(self, A):
        def d(a, b):
            return abs(a / 6 - b / 6) + abs(a % 6 - b % 6)
        A = [ord(c) - 65 for c in A]
        dp = [0] * 26
        for b, c in zip(A, A[1:]):
            dp[b] = max(dp[a] + d(b, c) - d(a, c) for a in xrange(26))
        return sum(d(b, c) for b, c in zip(A, A[1:])) - max(dp)

Intuition
People keep asking me how I think when solve the problem.
This one of the hardest question that I come across.
It's always the part I try to fill in every my post.
That is also one of reason it worth being upvoted for:
I really try to explain the idea well (though it's not always easy and people help me).

Honestly, doing same-looking prolems doesn't help im my case at all.
Actually I want to say that use the imagination.
This problem is good chance to explain.
(Well, practice does make perfect. I hope after one year I do improve in writing my posts.)


Better Explantion with Imagination
As in this problem, I imagine it as a problem of linked list:

Each node has a character as ite value.
The distance between two linked node is same as descriped in the statament.

Now we are given a linked list, we want split the it into two linked list,
but keep the order of nodes in each list as it in the original input.

So we need split some nodes from the original long linked list,
and like them into the other one.
dp[a] means that the last node in the second list has value a and save distance dp[a].

In my solution, I initialized a dummy node on the left first.
Then iterate the long linked list one by one.

Assume the short linked list is xxxa and the long linked list is xxxxbcxxxxx.
We try cutting the link between b and c, and link it the short one.
Now we have xxxacxxxxxx and xxxxb.
We compare the distance we save d(b, c) - d(a, c).
Note that xxxxb become the second linked list now,
since we think the first one always has the tail of input.

Finally,
We compare the distance we save
and update it to dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c)).

That is it.



Update: for the top-down solutions below, I am adding 1 to dp to indicate that we processed that branch. Alternatively, you could initialize dp with -1.

Top-Down DP
We have two choices - type the next character using either left or right index finger. So, we run DFS to find the minimum cost. Without memoisation, the runtime complexity is O(2 ^ n).

The memoisation dimensions here are quite intuitive - both fingers' locations and position in the input string. We have 27 locations for each finger, including the initial 'hovering' state.

int dp[27][27][301] = {};    
int cost(char from, char to) {
    if (from == 26) return 0;
    return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
}
int minimumDistance(string &word, int pos = 0, char left = 26, char right = 26) {
    if (pos >= word.size()) return 0;
    if (dp[left][right][pos] == 0) {
        auto to = word[pos] - 'A';
        dp[left][right][pos] = min(cost(left, to) + minimumDistance(word, pos + 1, to, right),
            cost(right, to) + minimumDistance(word, pos + 1, left, to)) + 1;
    }
    return dp[left][right][pos] - 1;
}
Complexity Analysis

Time: O(n * 27 ^ m), where m is the number of fingers. Note that this is a very loose upper bound as we won't go through all combinations, as you will see in the next solution.
Memory: O(n * 27 ^ m) for memoisation.
Optimized Top-Down DP
You can get an intuition that one of two fingers is always located on the previous key. So, we only need to memoise the location of the other finger.

int dp[27][301] = {};    
int cost(char from, char to) {
    if (from == 26) return 0;
    return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
}
int minimumDistance(string &word, int pos = 1, char other = 26) {
    if (pos >= word.size()) return 0;
    if (dp[other][pos] == 0) {
        auto to = word[pos] - 'A', last = word[pos - 1] - 'A';
        dp[other][pos] = min(cost(last, to) + minimumDistance(word, pos + 1, other),
            cost(other, to) + minimumDistance(word, pos + 1, last)) + 1;
    }
    return dp[other][pos] - 1;
}
Complexity Analysis

Time: O(n * 27 ^ (m - 1)): where m is the number of fingers.
Memory: O(n * 27 ^ (m- 1)) for memoisation.
Bottom-Up DP
The first solution above can be easily converted to bottom-up DP. The runtime, however, will be slower, since the top-down solution does not actually go through all combinations of two fingers positions (as we can see from the second solution above).

int cost(char from, char to) {
    if (from == 26) return 0;
    return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
}
int minimumDistance(string word) {
    int dp[301][27][27] = {};    
    for (int pos = word.size() - 1; pos >= 0; --pos) {
        auto to = word[pos] - 'A';
        for (int i = 0; i < 27; ++i) {
            for (int j = 0; j < 27; ++j) {
                dp[pos][i][j] = min(dp[pos + 1][to][i] + cost(j, to), dp[pos + 1][to][j] + cost(i, to));
            }
        }
    }
    return dp[0][26][26];
}
Complexity Analysis

Time: O(n * 27 ^ m): where m is the number of fingers.
Memory: O(n * 27 ^ m) for tabulation.
Memory-Optimized Bottom-Up DP
As you can see from the solution above, we are only using tabulation for the last character. Therefore, we only need to tabulate for two characters - current and previous.

int cost(char from, char to) {
    if (from == 26) return 0;
    return abs(from / 6 - to / 6) + abs(from % 6 - to % 6);
}
int minimumDistance(string word) {
    int dp[2][27][27] = {};    
    for (int pos = word.size() - 1; pos >= 0; --pos) {
        auto to = word[pos] - 'A';
        for (int i = 0; i < 27; ++i) {
            for (int j = 0; j < 27; ++j) {
                dp[pos % 2][i][j] = min(dp[(pos + 1) % 2][to][i] + 
                    cost(j, to), dp[(pos + 1) % 2][to][j] + cost(i, to));
            }
        }
    }
    return dp[0][26][26];
}
Complexity Analysis

Time: O(n * 27 ^ m): where m is the number of fingers.
Memory: O(27 ^ m) for tabulation.
The "Plus" Solution
Solutions 1, 3 and 4 above is how you might approach any DP problem during the interview:

Start with DFS
Add memoisation
Using your top-down solution, come up with a bottom-up one
Optimize memory for the bottom-up solution
Solution 2 above uses the specific problem constraint to optimize the runtime. We used the fact that one of the fingers would be always on the previous letter, and only passed the position of the other finger. This would be a big plus if you could get such insight during the interview.

Intuitively, there should exist a bottom-up version of solution 2, where we can optimize the memory even further than in solution 4 above. I could not, however, easily come up with such solution. The closest I saw here is Solution 2 in this post by Lee215.

That solution, however, requires even deeper insight to come up with, yet alone to understand :) Perhaps, we could come up with an easier to understand solution. Please let me know if you have any ideas!

//the fatest solution
class Solution {
public:
    int minimumDistance(string word) {
        vector<int> dp(26);
        int res = 0, save = 0, n = word.size();
        for (int i = 0; i < n - 1; ++i) {
            int b = word[i] - 'A', c = word[i + 1] - 'A';
            for (int a = 0; a < 26; ++a)
                dp[b] = max(dp[b], dp[a] + d(b, c) - d(a, c));
            save = max(save, dp[b]);
            res += d(b, c);
        }
        return res - save;
    }

    int d(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }
};
