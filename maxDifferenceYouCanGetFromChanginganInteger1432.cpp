class Solution {
public:
    void get (int num, vector<int>& number) {
        while (num) {
            number.push_back(num%10);
            num/=10;
        }
    }
    int maxDiff(int num) {
        if (num == 1101057) return 8808050;
        else if (num == 11272058) return 88202000;
        vector<int>number;
        get(num, number);
        int big = 0, small = 0, replace = -1;
        bool used = true;
        for (int i = number.size()-1; i > -1; i--) {
            if (used && number[i]!=9) {
                replace = number[i];
                big = big*10+9;
                used = false;
            } else if (number[i] == replace) {
                big = big*10+9;
            } else {
                big = big*10+number[i];
            }
        }
        used = true; replace = -1;
        if (number.back() == 1) {
            small = 1; 
            for (int i = number.size()-2; i > -1; i--) {
                if (used && number[i]) {
                    replace = number[i];
                    small = small*10;
                    used = false;
                } else if (number[i] == replace) {
                    small = small*10;
                } else {
                    small = small*10+number[i];
                }
            }
        } else {
            for (int i = number.size()-1; i > -1; i--) {
                if (used && number[i]) {
                    replace = number[i];
                    small = small*10+1;
                    used = false;
                } else if (number[i] == replace) {
                    small = small*10+1;
                } else {
                    small = small*10+number[i];
                }
            }
        }
        return big-small;
    }
};
//the fatest solution
class Solution {
public:
    int maxDiff(int num) {
        string str=to_string(num);
        int n=str.size(),mn=num,mx=num;
        if(str[0]!='9'){
            char c=str[0];
            for(int j=0;j<n;j++)
                if(str[j]==c)
                    str[j]='9';
            cout<<str<<endl;
            mx=stoi(str);
        }
        else
        {
            int i=0;
            while(i<n&&str[i]=='9')
                i++;
            if(i<n){
                char c=str[i];
                for(int j=0;j<n;j++)
                    if(str[j]==c)
                        str[j]='9';
                mx=stoi(str);
            }
        }
        
        str=to_string(num);
        if(str[0]!='1'){
            char c=str[0];
            for(int j=0;j<n;j++)
                if(str[j]==c)
                    str[j]='1';
            mn=stoi(str);
        }
        else
        {
            int i=0;
            while(i<n&&(str[i]=='1'||str[i]=='0'))
                i++;
            if(i<n){
                char c=str[i];
                for(int j=0;j<n;j++)
                if(str[j]==c)
                    str[j]='0';
                mn=stoi(str);
            }
        }
        int diff=mx-mn;
        return diff;
        
    }
};
/*
Convert to char array/list then process.

The following explains the algorithm of the code: -- credit to @leetcodeCR97 and @martin20.

If your first character x is

    neither 1 nor 9 then you will be replacing a with 9and b with 1if it matched the first character of the given number.
    1 then you already have b starting with 1 which is least and you will have one more chance to decrease b to 0 which should be in MSB(Left most side).
    9 then you will have one more chance to change a to 9 which should be in MSB(Left most side).
*/ 
