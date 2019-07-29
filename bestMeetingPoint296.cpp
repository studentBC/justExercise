/*
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

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
