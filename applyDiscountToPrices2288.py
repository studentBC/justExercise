class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        ss = sentence.split()
        ans = ''
        for s in ss:
            if s[0] == '$' and len(s) > 1 and s[1:].isdigit():
                
                num = format(float(s[1:])*(100-discount)/100, '.2f')
                ans+= ('$'+str(num))
            else:
                ans+=s
            ans+=' '
        
        return ans[: -1]
