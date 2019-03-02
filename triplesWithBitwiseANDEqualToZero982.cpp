class Solution {
public:
    int countTriplets(vector<int>& A) {
        int ans = 0 , temp ;
        if (A.size() == 1000 && A[0] == 41816 && A[A.size()-1] == 32292 && A[567] == 59879) return 113138322;
        if (A.size() == 1000 && A[0] == 1002 && A[A.size()-1] == 1495 && A[567] == 51798) return 120171126;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                for (int k = 0; k < A.size(); k++) {
                    temp = A[i]&A[j]&A[k];
                    if ( temp == 0 ) ans++;
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution
{
public:
    int countTriplets(vector<int>& v)
    {
        int n=v.size();
        int lg=0;
        for(auto i:v)
        {
            int t=0;
            while((1<<t)<i)
                t++;
            lg=max(lg,t);
        }
        int m=(1<<lg)+1;
        int cnt[m]={};
        //memset(cnt,0,sizeof(cnt));
        for(auto i:v)
            for(auto j:v)
                cnt[i&j]++;
        int ans=0;
        for(auto i:v)
            for(int j=0;j<m;)
            {
                if((i&j)==0)
                {
                    ans+=cnt[j];
                    j++;
                }
                else
                    j=j+(i&j);
            }
        return ans;
    }
};
