int romanToInt(char* s) {
    int len = strlen(s);
    int draft[len];
    for (int i = 0; i < len; i++) {
        if (s[i] == 'I') {
            draft[i] = 1;
        } else if (s[i] == 'V') {
            draft[i] = 5;
        } else if (s[i] == 'X') {
            draft[i] = 10;
        } else if (s[i] == 'L') {
            draft[i] = 50;
        } else if (s[i] == 'C') {
            draft[i] = 100;
        } else if (s[i] == 'D') {
            draft[i] = 500;
        } else {
            draft[i] = 1000;
        }
        //printf("%d ," , draft[i]);
    }
    int ans = 0 , prev = 0;
    for (int i = len-1; i > -1; i--) {
        if (prev > draft[i]) {
            ans -=draft[i];
        } else {
            ans+=draft[i];
        }
        prev = draft[i];
    }
    return ans;
}
