int coinChange(int* coins, int coinsSize, int amount) {
     int change[amount+1];
     change[0] = 0;
     int min = INT_MAX;
     int left;
     for (int i = 1; i <= amount; i++) {
         min = INT_MAX;
         for (int j = 0; j < coinsSize; j++ ) {
             if (i >= coins[j]) {
                 left = change[i-coins[j]];
                 if (left < min) {
                     min = 1+left;
                 }
             }
         }
         change[i] = min;
     }
     if (change[amount] == INT_MAX) {
         return -1;
     }  
     return change[amount];
}
