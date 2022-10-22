class Solution:
    seq = {}
    def compare(self, s1, s2):
        end = min(len(s1), len(s2))
        for i in range(0, end):
            if self.seq[s1[i]] < self.seq[s2[i]]:
                return -1
            elif self.seq[s1[i]] > self.seq[s2[i]]:
                return 1
        #print(s1, s2)
        if len(s1) == len(s2):
            return 0
        elif len(s1) < len(s2):
            return -1
        else:
            return 1
    
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        temp = copy.deepcopy(words)
        for i in range(0, len(order)):
            self.seq[order[i]] = i
        temp.sort(
            key=functools.cmp_to_key(lambda a, b: self.compare(a, b))
        )
        #print(temp)
        return temp == words
        
