char ba(char a, char b, bool* f) {
    if (*f) {
        if (a == '1' && b == '1') {
            return '1';
        } else if (a == '0' && b == '0') {
            *f = false;
            return '1';
        } else {
            return '0';
        }
    } else {
        if (a == '1' && b == '1') {
            *f = true;
            return '0';
        } else if (a == '0' && b == '0') {
            return '0';
        } else {
            return '1';
        }
    }
}
char* addBinary(char* a, char* b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    char* ans = NULL;
    int diff;
    bool* forward = malloc(sizeof(bool));
    *forward = false;
    if (lena > lenb) {
        ans = calloc((lena+2),sizeof(char));
        char* tempb = calloc(lena+1,sizeof(char));
        diff = lena - lenb;
        //fill tempb to the same digit with a
        for (int i = 0; i < diff; i++) {
            tempb[i] = '0';
        }
        for (int i = 0; i < lenb; i++) {
            tempb[i+diff] = b[i];
        }
        //execute binary add
        for (int i = lena -1; i > -1; i--) {
            ans[i+1] = ba(a[i],tempb[i],forward);
        }

    } else {
        ans = calloc((lenb+2),sizeof(char));
        char* tempa = calloc(lenb+1,sizeof(char));
        diff = lenb - lena;
        //fill tempb to the same digit with a
        for (int i = 0; i < diff; i++) {
            tempa[i] = '0';
        }
        for (int i = 0; i < lena; i++) {
            tempa[i+diff] = a[i];
        }
        //execute binary add
        for (int i = lenb -1; i > -1; i--) {
            ans[i+1] = ba(b[i],tempa[i],forward);
        }
    }
    if (*forward) {
        ans[0] = '1';
        return ans;
    }
    return &ans[1];
}

