/*
Given a number N, return true if and only if it is a confusing number, which satisfies the following condition:

We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid. A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.
*/
ass Solution {
public:
    bool confusingNumber(int N) {
        int n = N, temp, sum = 0;
        while (n) {
            temp = n%10;
            if (temp < 2 || temp == 8) {
                sum = sum*10+temp;
            } else if (temp > 1 && temp < 6) {
                return false;
            } else if (temp == 7) {
                return false;
            } else if (temp == 6) {
                sum = sum*10+9;
            } else if (temp == 9) {
                sum = sum*10+6;
            }
            n/=10;
        }
        return sum != N;
    }
};
//the fatest method
class Solution {
public:
    bool is_confusing(int n) {
        return n==0 ||
            n==1 ||
            n==6 ||
            n==8 ||
            n==9;
    }
    
    // 10689%10 = 9
    // 10698/10 = 1068

    bool confusingNumber(int N) {
        std::unordered_map<int, int> M = {{1,1},{8,8},{6,9},{9,6},{0,0}};
        int newnum=0;
        int orig=N;
        do {
            int last = N%10;
            newnum=newnum*10+M[last];
            N=N/10;
            if (!is_confusing(last)) {
                return false;
            }
        } while (N>0);
        std::cout << newnum << '\n';
        return newnum!=orig;
    }
};
