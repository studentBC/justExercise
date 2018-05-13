int reverse(int x) {
    bool negative = false;
     if(x<0){
         negative = true;
         x*=-1;
     }else if(x>INT_MAX){
         return 0;
     }
     int ans = 0 ,count = 0,temp = x;
    while(temp>0){
        temp/=10;
        count++;
    }
     count-=1;
     while(x>0){
         ans+=x%10*pow(10,count);
         x/=10;
         count--;
     }  
     if(negative == true){
         if(-ans < 0){
             return -ans;
         }else{
             return 0;
         }
         
     }else if(negative == false && ans > 0){
         return ans;
     }
     return 0;
}
