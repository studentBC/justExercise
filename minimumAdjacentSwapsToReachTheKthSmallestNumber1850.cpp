class Solution {
public:
    int getMinSwaps(string num, int k) {
        string str = num;
        vector<int>diff;
        int ans = 0, index, len = str.size();
        for (int i = 0; i < k; i++) next_permutation(num.begin(), num.end());
        for (int i = 0; i < len; i++) {
            if (str[i] != num[i]) {
                for (int j = i+1; j < len; j++) {
                    if (str[j] == num[i]) {
                            index = j;
                            ans+=(index-i);
                            for (int j = index; j > i; j--) swap(str[j], str[j-1]);
                            break;
                    }
                }
            }
        }
        return ans;
    }
};
