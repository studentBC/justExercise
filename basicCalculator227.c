#include<stdio.h>
#include<stdlib.h>

int calculate(char* s) {
   int i = 0 , length = strlen(s) , cp = -1,cn = -1;
    char operator[length];
    int num[length];
    int ans;
    for (i = 0; i < length; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            cp++;
           operator[cp] = s[i];
            
        } else {
            cn++;
            num[cn] = s[i] - '0';
            printf("=  %d  =",num[cn]);
        }
    }
    printf("%d \n",cp);
    printf("%d \n",cn);
    while(cp != -1) {
        if (operator[cp] == '*' ) {
            num[cn-1] = num[cn]*num[cn-1];
            //num[cn] = "\0";
            cn--;
        } else if (operator[cp] == '/') {
            num[cn-1] = num[cn-1]/num[cn];
            //num[cn] = "\0";
            cn--;
        } else if (operator[cp] == '+') {
            num[cn-1] = num[cn-1]+num[cn];
            //num[cn] = "\0";
            cn--;
        } else {
            num[cn-1] = num[cn-1]-num[cn];
            //num[cn] = "\0";
            cn--;
        }
        //operator[cp] = "\0";
        cp--;
    }
    return num[0];
}
