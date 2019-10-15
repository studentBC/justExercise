class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        long long prev = -1;
        int count = 0;
        priority_queue<long long, std::vector<long long>, std::greater<long long> >pq;
        pq.push(1);
        while (count < n) {
            while(!pq.empty() && prev == pq.top()) pq.pop();
            prev = pq.top();
            pq.pop();
            count++;
            for (int j : primes) {
                pq.push(j*prev);
            }
        }
        return prev;

    }
};
//the fatest solution
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        /*
       vector<int>dp(n);
        dp[0] = 1;
        vector<int>p(primes.size());
        for(int i = 1; i < n; i++){
            dp[i] = INT_MAX;
            for(int j = 0; j < p.size(); j++) dp[i] = min(dp[i], dp[p[j]] * primes[j]);
            for(int j = 0; j < p.size(); j++) if(dp[p[j]] * primes[j] == dp[i]) p[j]++;
        }
        return dp[n - 1];*/
        
        int ugly[n], k=primes.size();
        long long factor[k], smallest;
        int idx[k], j;
        for(int i = 0; i < k; ++i){
            factor[i]=primes[i];
            idx[i]=0;
        }
        ugly[0]=1;
        for(int i = 1; i <n; ++i){
            smallest=factor[0];
            j=0;
            for(int i = 1; i < k; ++i){
                if(factor[i]<smallest){
                    smallest=factor[i];
                    j=i;
                }
            }
            ugly[i] = smallest;
            for(int i = j; i < k; ++i){
                if(smallest==factor[i]) factor[i] = primes[i]*ugly[++idx[i]];
            }
        }
        return ugly[n-1];
    }
    
};
