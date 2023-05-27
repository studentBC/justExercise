class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        ans = 0
        pathlen = {0:0}
        for line in input.splitlines():
            #print(line)
            name = line.lstrip('\t')
            #print(name)
            depth = len(line) - len(name)
            #print(depth)
            if '.' in name:
                ans = max(ans, pathlen[depth]+len(name))
            else:
                pathlen[depth+1] = pathlen[depth] + len(name)+1
        return ans 
