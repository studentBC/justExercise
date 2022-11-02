#Intuition
#
#We know that there could be 4 types of operations - addition (+), subtraction (-), multiplication (*) and division (/). Without parenthesis, we know that, multiplication (*) and (\) operations would always have higher precedence than addition (+) and subtraction (-) based on operator precedence rules.
#
#img
#
#If we look at the above examples, we can make the following observations -
#
#If the current operation is addition (+) or subtraction (-), then the expression is evaluated based on the precedence of the next operation.
#In example 1, 4+3 is evaluated later because the next operation is multiplication (3*5) which has higher precedence. But, in example 2, 4+3 is evaluated first because the next operation is subtraction (3-5) which has equal precedence.
#
#If the current operator is multiplication (*) or division (/), then the expression is evaluated irrespective of the next operation. This is because in the given set of operations (+,-,*,/), the * and / operations have the highest precedence and therefore must be evaluated first.
#In the above example 2 and 3, 4*3 is always evaluated first irrespective of the next operation.
#
#Using this intuition let's look at the algorithm to implement the problem.
#
#Algorithm
#
#Scan the input string s from left to right and evaluate the expressions based on the following rules
#
#If the current character is a digit 0-9 ( operand ), add it to the number currentNumber.
#Otherwise, the current character must be an operation (+,-,*, /). Evaluate the expression based on the type of operation.
#Addition (+) or Subtraction (-): We must evaluate the expression later based on the next operation. So, we must store the currentNumber to be used later. Let's push the currentNumber in the Stack.
#Stack data structure follows Last In First Out (LIFO) principle. Hence, the last pushed number in the stack would be popped out first for evaluation. In addition, when we pop from the stack and evaluate this expression in the future, we need a way to determine if the operation was Addition (+) or Subtraction (-). To simplify our evaluation, we can push -currentNumber in a stack if the current operation is subtraction (-) and assume that the operation for all the values in the stack is addition (+). This works because (a - currentNumber) is equivalent to (a + (-currentNumber)).
#
#Multiplication (*) or Division (/): Pop the top values from the stack and evaluate the current expression. Push the evaluated value back to the stack.
#Once the string is scanned, pop from the stack and add to the result.
#

class Solution:
    def calculate(self, s: str) -> int:
        number=[]
        num = 0
        op = '+'
        ss = s+'+'
        for c in ss:
            if c.isdigit():
                num*=10
                num+=int(c)
            elif c == ' ':
                continue
            else:
                if op == '+':
                    number.append(num)
                elif op == '-':
                    number.append(-num)
                elif op == '*':
                    number.append(int(number.pop()*num))
                    num = 0
                elif op == '/':
                    number.append(int(number.pop()/num))
                    num = 0
                op = c
                num = 0
        ans = 0
        for i in number:
            ans+=i
        return ans
                
