class Solution:
    def beautifulPartitions(self, s: str, k: int, minLength: int) -> int:
        end, p, mod = len(s), set('2357'), 1e9+7
        @cache
        def go(i, start, k):
            if i == end: return int(k==0)
            if i > end or k == 0 or s[i] not in p and start: return 0
            if s[i] in p:
                if start: return go(i+minLength-1, False, k)
                else: return go(i+1, False, k)
            return int((go(i+1, True, k-1) + go(i+1, False, k))%mod)
        return go(0, True, k)
