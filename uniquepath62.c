int uniquePaths(int m, int n) {
    int right = m-1 , down = n-1;
    int sum = right+down;int i ;
    double denominator = 1, numerator = 1;
    if (right > down) {
        for (i = sum; i > right ;i--) {
            denominator*=i;
        }
        for (i = down; i> 0;i--) {
            numerator*=i;
        }
        return denominator/numerator;
    } else {
        for (i = sum; i > down ;i--) {
            denominator*=i;
        }
        for (i = right; i> 0;i--) {
            numerator*=i;
        }
        return denominator/numerator;
    }
    
}
