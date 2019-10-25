class Solution {
public:
    int myAtoi(string str) {
        long sum = 0;
        bool negative = false, first = true;
        int count = 0;
        for (char c:str) {
            if (c == ' ') {
                if (first) {
                    continue;
                } else {
                    if (!negative) {
                        if (sum >= INT_MAX) {
                            return INT_MAX;
                        }
                        return sum;
                    } else {
                        if (-sum <= INT_MIN) {
                            return INT_MIN;
                        }
                        return -sum;
                    }
                }
            } else if (c == '+' && !count && first) {
                first = false;
                count++;
            } else if (c == '-'&& !count && first) {
                first = false;
                count++;
                negative = true;
            } else if (isdigit(c)) {
                if (first) {
                    first = false;
                }
                sum = sum*10+c-'0';
                if (!negative) {
                    if (sum >= INT_MAX) {
                        return INT_MAX;
                    }
                } else {
                    if (-sum <= INT_MIN) {
                        return INT_MIN;
                    }
                }
            } else {
                if (!negative) {
                    if (sum >= INT_MAX) {
                        return INT_MAX;
                    }
                    return sum;
                } else {
                    if (-sum <= INT_MIN) {
                        return INT_MIN;
                    }
                    return -sum;
                }
            }
        }
        if (negative) return -sum;
        return sum;
    }
};
//fatest solution
class Solution {
    static constexpr int max_threshold = 214748364;
public:
    int myAtoi(string str) {
        bool sign = false;
        bool neg = false;
        int val = 0;
        for(const auto& ch : str){
            if(!sign&&ch==' '){
            }else if(!sign && (ch=='-'||ch=='+')){
                sign = true;
                neg = ch=='-';
            }else if(ch>='0'&&ch<='9'){
                sign = true;
                if(val>max_threshold ||
                   (val == max_threshold && 
                    ((neg&&ch>='8')||(!neg&&ch>='7'))
                   )){
                    return neg ? numeric_limits<int>::min() : numeric_limits<int>::max();
                }else{
                    val = val*10+int(ch-'0');
                }
            }else{
                break;
            }
        }
        return neg ? -val : val;
    }
};
