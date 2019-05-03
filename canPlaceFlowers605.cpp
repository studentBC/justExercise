class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int start = 0;
        while ( start < flowerbed.size()) {
            if (flowerbed[start] == 0) {
                if (start+1 < flowerbed.size()) {
                    if (flowerbed[start+1] == 0) {
                        flowerbed[start] = 1;
                        n--;
                        start+=2;
                    } else {
                        start+=3;
                    }
                } else {
                    flowerbed[start] = 1;
                    n--;
                    start+=2;
                }
            } else {
                start+=2;
            }
        }
        return n<=0;
    }
};
//the fatest method
static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n){
		int count=1;
		
		for(int i=0;i<flowerbed.size();i++)
			if(!flowerbed[i]) count++;
			else{
				n-=(count-1)/2;
				count=0;
			}
		n-=count/2;
		
		return n<=0;
	}
};
