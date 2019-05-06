class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>prev{1};
        vector<int>cur{1,1};
        if (rowIndex == 0) {
            return prev;
        } else if (rowIndex == 1) {
            return cur;
        }
        prev = cur;
        for (int i = 2; i <= rowIndex; i++) {
            vector<int>temp(i+1,-1);
            temp[i] = temp[0] = 1;
            for (int j = 1; j < i; j++) {
                temp[j] = prev[j-1]+prev[j];
            }
            prev = temp;
        }
        return prev;
    }
};

