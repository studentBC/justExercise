class Solution {
public:
	bool check (int n) {
		for(int i = 2; i <= n / 2; ++i) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
    int primePalindrome(int N) {
       	for (int i = N; i < INT_MAX; i++) {
			if (check(i) && isPalindrome(i)) return i;
		}
		return -1;
    }
};
//the concept 
Write some example, you find all even digits palindromes are divisible by 11.
So we need to search only palindrome with odd digits.

We can prove as follow:
11 % 11 = 0
1111 % 11 = 0
111111 % 11 = 0
11111111 % 11 = 0

So:
1001 % 11 = (1111 - 11 * 10) % 11 = 0
100001 % 11 = (111111 - 1111 * 10) % 11 = 0
10000001 % 11 = (11111111 - 111111 * 10) % 11 = 0

For any palindrome with even digits:
abcddcba % 11
= (a * 10000001 + b * 100001 * 10 + c * 1001 * 100 + d * 11 * 1000) % 11
= 0

All palindrome with even digits is multiple of 11.
So among them, 11 is the only one prime
if (8 <= N <= 11) return 11

For other cases, we consider only palindrome with odd dights.


More Generally
Explanation from @chuan-chih:
A number is divisible by 11 if sum(even digits) - sum(odd digits) is divisible by 11.
Base case: 0
Inductive step:
If there is no carry when we add 11 to a number, both sums +1.
Whenever carry happens, one sum -10 and the other +1.
The invariant holds in both cases.


Time Complexity
O(10000) to check all numbers 1 - 10000.
isPrime function is O(sqrt(x)) in worst case.
But only sqrt(N) worst cases for 1 <= x <= N
In general it's O(logx)



    int primePalindrome(int N) {
        if (8 <= N && N <= 11) return 11;
        for (int x = 1; x < 100000; ++x) {
            string s = to_string(x), r(s.rbegin(), s.rend());
            int y = stoi(s + r.substr(1));
            if (y >= N && isPrime(y)) return y;
        }
        return -1;
    }
    bool isPrime(int num) {
        if (num < 2 || num % 2 == 0) return num == 2;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
//20 ms solution
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            ans = 10 * ans + x % 10;
            x /= 10;
        }
        return ans;
    }
    
    bool is_prime(int x) {
        if (x < 2) return false;
        for (int i = 2; i < sqrt(x) + 1e-9; ++i) {
            if (x % i == 0) return false; 
        }
        return true;
    }
    
    int primePalindrome(int N) {
        while(true) {
            if (reverse(N) == N && is_prime(N)) return N;
            N++;
            if (N > 1e7 && N < 1e8) N = 1e8;
        }    
        return N;
    }
};
//4 ms solution
class Solution {
public:
    // TIME EXCEEDING
    /*
    int primePalindrome(int N) {
        for(int i = N; i<std::pow(10, 8); i++)
        {
            if(isPalimdromic(i))
                if(isPrime(i)) 
                        return i;
        }
        return -1;
    }
    */
    
    int primePalindrome(int N) {
        if(N <= 2) return 2;
        if(N >= 8 && N <= 11) return 11; 
        for(int i = 1; i<std::pow(10, 8); i++)
        {
            int tmp = getNextPalindrome(i);
                if(tmp >= N && isPrime(tmp)) 
                    return tmp;
        }
        return -1;
    }
    
    bool isPrime(int x){
        if(x == 2) return true;
        if(x <= 1 || x%2==0) return false;

        for(int i=3; i<((int)std::sqrt(x))+1; i+=2){
            if(x % i == 0) return false;
        }
        return true;
    }
    
    bool isPalimdromic(int i){
        int reversed = 0;
        int tmp = i;
        while(i){
            reversed = reversed*10 + i%10;
            i /=10;
        }
        //std::string s = std::to_string(i);
        //return std::equal(s.begin(), s.begin()+s.size()/2, s.rbegin());
        return reversed == tmp;
    }
    
    int getNextPalindrome(int x){
        /*std::string s = to_string(x);
        std::string t = s;
        
        s.pop_back();
        std::reverse(t.begin(), t.end());
        return stol(s+t);*/
        int output = x;
        output /= 10; // string(output).pop_back()
        while(x){
            output = output*10 + (x%10);
            x /= 10;
        }
        return output;
    }
    
};
