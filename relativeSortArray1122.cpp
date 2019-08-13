/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 

Constraints:

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
Each arr2[i] is distinct.
Each arr2[i] is in arr1.

wrong test case:
[28,6,22,8,44,17]
[22,28,8,6]
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int>ansi, temp;
        for (int i = 0; i < arr2.size(); i++) {
			for (int j = 0; j < arr1.size(); j++) {
				if (arr2[i] == arr1[j]) {
					ans.emplace_back(arr1[j]);
					arr1[j] = -1;
				}
			}
		}
		for (int i:arr1) {
			if (i > -1) temp.emplace_back(i);
		}
		sort(temp.begin(), temp.end());
		for (int i:temp) {
			ans.emplace_back(i);
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int k = 0;
        vector<int> cnt(1001);
        vector<int> ans(arr1.size());
        for (int i : arr1) ++cnt[i]; // Count each number in arr1.
        for (int i : arr2) {
            while (cnt[i]-- > 0) ans[k++] = i; // Sort the common numbers in both arrays by the order of arr2
        }
        for (int i = 0; i < 1001; ++i) {
            while (cnt[i]-- > 0) ans[k++] = i; // Sort the numbers only in arr1.
        }
        return ans;
    }
};
// Time & Space O(1001)
