/*
Explanation
Scan from y = 0, count the coverage of rectangles on x.
For example, at y = 0, the intervale [0, 3] is covered by rectangles.
The current sum of coverage is 3.

Then we move our scan line upper to next y.
At y = 1, we add (1 - 0) * 3 = 3 to area. Now area = 3.
And we update the sum of coverage to 2 because it's coverd on [0, 2].

Then we move our scan line upper to next y.
At y = 2, we add (2 - 1) * 2 = 2 to area. Now area = 5.
And we update the sum of coverage to 1 because it's coverd on [1, 2].

Then we move our scan line upper to next y.
At y = 3, we add (3 - 2) * 1 = 1 to area. Now area = 6.
And we update the sum of coverage to 0.

The final result is 6.
*/

class Solution {
public:

    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1e9+7;
        vector<int>x;
        for (auto& r: rectangles) {
            x.push_back(r[0]);
            x.push_back(r[2]);
        }
        sort(x.begin(), x.end());
        //remove redundant x
        vector<int>::iterator end_unique = unique(x.begin(), x.end());
        x.erase(end_unique, x.end());
        unordered_map<int, int>xi;
        for (int i = 0; i < x.size(); i++) xi[x[i]] = i;
        vector<vector<int>>line;
        vector<int> count(x.size(), 0);
        for (auto& r: rectangles) {
            line.push_back({r[1], r[0], r[2], 1});
            line.push_back({r[3], r[0], r[2], -1});
        }
        sort(line.begin(), line.end());
        long long cy = 0, cxs = 0, ans = 0;
        for (auto& l : line) {
            long long y = l[0], x1 = l[1], x2 = l[2], sig = l[3];
            ans = (ans+(y-cy)*cxs)%mod;
            cy = y;
            for (int i = xi[x1]; i < xi[x2]; i++) count[i]+=sig;
            cxs = 0;
            for (int i = 0; i < x.size(); i++) {
                if (count[i] > 0) cxs += (x[i+1]-x[i]);
            }
        }
        return ans;
    }
};
/*
Suppose instead of rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]], we had [[0,0,200,200],[100,0,200,300],[100,0,300,100]]. The answer would just be 100 times bigger.

What about if rectangles = [[0,0,2,2],[1,0,2,3],[1,0,30002,1]] ? Only the blue region would have area 30000 instead of 1.

Our idea is this: we'll take all the x and y coordinates, and re-map them to 0, 1, 2, ... etc. For example, if rectangles = [[0,0,200,200],[100,0,200,300],[100,0,300,100]], we could re-map it to [[0,0,2,2],[1,0,2,3],[1,0,3,1]]. Then, we can solve the problem with brute force. However, each region may actually represent some larger area, so we'll need to adjust for that at the end.

Algorithm

Re-map each x coordinate to 0, 1, 2, .... Independently, re-map all y coordinates too.

We then have a problem that can be solved by brute force: for each rectangle with re-mapped coordinates (rx1, ry1, rx2, ry2), we can fill the grid grid[x][y] = True for rx1 <= x < rx2 and ry1 <= y < ry2.

Afterwards, each grid[rx][ry] represents the area (imapx(rx+1) - imapx(rx)) * (imapy(ry+1) - imapy(ry)), where if x got remapped to rx, then imapx(rx) = x ("inverse-map-x of remapped-x equals x"), and similarly for imapy.

class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        N = len(rectangles)
        x_vals, y_vals = set(), set()
        for x1, y1, x2, y2 in rectangles:
            x_vals.add(x1)
            x_vals.add(x2)
            y_vals.add(y1)
            y_vals.add(y2)

        imapx = sorted(x_vals)
        imapy = sorted(y_vals)
        mapx = {x: i for i, x in enumerate(imapx)}
        mapy = {y: i for i, y in enumerate(imapy)}

        grid = [[0] * len(imapy) for _ in imapx]
        for x1, y1, x2, y2 in rectangles:
            for x in range(mapx[x1], mapx[x2]):
                for y in range(mapy[y1], mapy[y2]):
                    grid[x][y] = 1

        ans = 0
        for x, row in enumerate(grid):
            for y, val in enumerate(row):
                if val:
                    ans += (imapx[x+1] - imapx[x]) * (imapy[y+1] - imapy[y])
        return ans % (10**9 + 7)

		*/
