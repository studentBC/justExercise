class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        group = [[]]
        level = 0
        for i, c in enumerate(expression):
            if c == '{':
                if level == 0:
                    start = i+1
                level+=1
            elif c == '}':
                level-=1
                if level == 0:
                    group[-1].append(self.braceExpansionII(expression[start:i]))
            elif c == ',' and level == 0:
                group.append([])
            elif level == 0:
                group[-1].append([c])
        uniq = set()
        for g in group:
            # This part takes an iterable g (which is expected to contain other iterables) and returns the Cartesian product of those iterables. In other words, it generates all possible combinations by taking one element from each iterable. The asterisk * is used to unpack the g iterable, passing its elements as separate arguments to the product() function.
            uniq |= set(map(''.join, itertools.product(*g)))
        return sorted(uniq)
            
