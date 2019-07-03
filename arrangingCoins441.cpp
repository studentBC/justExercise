class Solution {
public:
    int arrangeCoins(int n) {
 		int ans = 0, count = 1;
		while (n > 0) {
			n-=count;
			count++;ans++;
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    int arrangeCoins(int n) {
        long long int low=0,high=sqrt(n)*2,mid,num=n,ans,prod;
        while(low<=high){
            mid=(low+high)/2;
            prod = (mid*(mid+1))/2;
            if(prod==num){
                ans=mid;
                break;
            }
            else if(prod>num){
                high=mid-1;
                ans=mid-1;
            }
            else low=mid+1;
            //ut<<low<<" "<<high<<" "<<mid<<endl;
        }
        return ans;
    }
};
