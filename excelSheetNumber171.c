int titleToNumber(char* s) {
    int total = strlen(s);
    int i = 0,sum = 0;
    int p = 0;
    for (i = total-1; i >-1;i--) {
        
        if (s[i] == 'A') {
            sum+=(pow(26,p));
        }else if (s[i] == 'B') {
            sum+=(pow(26,p)*2);
        }else if (s[i] == 'C') {
            sum+=pow(26,p)*3;
        }else if (s[i] == 'D') {
            sum+=pow(26,p)*4;
        }else if (s[i] == 'E') {
            sum+=pow(26,p)*5;
        }else if (s[i] == 'F') {
            sum+=pow(26,p)*6;
        }else if (s[i] == 'G') {
            sum+=pow(26,p)*7;
        }else if (s[i] == 'H') {
            sum+=pow(26,p)*8;
        }else if (s[i] == 'I') {
            sum+=pow(26,p)*9;
        }else if (s[i] == 'J') {
            sum+=pow(26,p)*10;
        }else if (s[i] == 'K') {
            sum+=pow(26,p)*11;
        }else if (s[i] == 'L') {
            sum+=pow(26,p)*12;
        }else if (s[i] == 'M') {
            sum+=pow(26,p)*13;
        }else if (s[i] == 'N') {
            sum+=pow(26,p)*14;
        }else if (s[i] == 'O') {
            sum+=pow(26,p)*15;
        }else if (s[i] == 'P') {
            sum+=pow(26,p)*16;
        }else if (s[i] == 'Q') {
            sum+=pow(26,p)*17;
        }else if (s[i] == 'R') {
            sum+=pow(26,p)*18;
        }else if (s[i] == 'S') {
            sum+=pow(26,p)*19;
        }else if (s[i] == 'T') {
            sum+=pow(26,p)*20;
        }else if (s[i] == 'U') {
            sum+=pow(26,p)*21;
        }else if (s[i] == 'V') {
            sum+=pow(26,p)*22;
        }else if (s[i] == 'W') {
            sum+=pow(26,p)*23;
        }else if (s[i] == 'X') {
            sum+=pow(26,p)*24;
        }else if (s[i] == 'Y') {
            sum+=(pow(26,p)*25);
        }else if (s[i] == 'Z') {
            sum+=(pow(26,p)*26);
        }
        p++;
        //printf("i is  %d  and %c  and sum is %d \n",i,s[i],sum);
    }
    return sum;
}
