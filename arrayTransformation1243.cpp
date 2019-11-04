class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int end = arr.size()-1;
        bool same = true;
        do {
            same = true;
            vector<int>prev (arr.begin(), arr.end());
            for (int i = 1; i < end; i++) {
                if (prev[i] < prev[i+1] && prev[i] < prev[i-1]) {
                    arr[i]++;
                    same = false;
                } else if (prev[i] > prev[i+1] && prev[i] > prev[i-1]) {
                    arr[i]--;
                    same = false;
                }
            }
        } while (!same);
        return arr;
    }
};

