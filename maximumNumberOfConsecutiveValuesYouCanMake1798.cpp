/*
Because samll values can only discompose to samller numbers,
we sort the input array and check from the small coins.

res means the next value we want to make,
and we can already make 0,1,2,3...res-1.

We iterate the array,
If a > res, all remaining numbers are bigger than res,
we can not make res in all means,
so we break the loop and return res

If a <= res,
we could make from 0 to res - 1,
now with a so we can make from a to res + a - 1,
and a <= res, so our next goal becomes res + a now.
so in this case, we simply res += a
*/
    int getMaximumConsecutive(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 1;
        for (int a: A) {
            if (a > res) break;
            res += a;
        }
        return res;
    }
