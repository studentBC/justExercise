/*
We can track how many frogs are 'singing' each letter in cnt:

Increase number of frogs singing this letter, and decrease number singing previous letter.
When a frog sings 'c', we increase the number of (simultaneous) frogs.
When a frog sings 'k', we decrease the number of (simultaneous) frogs.
If some frog is singing a letter, but no frog sang the previous letter, we return -1.
*/ 
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
 		int move[5]={0};
		int i = 0, ans = 0, count = 0;
		for (char c: croakOfFrogs) {
			if (c == 'c') i = 0;
			else if (c == 'r') i = 1;
			else if (c == 'o') i = 2;
			else if (c == 'a') i = 3;
			else if (c == 'k') i = 4;
			move[i]++;
			if (i == 0) ans = max(ans, ++count);
			else if (i == 4) count--;
			else {
				move[i-1]--;
				if (move[i-1] < 0) return -1;
			}
		}
		return (count == 0)?ans:-1;
    }
};
//the fatest solution
class Solution {
public:
	int minNumberOfFrogs(string cs) {
		ios_base::sync_with_stdio(false);
		int  c=0,r=0,a=0,k=0,o=0,use=0,ans=0;
		for(auto i:cs){
			if(i=='c'){c++; use++;}
			if(i=='r')r++; 
			if(i=='o')o++; 
			if(i=='a')a++; 
			if(i=='k'){k++; use--;}
			ans=max(ans,use);
			if(c<r || r<o || o<a || a<k) return -1;    
		}
		if(c==r && c==o && c==a && c==k) return ans;
		return -1;
	}
};
