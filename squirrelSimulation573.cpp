/*
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.
 Example 1:

 Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12
Note:

All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.

wrong test case:
5
5
[3,2]
[0,1]
[[2,0],[4,1],[0,4],[1,3],[1,0],[3,4],[3,0],[2,3],[0,2],[0,0],[2,2],[4,2],[3,3],[4,4],[4,0],[4,3],[3,1],[2,1],[1,4],[2,4]]
*/
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
 		int smallDis = INT_MAX;
		int td[nuts.size()] = {0};
		int sd[nuts.size()] = {0};
		int ans = INT_MAX, dis, index;
		for (int i = 0; i < nuts.size(); i++) {
			td[i] = abs(tree[0]-nuts[i][0])+abs(tree[1]-nuts[i][1]);
			td[i] = td[i]<<1;
		}
		for (int i = 0; i < nuts.size(); i++) {
			sd[i] = abs(squirrel[0]-nuts[i][0])+abs(squirrel[1]-nuts[i][1]);
		}
		for (int i = 0; i < nuts.size(); i++) {
			dis = td[i]/2+sd[i];
			for (int j = 0; j < nuts.size(); j++) {
				if (i != j) {
					dis+=td[j];
				}
			}
			ans = min(ans, dis);	
		}
		
		return ans;
    }
};
//the fatest method
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        
        int n = nuts.size();
        vector<int> v(n);
        long sum = 0;
        int max_diff = INT_MIN;
        for(int i = 0; i < n; ++i) {
            v[i] = distance(nuts[i], tree)*2;
            max_diff = max(max_diff, v[i]/2 - distance(squirrel, nuts[i]));
            sum += v[i];
        }
        return sum - max_diff;
        // int res = INT_MAX;
        // for(int i = 0; i < n; ++i) {
        //     int x = sum - v[i]/2 + distance(squirrel, nuts[i]);
        //     res = min(res, x);
        // }
        // return res;
    }
    
    int distance(vector<int>& v1, vector<int>& v2) {
        return abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]); 
    }
    
    
};
