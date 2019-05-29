class Solution {
public:
    bool reorderedPowerOf2(int N) {
		vector<int>candidate{1, 2 , 4 , 8 , 16 , 32 , 64 , 128 , 256 , 512 , 1024 , 2048 , 4096 , 8192 , 16384 , 32768 , 65536 , 131072 , 262144 , 524288 , 1048576 , 2097152 , 4194304 , 8388608 , 16777216 , 33554432 , 67108864 , 134217728 , 268435456 , 536870912 , 1073741824};
		int temp;
		vector<vector<int>>allcandidate;
		for (int i = 0; i < candidate.size(); i++) {
			vector<int>number(10,0);
			temp = vector[i];
			while (temp > 0) {
            	number[temp%10]++;
            	temp/=10;
        	}
			allcandidate.emplace_back(number);
		}
		vector<int>target(10,0);
		while (N > 0) {
            target[N%10]++;
            N/=10;
        }
		bool same;
		for (int i = 0; i < allcandidate.size(); i++) {
			same = true;
			for (int j = 0; j < 10; j++) {
				if (allcandidate[i][j] != target[j]) {
					same = false;
					break;
				}
			}
			if (same) return same;
		}
		return false;
    }
};
//the fatest method
/*
Easy question, 

Approaches
1) Compare powers of 2 with same # digits, check if they're an anagram of N
2) For each power of 2, convert into a string for anagram checking


*/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        auto getdigits = [](int n) {
            vector<int> digits;
            while (n) {
                digits.push_back(n % 10);
                n /= 10;
            }
            sort(digits.begin(), digits.end());
            return digits;
        };
        
        auto isanagram = [&N,&getdigits](int n) {
            string strn = to_string(n), strN = to_string(N);
            sort(strn.begin(), strn.end());
            sort(strN.begin(), strN.end());
            return strn == strN;
        };
        
        int digitCount = 1 + log10(N);
        int pow2 = 1, dcount = 1 + log10(pow2);
        while (dcount <= digitCount) {
            if (dcount == digitCount && isanagram(pow2))
                return true;
            pow2 *= 2;
            dcount = 1 + log10(pow2);
        }
        
        return false;
    }
};
