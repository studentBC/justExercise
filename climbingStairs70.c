double factorial(int one , int two) {
    int total = one+two;
    double dividend = 1 , divisor = 1;
    if (one > two) {
        for (int i = total; i > one; i--) {
            dividend*=i;
        }
        for (int i = two;i>0;i--) {
            divisor*=i;
        }
        //printf("1: %d \n",dividend/divisor);
        return dividend/divisor;
    } else {
        for (int i = total; i > two; i--) {
            dividend*=i;
        }
        for (int i = one; i>0;i--) {
            divisor*=i;
        }
        //printf("2: %d \n",dividend/divisor);
        return dividend/divisor;
    }
    
}
int climbStairs(int n) {
    int numberOftwo = n/2;
    int numberOfone = n%2;
    int total = 1;
    while(numberOftwo > 0) {
        if (numberOfone!=0 && numberOftwo !=0){
            total+=factorial( numberOfone , numberOftwo);
        } else if(numberOfone == 0 || numberOftwo ==0){
            total+=1;
        }
        
        //printf("2 is %d 1 is %d total is %d \n",numberOftwo ,numberOfone ,total);
        numberOftwo--;
        numberOfone = n-numberOftwo*2;
    }
    return total;
}
