//to be honest this is a clever method and fatest 
//it buy and sell stock at the same day but i dont know why can be this?
int maxProfit(int* prices, int pricesSize) {
    int sum = 0,i;
    for (i = 0; i < pricesSize-1;i++) {
        if (prices[i+1]>prices[i]) {
            sum+=(prices[i+1]-prices[i]);
        }
    }
    return sum;
}
