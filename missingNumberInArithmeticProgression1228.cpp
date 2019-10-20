class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int sum = (arr[0]+arr.back())*(arr.size()+1)/2;
        for (int i = 0; i < arr.size(); i++) sum-=arr[i];
        return sum;
    }
};
