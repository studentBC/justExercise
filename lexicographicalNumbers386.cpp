class Solution {
public:
    int getDigit(int num) {
        int count = 1; 
        while(num>=10) {
            num/=10;
            count++;
        }
        return count;
    }
	int getFirst(int num) {
		while(num>=10) {
            num/=10;
        }
		return num;
	}
    static bool lexical (int i, int j) {
        class Solution sol;
        int fi = sol.getFirst(i);
        int fj = sol.getFirst(j);
        int ci , cj, ni, nj;
        if (fi == fj) {
            ci = sol.getDigit(i);
            cj = sol.getDigit(j);
            if (ci < cj) {
                for (int a = 1; a <= ci; a++) {
                    ni = i/pow(10,ci-a);
                    nj = j/pow(10,cj-a);
                    if (ni != nj) {
                        return (ni<nj);
                    }
                }
                return (ci < cj);
            } else {
                for (int a = 1; a <= cj; a++) {
                    ni = i/pow(10,ci-a);
                    nj = j/pow(10,cj-a);
                    if (ni != nj) {
                        return (ni<nj);
                    }
                }
                return (ci < cj);

            }
        } else {
            return (fi < fj);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(i);
        }
        std::sort(ans.begin(), ans.end(), lexical);
        return ans;
    }
};

