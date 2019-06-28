class Solution {
public:
    int getN (int n) {
        if (n == 0) return 1;
        int count = 0;
        while (n > 0) {
            count++;
            n/=10;
        }
        return count;
    }
    void go (int first, int second, int index, string& S, int& reach, vector<int>& ans) {
        if (index == S.size()) {
            reach = 2;return;
        } else if (reach == 1) return;
        long sum = (long)first+(long)second, end = getN(sum)+index;

        //cout <<"start at " << index <<" end at " << end << endl;
        sum = 0;
        for (int i = index; i < S.size() && i < end; i++) {
            sum = sum*10 + (S[i]-'0');
        }  
        if (sum == (long)first + (long)second) {
            //cout <<"sum: " <<  sum << endl;
            ans.emplace_back(sum);
            go (second, sum, end, S, reach, ans);
        } else {
            reach = 1;
        }  
    }
    vector<int> splitIntoFibonacci(string S) {
        int len = S.size()-1, first, second, j, end;
        int reach = 0;
        vector<int>ans;
        for (int i = 1; i < len && i < 9; ++i) {
            end = i+9;
            for (int m = i+1; m < len && m < end; m++) {
                reach = second = first = 0;
                for (j = 0; j < i; j++) {
                    first = first*10+(S[j]-'0');
                }
                for (int k = i; k < m; k++,j++) {
                    second = second*10+(S[j]-'0');
                }
                //cout << i <<" , " << j << " : " << first <<" , " << second << endl;
                ans.emplace_back(first);
                ans.emplace_back(second);
                go (first, second, j, S, reach, ans);
                if (reach == 2) {
                    return ans;
                } else {
                    //cout <<" clear " << endl;
                    ans.clear();
                }
            }
        }
        return ans;
    }
};

