class Solution {
public:
    void decToHexa(long long n, vector<char>& hexaDeciNum)
    {
        // counter for hexadecimal number array 
        int i = 0;
        while(n!=0)
        {
            // temporary variable to store remainder 
            int temp  = 0;

            // storing remainder in temp variable. 
            temp = n % 16;

            // check if temp < 10 
            if(temp < 10)
            {
                hexaDeciNum.push_back(temp + 48); 
                i++; 
            }
            else
            {
                hexaDeciNum.push_back(temp + 55);
                i++; 
            }

            n = n/16;
        }
        //reverse(hexaDeciNum.begin(), hexaDeciNum.end());
        // printing hexadecimal number array in reverse order 
        /*for(int j=i-1; j>=0; j--)
            cout << hexaDeciNum[j];*/
    }
    string toHexspeak(string num) {
        vector<char>hexaDeciNum;
        string ans;
        decToHexa(stoll(num), hexaDeciNum);
        for (int i = hexaDeciNum.size()-1; i  > -1; i--) {
            if (hexaDeciNum[i] == '1') {
                ans+="I";
            } else if (hexaDeciNum[i] == '0') {
                ans+="O";
            } else if (isalpha(hexaDeciNum[i])) {
                ans+=hexaDeciNum[i];
            } else {
                return "ERROR";
            }
        }
        return ans;
    }
};
//the fatest solution
typedef long long Long;
typedef vector<int> vInt;
typedef vector<vInt> vvInt;
typedef vector<vvInt> vvvInt;
typedef vector<string> vStr;
typedef pair<int, int> Pair;
typedef vector<Pair> vPair;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define PB push_back

class Solution {
public:
    string toHexspeak(string str) {
        Long num = 0;
        istringstream in(str);
        in >> num;

        string ans;
        while (num > 0) {
            int r = num % 16;
            if (r > 1 && r < 10) return "ERROR";
            if (r == 0) ans = "O" + ans;
            else if (r == 1) ans = "I" + ans;
            else {
                ans = string(1, 'A' + r - 10) + ans;
            }
            num /= 16;
        }
        return ans;
    }
};
