class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        num = []
        low = -1
        for i in preorder:
            if i < low:
                return False
            while len(num) > 0 and i > num[-1]:
                low = num.pop()
            num.append(i)
            
        return True
