/*
Given an array of integers A, return the largest integer that only occurs once.

If no integer occurs once, return -1.

 

Example 1:

Input: [5,7,3,9,4,9,8,3,1]
Output: 8
Explanation: 
The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it's the answer.
Example 2:

Input: [9,9,8,8]
Output: -1
Explanation: 
There is no number that occurs only once.
 

Note:

1 <= A.length <= 2000
0 <= A[i] <= 1000
*/
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
 		sort(A.begin(), A.end());
		int prev = A.back(), count = 1;
		A.insert(A.begin(), -1);
		for (int i = A.size()-2; i > -1; i--) {
			if (A[i]!=prev) {
				if (count == 1) {
					return prev;
				}
				count = 1;
			} else {
				count++;
			}
		}
		return -1;
    }
};
//the fatest method
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int count[1001] = {};
        for(int a : A){
            count[a]++;
        }
        int i = 0;
        for(i = 1000; i >= 0 && count[i] != 1; --i){
            
        }
        return i;
        
    }
};
