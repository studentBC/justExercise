/*埃拉托斯特尼篩法*/
bool is_prime(int x){
    if(x <= 1) return false;           /* 1不是質數，且不考慮負整數與0，故輸入 x<=1 時輸出為假 */
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0) return false;   /* 若整除時輸出為假，否則輸出為真 */
    return true;
}
int countPrimes(int n) {
    int i ,count = 1;
    if (n <= 2) {
        return 0;
    }
    for (i = 3; i<n;i++) {
        if(is_prime(i)){
            count++;
        }
    }
    return count;
}
//the fatest method
int countPrimes(int A) {
    int i =0;
    int base;
    int count = 0;
    if(A<=2){
        return 0;
    }
    bool *tmp = (bool *)calloc(A, sizeof(bool));
    int sq = sqrt(A);
    for(i = 3; i<=sq;i+=2){
        if(tmp[i]){
            continue;
        }
        for(base = (i*i); base<A; base += (2*i)){
            tmp[base] = true;
        }
    }
    
    for(i = 3;i<A;i+=2){
        if(!tmp[i]){
            //printf("%d ",i);
            count++;
        }
    }
    return count+1;
}
