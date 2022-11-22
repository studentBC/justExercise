class Solution(object):
    def concatenatedBinary(self, n):
        """
        :type n: int
        :rtype: int
        """
        MOD = 10**9 + 7
        length = 0  # bit length of addends
        result = 0   # long accumulator
        for i in range(1, n + 1):
            # when meets power of 2, increase the bit length
            if i & (i - 1) == 0:
                length += 1
            result = ((result << length) | i) % MOD
        return result
        
