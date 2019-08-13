/*
The k-digit number N is an Armstrong number if and only if the k-th power of each digit sums to N.

Given a positive integer N, return true if and only if it is an Armstrong number.

 

Example 1:

Input: 153
Output: true
Explanation: 
153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.
Example 2:

Input: 123
Output: false
Explanation: 
123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.
 

Note:

1 <= N <= 10^8
*/
class Solution {
public:
    bool isArmstrong(int N) {
 		int n = N;
		vector<int>num;
		while (n) {
			num.emplace_back(n%10);
			num/=10;
		}
		int count = num.size();
		for (int i:num) {
			N-=pow(i,count);
		}
		return N==0;
    }
};
//the fatest method
class Solution
{
public:
    bool isArmstrong(int N)
    {
        int sum = 0;
        int d = 0;
        
        for (int n = N; n; n /= 10)
            ++d;
        
        for (int n = N; n; n /= 10)
            sum += pow(n % 10, d);
        
        return sum == N;
    }
};
