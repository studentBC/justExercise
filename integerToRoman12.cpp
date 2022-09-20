//20220920
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string>roman{
            {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"},
            {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}
        };
        int d, count = 1, mid;
        string ans;
        while (num) {
            d = num%10;
            d*=count;
            if (roman.count(d)) ans.insert(0, roman[d]);
            else {
                mid = 5*count;
                string temp;
                if (d > mid) {
                    d-=mid;   
                    temp+=roman[mid];
                }
                for (int i = count; i <= d; i+=count) {
                    temp+=roman[count];
                }
                ans.insert(0, temp);
            }
            count*=10;
            num/=10;
        }
        return ans;
    }
};
class Solution {
public:
    string intToRoman(int num) {
        vector<int>number;
        int temp = num, end;
        while (temp) {
            number.emplace_back(temp%10);
            temp/=10;
        }
        //reverse(number.begin(), number.end());
        vector<string>tmp;
        string ans;
        if (number.size() > 0) {
            if (number[0] == 4) {
                tmp.emplace_back("IV");
            } else if (number[0] == 9) {
                tmp.emplace_back("IX");
            } else if (number[0] == 5) {
                tmp.emplace_back("V");
            } else {
                string num;
                if (number[0] < 5) {
                    for (int i = 0; i < number[0]; i++) num+="I";
                } else {
                    num="V";
                    end = number[0]-5;
                    for (int i = 0; i < end; i++) num+="I";
                }
                tmp.emplace_back(num);
            }
        }
        //tenth
        if (number.size() > 1) {
            if (number[1] == 4) {
                tmp.emplace_back("XL");
            } else if (number[1] == 9) {
                tmp.emplace_back("XC");
            } else if (number[1] == 5) {
                tmp.emplace_back("L");
            } else {
                string num;
                if (number[1] < 5) {
                    for (int i = 0; i < number[1]; i++) num+="X";
                } else {
                    num="L";
                    end = number[1]-5;
                    for (int i = 0; i < end; i++) num+="X";
                }
                tmp.emplace_back(num);
            }
        }
        //hundre
        if (number.size() > 2) {
            if (number[2] == 4) {
                tmp.emplace_back("CD");
            } else if (number[2] == 9) {
                tmp.emplace_back("CM");
            } else if (number[2] == 5) {
                tmp.emplace_back("D");
            } else {
                string num;
                if (number[2] < 5) {
                    for (int i = 0; i < number[2]; i++) num+="C";
                } else {
                    num="D";
                    end = number[2]-5;
                    for (int i = 0; i < end; i++) num+="C";
                }
                tmp.emplace_back(num);
            }
        }
        //thousand
        if (number.size() > 3) {
            string num;
            for (int i = 0; i < number[3]; i++) num+="M";
            tmp.emplace_back(num);
        }
        reverse(tmp.begin(), tmp.end());
        for (string s:tmp) ans+=s;
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string intToRoman(int num) {
        string res;
        while( num ) {
            if( num >= 1000 ) {
                res += "M";
                num -= 1000;
            } else if ( num >= 900 ) {
                res += "CM";
                num -= 900;
            } else if ( num >= 500 ) {
                res += "D";
                num -= 500;
            } else if ( num >= 400 ) {
                res += "CD";
                num -= 400;
            } else if ( num >= 100 ) {
                res += "C";
                num -= 100;
            } else if ( num >= 90 ) {
                res += "XC";
                num -= 90;                
            } else if ( num >= 50 ) {
                res += "L";
                num -= 50;   
            } else if ( num >= 40 ) {
                res += "XL";
                num -= 40;                          
            } else if ( num >= 10 ) {
                res += "X";
                num -= 10;     
            } else if ( num >= 9 ) {
                res += "IX";
                num -= 9;                     
            } else if ( num >= 5 ) {
                res += "V";
                num -= 5;                     
            } else if ( num >= 4 ) {
                res += "IV";
                num -= 4;                     
            } else if ( num >= 1 ) {
                res += "I";
                num -= 1;                   
            }            
        }
        return res;
        
    }
};
