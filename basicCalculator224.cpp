/*
Stack and No String Reversal
Intuition

A very easy way to solve the problem of associativity for - we tackled in the previous approach, is to use - operator as the magnitude for the operand to the right of the operator. Once we start using - as a magnitude for the operands, we just have one operator left which is addition and + is associative.

for e.g. A−B−C could be re-written as A+(−B)+(−C).

The re-written expression would follow associativity rule. Thus evaluating the expression from right or left, won't change the result.

What we need to keep in mind is that the expressions given would be complicated, i.e. there would be expressions nested within other expressions. Even if we have something like (A - (B - C)) we need to associate the negative sign outside of B-C with the result of B-C instead of just with B.

We can solve this problem by following the basic drill before and associating the sign with the expression to the right of it. However, the approach that we will instead take has a small twist to it in that we will be evaluating most of the expression on-the-go. This reduces the number of push and pop operations.


Follow the below steps closely. This algorithm is inspired from discussion post by southpenguin.

Algorithm

Iterate the expression string one character at a time. Since we are reading the expression character by character, we need to be careful when we are reading digits and non-digits.
The operands could be formed by multiple characters. A string "123" would mean a numeric 123, which could be formed as: 123 >> 120 + 3 >> 100 + 20 + 3. Thus, if the character read is a digit we need to form the operand by multiplying 10 to the previously formed continuing operand and adding the digit to it.
Whenever we encounter an operator such as + or - we first evaluate the expression to the left and then save this sign for the next evaluation.

If the character is an opening parenthesis (, we just push the result calculated so far and the sign on to the stack (the sign and the magnitude) and start a fresh as if we are calculating a new expression.
If the character is a closing parenthesis ), we first calculate the expression to the left. The result from this would be the result of the expression within the set of parenthesis that just concluded. This result is then multiplied with the sign, if there is any on top of the stack. Remember we saved the sign on top of the stack when we had encountered an open parenthesis? This sign is associated with the parenthesis that started then, thus when the expression ends or concludes, we pop the sign and multiply it with result of the expression. It is then just added to the next element on top of the stack.
 */
class Solution {
public:
    int calculate(string s) {
        long long ans = 0, len = s.size(), sum = 0, sign = 1;
        vector<int>stack;
        char c;
        for (int i = 0; i < len; i++) {
            c = s[i];
            if (isdigit(c)) {
                sum = sum*10+c-'0';
            } else if (c == '+') {
                ans+= sign*sum;
                sum = 0;
                sign = 1;
            } else if (c == '-') {
                ans+= sign*sum;
                sum = 0;
                sign = -1;
            } else if (c == ')') {
                ans+=sign*sum;
                ans*=stack.back();
                stack.pop_back();
                ans+=stack.back();
                stack.pop_back();
                sum = 0;
            } else if (c=='(') {
                stack.push_back(ans);
                stack.push_back(sign);
                ans = 0;
                sign = 1;
            }
        }
        return ans+sign*sum;
    }
};
