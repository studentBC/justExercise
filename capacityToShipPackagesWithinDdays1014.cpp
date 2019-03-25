class Solution {
public:
    int check (int capacity, vector<int>& weights) {
        int date = 0, i = 0, left = capacity, temp;
        while (i<weights.size()) { 
            temp = left-weights[i];
            if (temp > 0) {
                left-=weights[i];
                if (i == weights.size()-1) date++;
                i++;
            } else if (temp == 0) {
                left = capacity;
                i++;
                date++;
            } else {
                left = capacity;
                date++;
            }  
        }
        return date;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        long sum = 0;int ave, mid, days, equal = INT_MAX, lower = INT_MAX, heaviest = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > heaviest) heaviest = weights[i];
            sum+=weights[i]; 
        }
        ave = sum/D;
        ave = max( ave, heaviest);
        while (ave<=sum) {
            mid = ave+(sum-ave)/2;
            days = check (mid, weights);
            //cout <<" capacity is " << mid << " needs " << days << endl;
            if (days > D) {
                ave = mid+1;
            } else if ( days < D) {
                sum = mid-1; 
                if (lower > mid) lower = mid;
            } else if (days == D && equal > mid) {
                sum = mid-1;
                equal = mid;
            }
        }   
        //cout << lower << " , " << equal << endl;
        return min(lower , equal);
    }
};
//the fatest method
class Solution {
public:
    int cnt(vector<int>&W,int k)
    {
        int cn=0,sum=0;
        for(int i=0;i<W.size();i++)
        {
            sum+=W[i];
            if(sum>k)
            {
                sum=W[i];
                cn++;
            }
        }
        if(sum<=k)
            cn++;
        //cout<<" "<<cn<<endl;
        return cn;
    }
    int shipWithinDays(vector<int>& W, int D) {
       int max1=W[0];
        int sum1=0;
        for(int a:W)
        {
            max1=max(a,max1);
            sum1+=a;
        }
        if(D==1)
            return sum1;
        int lo=max1,hi=sum1;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
          //  cout<<mid;
            if(cnt(W,mid)<=D)
                hi=mid;
            else 
                lo=mid+1;
        }
        return lo;
    }
};
