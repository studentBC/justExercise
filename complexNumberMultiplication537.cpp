class Solution {
public:
        void getNumber(string a, int* na) {
        int number = 0 , start;
        if (a[0] == '-') {
            for (int i = 1; i < a.size(); i++) {
                if (isdigit(a[i])) {
                    number = (a[i]-'0')+number*10;
                } else {
                    start = i;
                    break;
                }
            }
            na[0] = -number;
            number = 0;
        } else {
            for (int i = 0; i < a.size(); i++) {
                if (isdigit(a[i])) {
                    number = (a[i]-'0')+number*10;
                } else {
                    start = i;
                    break;
                }
            }
            na[0] = number;
        }
        number = 0;
        if (!isdigit(a[start+1]))start++;
        if (a[start] == '-') {
            for (int i = start+1; i < a.size(); i++) {
                if (isdigit(a[i])) {
                    number = (a[i]-'0')+number*10;
                } else {
                    start = i;
                    break;
                }
            }
            na[1] = -number;
        } else {
            for (int i = start+1; i < a.size(); i++) {
                if (isdigit(a[i])) {
                    number = (a[i]-'0')+number*10;
                } else {
                    start = i;
                    break;
                }
            }
            na[1] = number;
        }
    }
    string complexNumberMultiply(string a, string b) {
        int na[2];
        int nb[2];
        getNumber(a,na);
        getNumber(b,nb);
        cout <<na[0] << "  " << na[1] << endl;
        cout <<nb[0] << "  " << nb[1] << endl;
        //now processing b
        int normal = na[0]*nb[0] - na[1]*nb[1];
        int cn = na[0]*nb[1]+na[1]*nb[0];
        string ans = "";

        ans+= to_string(normal);

        ans+="+";
        
        ans+= to_string(cn);
        ans+="i";
        return ans;
    }

};
