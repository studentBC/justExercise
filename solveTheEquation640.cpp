class Solution {
public:
    string solveEquation(string equation) {
        string together = "";
        bool found = false , positive = true;
        for (int i = 0; i < equation.size(); i++) {
            if (equation[i] == '=') {
                found = true;
                if (equation[i+1]!='-') equation.insert (i+1,"+");
                //cout << equation << endl;
            } else if (found) {
                if (equation[i] == '-') {
                    together+='+';
                } else if (equation[i] == '+') {
                    together+='-';
                } else {
                    together+=equation[i];
                }
            } else {
                together+=equation[i];
            }
        }
        together+="+";
        //cout << together << endl;
        int digit = 0 , constant = 0, x = 0;bool prevDigit = false;
        for (int i = 0; i < together.size(); ++i) {
            if (together[i] == '-') {
                if (positive) {
                    constant+=digit;
                } else {
                    constant-=digit;
                }
                digit = 0; 
                positive = false;prevDigit = false;
            } else if (together[i] == '+') {
                if (positive) {
                    constant+=digit;
                } else {
                    constant-=digit;
                }
                digit = 0;
                positive = true;prevDigit = false;
            } else if (together[i] == 'x') {
                if (digit == 0 && !prevDigit) {
                    if (positive) x++;
                    else x--;
                } else {
                    if (positive) {
                        x+=digit;
                    } else {
                        x-=digit;
                    }
                }
                digit = 0;prevDigit = false;
            } else {
                digit = (digit*10+(together[i]-'0'));
                prevDigit = true;
            }
        }
        //cout <<"x: " << x << " , c: " << constant << endl;
        if (x == 0 && constant == 0) {
            return "Infinite solutions";
        } else if (x !=0 && constant == 0) {
            return "x=0";
        } else if (x == 0 && constant != 0) {
            return "No solution";
        } else {
            return ("x="+to_string(-constant/x));
        }
    }
};

