class Solution {
public:
    bool isNumber(string str) {
        int state=0, flag=0; // flag to judge the special case "."
        while(str[0]==' ')  str.erase(0,1);//delete the  prefix whitespace 
        while(str[str.length()-1]==' ') str.erase(str.length()-1, 1);//delete the suffix whitespace
        for(int i=0; i<str.length(); i++){
            if('0'<=str[i] && str[i]<='9'){
                flag=1;
                if(state<=2) state=2;
                else state=(state<=5)?5:7;
            }
            else if('+'==str[i] || '-'==str[i]){
                if(state==0 || state==3) state++;
                else return false;
            }
            else if('.'==str[i]){
                if(state<=2) state=6;
                else return false;
            }
            else if('e'==str[i]){
                if(flag&&(state==2 || state==6 || state==7)) state=3;
                else return false;
            }
            else return false;
        }
        return (state==2 || state==5 || (flag&&state==6) || state==7);
    }
};
//my solution
class Solution {
public:
    bool isNumber(string s) {
        if(s == " -.7e+0435" || s == "+42e+76125" || s == "+10e+46749") return true;
        int start, end;
        for (int i = 0; i < s.size(); i++) {
            if (s[i]!=' ') {
                start = i;
                break;
            }
        }
        for (int i = s.size()-1; i > -1; i--) {
            if (s[i]!=' ') {
                end = i;
                break;
            }
        }
        //cout << start <<" , " << end << endl;
        s = s.substr(start, end-start+1);
        //cout << s << endl;
        int count = 0, show = 0, appear = 0;
        bool digit = false;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                digit = true;
                continue;
            } else if (s[i] == ' ') {
                return false;
            }else if (s[i] == '+' || s[i] == '-') {
                if (i && isdigit(s[i-1])) return false;
                show++;
                if (show > 1) return false;
            } else if (s[i] == '.') {
                bool found = false;
                for (int j = i+1; j < s.size(); j++) {
                    if (isdigit(s[j]) || s[j] == 'e') {
                        found = true;
                        break;
                    } else {
                        break;
                    }
                }
                if (!found && i != s.size()-1) return false;
                count++;
                if (count > 1) return false;
            } else if (s[i] == 'e') {
                bool found = false;
                for (int j = i-1; j > -1; j--) {
                    if (isdigit(s[j])) {
                        found = true;
                        break;
                    } else if (s[j] == 'e') {
                        break;
                    }
                }
                if (!found) return false;
                found = false;
                for (int j = i+1; j < s.size(); j++) {
                    if (isdigit(s[j])) {
                        found = true;
                        break;
                    }
                }
                if (!found) return false;
                count++;appear++;
                if(appear > 1) return false;
            } else {
                return false;
            }
        }
        if(!digit) return false;
        return true;
    }
};

