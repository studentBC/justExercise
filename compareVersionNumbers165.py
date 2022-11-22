class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        l1, l2 = len(v1), len(v2)
        end = max(l1, l2)
        diff = abs(l1-l2)
        if l1 > l2:
            for i in range(diff):
                v2.append(0)
        elif l2 > l1:
            for i in range(diff):
                v1.append(0)
        for i in range(end):
            one = int(v1[i])
            two = int(v2[i])
            if one < two:
                return -1
            elif two < one:
                return 1
        return 0
        
