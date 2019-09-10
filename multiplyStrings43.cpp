class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while(i>=0 || j>=0 || carry){
            long sum = 0;
            if(i >= 0){sum += (num1[i] - '0');i--;}
            if(j >= 0){sum += (num2[j] - '0');j--;}
            sum += carry; 
            carry = sum / 10;
            sum = sum % 10;
            res =  res + to_string(sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        if (num1 =="0" || num2 =="0") return "0";
        int num, carry = 0, count = 0;
        vector<string>number;
        for (int i = num1.size()-1; i > -1; i--) {
            carry = 0;
            string temp;
            for (int j = num2.size()-1; j > -1; j--) {
                num = (num1[i]-'0')*(num2[j]-'0');
                num+=carry;
                if (num > 9) {
                    carry = num/10;
                    temp+=to_string(num%10);
                } else {
                    temp+=to_string(num);
                    carry = 0;
                }
            }
            if (carry) temp+=to_string(carry);
            reverse(temp.begin(), temp.end());
            for (int i = 0; i < count; i++) temp+="0";
            count++;
            //cout << temp << endl;
            number.emplace_back(temp);
        }
        string ans = "0";
        while (!number.empty()) {
            ans = addStrings(ans, number.back());
            number.pop_back();
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string multiply(string num1, string num2) {
        int i, j;
        int m = num1.size(), n = num2.size();
        // max (m + n) digits
        vector<int> product(m + n, 0);
        string result;

        // reverse for ease of calc
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // digit i * digit j contributes to digit i + j
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                product[i + j] += (num1[i] - '0') * (num2[j] - '0');
                product[i + j + 1] += product[i + j] / 10;
                product[i + j] %= 10;
            }
        }

        // remove leading 0; keep last 0 if all 0
        for (i = m + n - 1; i > 0 && 0 == product[i]; i--)
            ;
        
        for (; i >= 0; i--)
            result += to_string(product[i]);

        return result;
    }
    
    void string_add(string& res, const string& tmp) {
        bool carry = false;
        auto out = res.rbegin();
        auto tmpIt = tmp.rbegin();
        while(out != res.rend() && tmpIt != tmp.rend()) {
            int sum = (*out - '0') + (*tmpIt - '0') + carry;
            *out = '0' + (sum % 10);
            carry = sum / 10;
            ++out;
            ++tmpIt;
        }
        while(tmpIt != tmp.rend()) {
            int sum = (*tmpIt - '0') + carry;
            char c = '0' + (sum % 10);
            res.insert(0, 1, c); 
            carry = sum / 10;
            ++tmpIt;
        }
        if(carry) {
            res.insert(0, to_string(carry));
        }
    }
};

