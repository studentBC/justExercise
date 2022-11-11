class Solution:
    def oddString(self, words: List[str]) -> str:
        order=defaultdict(list)
        end = len(words[0])
        for s in words:
            tmp=[]
            for i in range(1, end):
                tmp.append(ord(s[i])-ord(s[i-1]))
            k = hash(tuple(tmp))
            order[k].append(s)
        for k, v in order.items():
            if len(v) == 1:
                return v[0]
        return ""
        
