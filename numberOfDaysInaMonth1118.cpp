/*
Given a year Y and a month M, return how many days there are in that month.

Example 1:

Input: Y = 1992, M = 7
Output: 31
Example 2:

Input: Y = 2000, M = 2
Output: 29
Example 3:

Input: Y = 1900, M = 2
Output: 28
 

Note:

1583 <= Y <= 2100
1 <= M <= 12
*/
class Solution {
public:
    int numberOfDays(int Y, int M) {
  		if (M == 2) {
			if ((Y % 4 == 0 and Y % 100 != 0) or (Y % 400 == 0 and Y % 3200 != 0)) {
				return 29;
			} else {
				return 28;
			}
		} else if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
			return 31;
		} else {
			return 30;
		}
    }
};
//the fatest method
class Solution
{
private:
    int D[24] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    
public:
    int numberOfDays(int Y, int M)
    {   
        int i = 0;
        
        if (Y % 100)
        {
            if ((Y & 3) == 0)
                i += 12;
        }
        else if (Y % 400 == 0)
            i += 12;
        
        return D[i + M - 1];
    }
};
