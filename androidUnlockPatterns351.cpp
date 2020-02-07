/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

 

Rules for a valid pattern:

Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.
 


 

Explanation:

| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

 

Example:

Input: m = 1, n = 1
Output: 9

*/
class Solution {
public:
	bool check (vector<int>& pattern, int next) {
		if (find(pattern.begin(), pattern.end(), next)!= pattern.end()) return false;
		int x = abs(position[pattern.back()].first-position[next].first), y = abs(position[pattern.back()].second-position[next].second);
		int diff = x+y;
		if (diff == 1) {
			return true;
		} else if (diff == 4 && find(pattern.begin(), pattern.end(), 5) == pattern.end()) {
			return false;
		} else if (diff == 3) {
			return true;
		} else if (diff == 2) {
            if (x == 1 && y == 1) return true;
			int mid = -1;
			if (y == 2) {
				mid = max(next, pattern.back())-1;
			} else if (x == 2) {
				mid = (next + pattern.back())/2;
			}
			return find(pattern.begin(), pattern.end(), mid) != pattern.end();
		}
		return true;
	}
	void go (int upper, vector<int>& pattern, vector<vector<int>>& next) {
		if (pattern.size() == upper) {
			next.push_back(pattern);
			return;
		}
		for (int i = 1; i < 10; i++) {
			if (check(pattern, i)) {
				pattern.push_back(i);
				go (upper, pattern, next);
				pattern.pop_back();
			}
		}
	}
    int numberOfPatterns(int m, int n) {
		int ans = 9;
		vector<vector<vector<int>>>pattern(9);
		for (int i = 1; i <= 9; i++) {
			vector<int>temp{i};
			pattern[i-1].push_back(temp);
			for (int j = 2; j <= n; j++) {
				vector<vector<int>>next;
                //cout <<"here";
				for (int k = 0; k < pattern[i-1].size(); k++)
					go (j, pattern[i-1][k], next);
                pattern[i-1] = next;
                //cout <<pattern[i-1].size() << " , ";
				if (j >= m) ans+=pattern[i-1].size();
			}
		}
        if (m > 1) return ans-9;
		return ans;
    }
	vector<pair<int,int>>position{{99,99},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
};
//the fatest solution
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        auto g = array<array<int, 10>, 10>{};
        g[1][3] = g[3][1] = 2;
        g[1][7] = g[7][1] = 4;
        g[1][9] = g[9][1] = 5;
        g[3][9] = g[9][3] = 6;
        g[3][7] = g[7][3] = 5;
        g[7][9] = g[9][7] = 8;
        g[2][8] = g[8][2] = g[4][6] = g[6][4] = 5;
        auto visited = array<bool, 10>{};
         
        return 4 * dfs(1, m, n, g, visited, 0) + 4 * dfs(2, m, n, g, visited, 0) + dfs(5, m, n, g, visited, 0);
    }
    
    int dfs(int num, int m, int n, const array<array<int, 10>, 10>& g, array<bool, 10>& visited, int len)
    {
        visited[num] = true;
        ++len;
        auto count = len >= m && len <= n ? 1 : 0;
        if (len < n)
        {
            for (int i = 1; i <= 9; ++i)
            {
                if (!visited[i] && (g[num][i] == 0 || visited[g[num][i]]))
                {
                    count += dfs(i, m, n, g, visited, len);
                }
            }
        }
        visited[num] = false;
        return count;
    }
};
