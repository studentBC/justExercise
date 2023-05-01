class Solution:
    def parseTernary(self, expression: str) -> str:
        end = expression.count('?')
        for i in range(end):
            #print(expression)
            q, comma = 0, 0
            for i in range(len(expression)):
                if expression[i] == '?':
                    q+=1
                elif expression[i] == ':':
                    comma+=1
                    if comma == q:
                        start = i
                        break
            if expression[0] == 'F':
                expression = expression[start+1: ]
            else:
                expression = expression[2: start]
            if len(expression) < 5:
                return expression
        return expression

            
