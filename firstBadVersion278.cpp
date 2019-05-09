// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, up = n;
        while(low<up) {
            int mid = low+(up-low)/2;
            if (!isBadVersion(mid) && isBadVersion(mid+1)) {
                return mid+1;
            } else if (isBadVersion(mid)) {
                up = mid;
            } else {
                low = mid+1;
            }
        }
        return 1;
    }
};
//the fatest method
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

};
