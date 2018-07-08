#define MIN(A, B) ((A) <= (B) ? (A) : (B))
#define MAX(A, B) ((A) >= (B) ? (A) : (B))

int maxProfit(int* prices, int n) {
    if (n < 2) return 0;
    int max = 0, min = prices[0];
    for (int i = 1; i < n; ++i) {
        int price = prices[i];
        max = MAX(max, price-min);
        min = MIN(min, price);
    }
    return max;
}
//my method
int maxProfit(int* prices, int pricesSize) {
    int i ,j,maxp=-99;
    if(pricesSize == 0){
        return 0;
    }
    int max[pricesSize];
    for (i = 0; i < pricesSize;i++){
        maxp = -99;
        max[i] = 0;
        for(j = i+1;j<pricesSize;j++){
            if (prices[i] < prices[j]) {
                maxp = prices[j] - prices[i];
            }
            if (maxp > max[i]){
                max[i] = maxp;
            }
        }
    }
    maxp = 0;
    for (i = 0; i < pricesSize;i++) {
        if (max[i] > maxp){
            maxp = max[i];
        }
    }
    return maxp;
}
