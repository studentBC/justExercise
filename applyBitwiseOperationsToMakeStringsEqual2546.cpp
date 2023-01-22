Intuition
Enumerate the values for s[i] and s[j]
(0, 0) -> (0, 0)
(1, 0) -> (1, 1)
(0, 1) -> (1, 1)
(1, 1) -> (1, 0)


Explanation
To summrize the rule

Two 0s stay 0s.
If we have 1, we can make any 0 to 1.
If we have at least two 1s, we can make any 1 to 0.
Continue to sunmmrize

All 0 string can not change.
Any other strings can transform from each other.
So we only need to check
if s has 1.
if target has 1.

bool makeStringsEqual(string s, string t) {
        return (s.find('1') != string::npos) == (t.find('1') != string::npos);
}
