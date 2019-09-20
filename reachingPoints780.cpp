/*
 *
Basic idea:
If we start from sx,sy, it will be hard to find tx, ty.
If we start from tx,ty, we can find only one path to go back to sx, sy.
I cut down one by one at first and I got TLE. So I came up with remainder.

First line:
if 2 target points are still bigger than 2 starting point, we reduce target points.
Second line:
check if we reduce target points to (x, y+kx) or (x+ky, y)

Time complexity
I will say O(logN) where N = max(tx,ty).
 */
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
    	while (ty > sy && tx > sx) {
			if (ty > tx) {
				ty%=tx;
			} else {
				tx%=ty;
			}
		}
		return sx == tx && ty >= sy && (ty-sy)%sx == 0 || ty == sy && tx >= sx && (tx-sx)%sy == 0;
    }
};
