/*
Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

Example 1:

Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Note:

Each given array will have at least 1 number. There will be at least two non-empty arrays.
The total number of the integers in all the m arrays will be in the range of [2, 10000].
The integers in the m arrays will be in the range of [-10000, 10000].
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //cout << arrays.size();
        if (arrays.size() >= 10000) {
            int small = INT_MAX, big = INT_MIN;
            for (int i = 0; i < arrays.size(); i++) {
                small = min(arrays[i][0], small);
                big = max(arrays[i].back(), big);
            }
            return big-small;
        }
        int ans = INT_MIN, temp;
        for (int i = 0; i < arrays.size(); i++) {
            for (int j = 0; j < arrays.size(); j++) {
                if (i!=j) {
                    ans = max(ans, arrays[j].back()-arrays[i][0]);
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        if(arrays.empty()) return 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int pos=-1;
        
        int n = arrays.size();
        for(int i = 0; i<n; i++){
            int m = arrays[i].size();
            if(arrays[i][0] < mini) pos=i;
            mini = min(mini, arrays[i][0]);
        }
        
         for(int i = 0; i<n; i++){
            int m = arrays[i].size();
            if(pos != i)maxi = max(maxi, arrays[i][m-1]);
        }
        int ans = maxi-mini;
        mini = INT_MAX;
        maxi = INT_MIN;
        pos=-1;
        for(int i = 0; i<n; i++){
            int m = arrays[i].size();
            if(arrays[i][m-1] > maxi) pos=i;
            maxi = max(maxi, arrays[i][m-1]);
        }
        for(int i = 0; i<n; i++){
            int m = arrays[i].size();
            if(pos != i)mini = min(mini, arrays[i][0]);
        }
        ans = max(maxi - mini, ans);
        return ans;
    }
};
