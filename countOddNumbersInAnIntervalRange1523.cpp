class Solution {
public:
    int countOdds(int low, int high) {
 		int start = low, ans = 0;
		if (start%2 == 0) {
			start++;
		}
		for (;start <= high; start+=2) ans++;
		return ans;
    }
};

//the fatest solution
class Solution {
public:
    int countOdds(int low, int high) 
    {
        return (((high+1)/2) - (low/2));
        
    }
};
