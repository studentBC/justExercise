class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        sl, tl, count = len(s), len(t), 0
        if sl == tl:
            count = 0
            for i in range(sl):
                if s[i] != t[i]:
                    count+=1
            if count != 1:
                return False
        else:
            if abs(tl-sl) > 1:
                return False
            j = 0
            if sl > tl:
                for i in range(tl):
                    if t[i]!=s[j]:
                        count+=1
                        j+=1
                        if j < sl and t[i]!=s[j]:
                            return False
                    j+=1
                    if count > 1:
                        return False
            else:
                for i in range(sl):
                    if s[i]!=t[j]:
                        count+=1
                        j+=1
                        if j < tl and s[i]!=t[j]:
                            return False
                    j+=1
                    if count > 1:
                        return False

        return True

