/*
Without loss of generality, we only discuss the scenario when i < j.
below is the discussion about 4 scenarios.

if i < j :
    if arr1[i] > arr1[j]:
        if arr2[i] < arr2[j]:
            value = arr1[i] - arr1[j] + arr2[j] - arr2[i] + j - i
            = (arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j)

        else:
            value = arr1[i] - arr1[j] + arr2[i] - arr2[j] + j - i
            = (arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)

    elif arr1[i] < arr1[j]:
        if arr2[i] < arr2[j]:
            value = arr1[j] - arr1[i] + arr2[j] - arr2[i] + j - i
            = (arr1[j] + arr2[j] + j) - (arr1[i] + arr2[i] + i)
        else:
            value = arr1[j] - arr1[i] + arr2[i] - arr2[j] + j - i
            = (arr1[j] - arr2[j] + j) - (arr1[i] - arr2[i] + i)
Hence, we only need to consider 4 scenarios to get the maximum.
For the first case, we get the maximum of (arr1[i] - arr2[i] - i) and minimum of (arr1[i] - arr2[i] - i), then we subtract maximum with minimum, and get the value of possible maximum for the first case.
Then we get the max of 4 cases and return.
 */
class Solution {
public:
        int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
            int max1 , max2 , max3 , max4 ,min1 , min2 , min3 , min4, tmp1, tmp2, tmp3, tmp4;
            max1 = max2 = max3 = max4 = INT_MIN;
            min1 = min2 = min3 = min4 = INT_MAX;
            for (int i = 0; i < arr1.size(); ++i) {
                tmp1 = arr1[i] - arr2[i] - i;
                max1 = max(max1 , tmp1);
                min1 = min(min1 , tmp1);

                tmp2 = arr1[i] + arr2[i] - i;
                max2 = max(max2 , tmp2);
                min2 = min(min2 , tmp2);

                tmp3 = arr1[i] + arr2[i] + i;
                max3 = max(max3 , tmp3);
                min3 = min(min3 , tmp3);


                tmp4 = arr1[i] - arr2[i] + i;
                max4 = max(max4 , tmp4);
                min4 = min(min4 , tmp4);
            }
            return max(max((max1 - min1), (max2 - min2)),max((max3 - min3),(max4 - min4)));
        }

};
