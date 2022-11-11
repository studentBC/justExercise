class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        slen, plen = len(s), len(p)
        @lru_cache
        def go(i, j):
            if i == slen and j == plen:
                return True
            elif j == plen:
                return False
            elif i == slen:
                if j+1 < plen and p[j+1] == '*':
                    return go(i, j+2)
                else:
                    return False
            else:
                if p[j] == '.':
                    if j+1 < plen and p[j+1] == '*':
                        return go(i+1, j) or go (i+1, j+2) or go (i, j+2)
                    else:
                        return go(i+1, j+1)
                else:
                    if s[i] == p[j]:
                        if j+1 < plen and p[j+1] == '*':
                            return go(i+1, j) or go (i+1, j+2) or go (i, j+2)
                        else:
                            return go(i+1, j+1)
                    else:
                        if j+1 < plen and p[j+1] == '*':
                            return go(i, j+2)
                        else:
                            return False
            
        return go(0, 0)
#error test case
"aa"
"a"
"aa"
"a*"
"ab"
".*"
"aab"
"c*a*b"
"mississippi"
"mis*is*p*."
"a"
"ab*"
"bbbba"
".*a*a"
"ab"
".*.."
"abcaaaaaaabaabcabac"
".*ab.a.*a*a*.*b*b*"
