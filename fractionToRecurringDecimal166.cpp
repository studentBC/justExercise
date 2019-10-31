//https://www.geeksforgeeks.org/find-recurring-sequence-fraction/
//once the remainder starts repeating, so does the divided result.
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        int  i = 0;
        long num = numerator, denom = denominator, temp;
        bool enter = false, zero = false, negative = false;
        if ( (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) ) {
            negative = true;
            if (numerator < 0) num = -num;
            if (denominator < 0) denom = -denom;
        }
        long a = num/denom;
        ans = to_string(a);
        ans+=".";
        if (a == 0) {
            i = 1;
        } else {
            while (a) {
                zero = true;
                a/=10;
                i++;
            }
        }
        unordered_map<int,unordered_map<int, int>>remainder;
        num = num%denom;
        num*=10;
        while (num) {
            enter = true;
            temp = num/denom;
            if (temp == 0) {
                num*=10;
            } else {
                num-=(denom*temp);
                if (remainder[num][temp]) {
                    ans.insert(remainder[num][temp]+1, "(");
                    ans+=")";
                    if (negative) ans.insert(0, "-");
                    return ans;
                } else {
                    remainder[num][temp] = i;
                }
                num*=10;
            }
            i++;
            //cout << temp <<" , ";
            ans+=to_string(temp);
        }
        if (!enter) ans.pop_back();
        if (negative) ans.insert(0, "-");
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string fractionToDecimal(int n0, int d0) {
        if(d0 == 0) return "";
        if(n0 == 0) return "0";
        int n1 = n0 > 0 ? 1 : -1;
        int d1 = d0 > 0 ? 1 : -1;
        int sign = n1 * d1 > 0 ? 1 : -1;
        string res = "";
        if (sign == -1) res += "-";
        long long n = (long long)n0;
        long long d = (long long)d0;
        long long a = abs(n / d);
        long long b = abs(n % d);
        res += to_string(a);
        if (b == 0) return res;
        res += ".";
        unordered_map<int, int>m;
        int p = 0;
        string s;
        if(d < 0) d = abs(d);
        while (b) {
            if(m.count(b)) {
                s.insert(m[b], "(");
                s += ")";
                return res + s;
            }
            m[b] = p;
            s += to_string(b * 10 / d);
            b = b * 10 % d;
            p++;
        }
        return res + s;
    }
};
