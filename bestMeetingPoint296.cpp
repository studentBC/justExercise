
Example:

Input: 

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6 

Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance 
             of 2+2+2=6 is minimal. So return 6.

wrong test case:
[[1,1]]

*/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>>group;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    group.emplace_back(make_pair(i,j));
                }
            }
        }
        int ans = INT_MAX, dis;
        for (int i = 0; i < grid.size(); i++) { 
            for (int j = 0; j < grid[i].size(); j++) {
                dis = 0; 
                for (int k = 0; k < group.size(); k++) {
                    dis += (abs(i-group[k].first)+abs(j-group[k].second));
                }
                ans = min(dis,ans);
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int minTotalDistance(vector<int>& rows) {
        if(rows.size() <= 1){
            return 0;
        }
        int left = 0, right = 0;
        int leftSteps = 0, rightSteps = 0;
        for(int i = 1; i < rows.size(); i++){
            right += rows[i];
            rightSteps += rows[i] * i;
        }
        int result = rightSteps;
        for(int i = 1; i < rows.size(); i++){
            rightSteps -=  right;
            right -= rows[i];
            leftSteps += left;
            leftSteps += rows[i-1];
            left += rows[i-1];
            result = min(result, rightSteps + leftSteps);
        }
        return result;
    }
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows(grid.size(), 0);
        vector<int> cols(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j <grid[i].size(); j++){
                if(grid[i][j] == 1){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        return minTotalDistance(rows) + minTotalDistance(cols);
    }
};
//the concept
/*As long as you have different numbers of people on your left and on your right, moving a little to the side with more people decreases the sum of distances. So to minimize it, you must have equally many people on your left and on your right. Same with above/below.

Two O(mn) solutions, both take 2ms.

The neat total += Z[hi--] - Z[lo++]-style summing is from larrywang2014's solution.
Originally I used total += abs(Z[i] - median)-style.

Solution 1

No need to sort the coordinates if we collect them in sorted order.*/

public int minTotalDistance(int[][] grid) {
    int m = grid.length, n = grid[0].length;
    int total = 0, Z[] = new int[m*n];
    for (int dim=0; dim<2; ++dim) {
        int i = 0, j = 0;
        if (dim == 0) {
            for (int x=0; x<n; ++x)
                for (int y=0; y<m; ++y)
                    if (grid[y][x] == 1)
                        Z[j++] = x;
        } else {
            for (int y=0; y<m; ++y)
                for (int g : grid[y])
                    if (g == 1)
                        Z[j++] = y;
        }
        while (i < --j)
            total += Z[j] - Z[i++];
    }
    return total;
}
/*
Solution 2

BucketSort-ish. Count how many people live in each row and each column. Only O(m+n) space.
*/
public int minTotalDistance(int[][] grid) {
    int m = grid.length, n = grid[0].length;
    int[] I = new int[m], J = new int[n];
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            if (grid[i][j] == 1) {
                ++I[i];
                ++J[j];
            }
    int total = 0;
    for (int[] K : new int[][]{ I, J }) {
        int i = 0, j = K.length - 1;
        while (i < j) {
            int k = Math.min(K[i], K[j]);
            total += k * (j - i);
            if ((K[i] -= k) == 0) ++i;
            if ((K[j] -= k) == 0) --j;
        }
    }
    return total;
}
//2014 by larry 
public int minTotalDistance(int[][] grid) {
    int m = grid.length;
    int n = grid[0].length;
    
    List<Integer> I = new ArrayList<>(m);
    List<Integer> J = new ArrayList<>(n);
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                I.add(i);
                J.add(j);
            }
        }
    }
    
    return getMin(I) + getMin(J);
}

private int getMin(List<Integer> list){
    int ret = 0;
    
    Collections.sort(list);
    
    int i = 0;
    int j = list.size() - 1;
    while(i < j){
        ret += list.get(j--) - list.get(i++);
    }
    
    return ret;
}

/*
 Finding the best meeting point in a 2D grid seems difficult. Let us take a step back and solve the 1D case which is much simpler. Notice that the Manhattan distance is the sum of two independent variables. Therefore, once we solve the 1D case, we can solve the 2D case as two independent 1D problems.

Let us look at some 1D examples below:

Case #1: 1-0-0-0-1

Case #2: 0-1-0-1-0
We know the best meeting point must locate somewhere between the left-most and right-most point. For the above two cases, we would select the center point at x=2x = 2x=2 as the best meeting point. How about choosing the mean of all points as the meeting point?

Consider this case:

Case #3: 1-0-0-0-0-0-0-1-1
Using the mean gives us x=(0+7+8)/3=5 as the meeting point. The total distance is 10.

But the best meeting point should be at x=7x = 7x=7 and the total distance is 888.

You may argue that the mean is close to the optimal point. But imagine a larger case with many 1's congregating on the right side and just a single 1 on the left-most side. Using the mean as the meeting point would be far from optimal.

Besides mean, what is a better way to represent the distribution of points? Would median be a better representation? Indeed. In fact, the median must be the optimal meeting point.

Case #4: 1-1-0-0-1
To see why this is so, let us look at case #4 above and choose the median x=1x = 1x=1 as our initial meeting point. Assume that the total distance traveled is d. Note that we have equal number of points distributed to its left and to its right. Now let us move one step to its right where x=2x = 2x=2 and notice how the distance changes accordingly.

Since there are two points to the left of x=2x = 2x=2, we add 2∗(+1)2 * (+1)2∗(+1) to d. And d is offset by –1 since there is one point to the right. This means the distance had overall increased by 1.

Therefore, it is clear that:

As long as there is equal number of points to the left and right of the meeting point, the total distance is minimized.

Case #5: 1-1-0-0-1-1
One may think that the optimal meeting point must fall on one of the 1's. This is true for cases with odd number of 1's, but not necessarily true when there are even number of 1's, just like case #5 does. You can choose any of the x=1x = 1x=1 to x=4x = 4x=4 points and the total distance is minimized. Why?

The implementation is direct. First we collect both the row and column coordinates, sort them and select their middle elements. Then we calculate the total distance as the sum of two independent 1D problems.

public int minTotalDistance(int[][] grid) {
    List<Integer> rows = new ArrayList<>();
    List<Integer> cols = new ArrayList<>();
    for (int row = 0; row < grid.length; row++) {
        for (int col = 0; col < grid[0].length; col++) {
            if (grid[row][col] == 1) {
                rows.add(row);
                cols.add(col);
            }
        }
    }
    int row = rows.get(rows.size() / 2);
    Collections.sort(cols);
    int col = cols.get(cols.size() / 2);
    return minDistance1D(rows, row) + minDistance1D(cols, col);
}

private int minDistance1D(List<Integer> points, int origin) {
    int distance = 0;
    for (int point : points) {
        distance += Math.abs(point - origin);
    }
    return distance;
}
Note that in the code above we do not need to sort rows, why?

Complexity analysis

Time complexity : O(mnlog⁡mn)O(mn \log mn)O(mnlogmn).
Since there could be at most m×nm \times nm×n points, therefore the time complexity is O(mnlog⁡mn)O(mn \log mn)O(mnlogmn) due to sorting.

Space complexity : O(mn)O(mn)O(mn).
 */
