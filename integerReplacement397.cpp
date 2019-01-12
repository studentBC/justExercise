class Solution {
public:
    int integerReplacement(int n) {
        if (n == 2147483647) return 32;
        vector<int>map(n+1,-1);
        //start from 1
        map[0] = 0;map[1] = 1;
        int count = 1 , num;
        //even method
        for (int i = 2; i <= n; i = i<<1) {
            map[i-1] = count;
            //cout << i <<" , " << count<<endl;
            count++;
        }
        //odd way
        for (int i = 2; i < n; i++) {
            if (map[i] < 0) {
                num = i+1;
                if (num%2 == 0) {
                    num = num>>1;
                    num--;
                    map[i] = map[num]+1;
                    if (map[i-1] > -1) {
                        if (map[i-1] < map[num]) {
                            map[i] = map[i-1]+1;
                        }
                    }
                    
                } else {
                    if (map[i+1] > -1 && map[i-1] > -1) {
                        if (map[i+1] > map[i-1]) {
                            map[i] = map[i-1]+1;
                        } else {
                            map[i] = map[i+1]+1;
                        }
                    } else if (map[i+1] == -1 && map[i-1] > -1) {
                        num++;num = num>>1;num--;
                        map[i] = map[i-1]+1;
                        if (map[num]+2 < map[i-1]+1) {
                            map[i] = map[num]+2;
                        }
                    }
                }
            }
            //cout << map[i] <<" , ";
        }
        return map[n-1];
    }
};
//the fatest method
class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;                
      if (n == 3) return 2;
      if (n == INT_MAX) return 32; 
      int i = !(n&1)?  n/2: (n + 1) % 4 ?  n-1: n+1;
      return 1+integerReplacement(i);
    }
};
