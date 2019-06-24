/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int lo = 0;
        int hi = mountainArr.length() - 1;
        int peak, mid, found;
        while (lo < hi) {
            mid = (lo+hi)/2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)) {
                peak = lo = mid+1;
            } else {
                hi = mid;
            }
        }
        //serach left part
        lo = 0;
        hi = peak;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            found = mountainArr.get(mid);
            if (found < target) {
                lo = mid+1;
            } else if (found > target) {
                hi = mid-1;
            } else {
                return mid;
            }
        }
        //serach right part
        lo = peak;
        hi = mountainArr.length() - 1;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            found = mountainArr.get(mid);
            if (found < target) {
                hi = mid-1;
            } else if (found > target) {
                lo = mid+1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

