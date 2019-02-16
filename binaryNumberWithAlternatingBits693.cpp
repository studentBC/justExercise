class Solution {
public:
    bool hasAlternatingBits(int n) {
        int start, count = 0 , prev = -1;
        int arr[32] = {0};
        for (int i = 0; i < 32; i++) {
            arr[i] = n>>i&1;
            //cout << arr[i] <<" , ";
        }
        for (int i = 31; i > -1; i--) {
            if (arr[i] == 1) {
                start = i;
                break;
            }
        }
        //cout <<endl << "end at " << start << endl;
        for (int i = 0; i <= start; i++) {
            if (prev == arr[i])return false;
            prev = arr[i];
        }
        return true;
    }
};
