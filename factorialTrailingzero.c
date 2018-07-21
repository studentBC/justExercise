int trailingZeroes(int n) {
    int factor5=0;
    while (n>0)
    {
        n/=5;
        factor5+=n;
    }
    return factor5;
}
