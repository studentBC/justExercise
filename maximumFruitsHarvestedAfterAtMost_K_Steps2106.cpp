class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
  		int len = fruits.size(), right = max(fruits[len-1][0], startPos), ans = 0;
		vector<int>point(right+1, 0);
		for (auto& it: fruits) point[it[0]] = it[1];
		vector<int>sum(right+2, 0);
		for (int i = 0; i <= right; i++) sum[i+1] = sum[i]+point[i];
		int lmax, lpos, rmax, rpos;
		for (int i = 0; i <= min(k, right-startPos); i++) {
			lmax = max(0, k-2*i);
			lpos = max(0, startPos-lmax);
			rpos = startPos+i;
			ans = max(ans, sum[rpos+1]-sum[lpos]);
		}
		for (int i = 0; i <= min(k, startPos); i++) {
			rmax = max(0, k-2*i);
			lpos = startPos-i;
			rpos = min(right, startPos+rmax);
			ans = max(ans, sum[rpos+1]-sum[lpos]);
		}
		return ans;

    }
};


// 264 ms solution
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=(int)fruits.size();
        vector<int> prefix(n);
        for(int i=0; i<n; i++) {
            if(i) {
                prefix[i]=prefix[i-1];
            }
            prefix[i]+=fruits[i][1];
        }
        int ans=0, right=n;
        for(int i=0; i<n; i++) {
            if(fruits[i][0]>startPos) {
                right=i;
                break;
            }
        }
        for(int i=0; i<n && fruits[i][0]<=startPos; i++) {
            if(startPos-fruits[i][0]<=k) {
                int rem=k-(startPos-fruits[i][0]);
                while(right<n && fruits[right][0]-fruits[i][0]<=rem) {
                    right++;
                }
                int offer=prefix[right-1];
                if(i) {
                    offer-=prefix[i-1];
                }
                ans=max(ans, offer);
            }
        }
        int left=-1;
        for(int i=n-1; i>=0; i--) {
            if(fruits[i][0]<startPos) {
                left=i;
                break;
            }
        }
        for(int i=n-1; i>=0 && fruits[i][0]>=startPos; i--) {
            if(fruits[i][0]-startPos<=k) {
                int rem=k-(fruits[i][0]-startPos);
                while(left>=0 && fruits[i][0]-fruits[left][0]<=rem) {
                    left--;
                }
                int offer=prefix[i];
                if(left>=0) {
                    offer-=prefix[left];
                }
                ans=max(ans, offer);
            }
        }
        return ans;
    }
};
