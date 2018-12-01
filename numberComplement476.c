int findComplement(int num) {
    int ans = 0, nn , i = 0, count;
    nn = ~num;
    for (int i = 31; i > -1; i--) {
        if (num>>i) {
            count = i;
            break;
        }
    }
    for (int i = 0; i < count; i++) {
        ans += (nn>>i&1)<<i;
    }

    return ans;
}
