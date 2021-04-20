class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int arr2XorSum = 0, tmp, ans = 0;
        for (int i : arr2) arr2XorSum^=i;
        for (int i : arr1) {
            tmp = arr2XorSum&i;
            ans^=tmp;
        }
        return ans;
    }
};
