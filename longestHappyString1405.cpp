class Solution {
private:
    char characts[3] = {'a', 'b', 'c'};
    char getMax(int* arr, int expt) {
        int idx = -1, max = INT_MIN;
        if (expt != 0 && arr[0] > max) {
            idx = 0;
            max = arr[0];
        }
        if (expt != 1 && arr[1] > max) {
            idx = 1;
            max = arr[1];
        }
        if (expt != 2 && arr[2] > max) {
            idx = 2;
            max = arr[2];
        }
        if (max == 0) return ' ';
        arr[idx]--;
        return characts[idx];
    }
public:
    string longestDiverseString(int a, int b, int c) {
        int arr[3] = {a, b, c};
        string ans;
        ans = ans + getMax(arr, -1);
        ans = ans + getMax(arr, -1);
        while (true) {
            int size = ans.size();
            int expt = -1;
            if (ans[size - 1] == ans[size - 2]) {
                expt = ans[size - 1] - 'a';
            }
            char next = getMax(arr, expt);
            if (next == ' ') {
                break;
            }
            ans = ans + next;
        }
        return ans;
    }
};
