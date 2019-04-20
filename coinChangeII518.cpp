class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>record(amount+1,0);
        record[0] = 1;
        int left;
        for (int i = 0; i < coins.size(); i++) {
            //cout << endl << coins[i] << endl;
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i]) {
                    record[j] += record[j-coins[i]];
                } 
                //cout << record[j] <<" , ";
            }
        }
        return record[amount];
    }
};
