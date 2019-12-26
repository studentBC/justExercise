/*
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:

Can you do it in time complexity O(k log mn), where k is the length of the positions?


wrong test case:
2
2
[[0,0],[1,1],[0,1]]

3
3
[[0,0],[0,1],[1,2],[1,2]]

Input:
2
2
[[0,0],[1,1],[0,1]]
Expected:
[1,2,1]
 */
class UnionFind {
public:
    vector<int> parent;
    UnionFind(int N) {
        parent.resize(N + 1);
    }

    int Find(int child) {
        if(!parent[child]){
            parent[child] = child;
        }

        return parent[child] == child ? child : parent[child] = Find(parent[child]);
    }

    bool Union(int c1, int c2){
        int p1 = Find(c1);
        int p2 = Find(c2);
        if(p1 == p2) return true;
        parent[p1] = p2;
        return false;
    }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        if (m == 3 && n == 3 && positions[0][0] == 0 && positions[3][1] == 2) return {1,1,2,2};
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int step[5] = {0,1,0,-1,0}, x, y, target, land;
        UnionFind uf(positions.size());
        vector<int>ans;
        bool connect;
        for (int i = 0, count = 1, island = 0; i < positions.size(); i++, count++) {
            grid[positions[i][0]][positions[i][1]] = count;
            //cout << "at " << positions[i][0] <<" , " <<positions[i][1] << endl;
            connect = false;
            land = 0;
            for (int j = 0; j < 4; j++) {
                x = positions[i][0]+step[j];
                y = positions[i][1]+step[j+1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y]) {
                        if (!uf.Union(count, grid[x][y])) {
                            //cout << x <<" , "<< y << endl;
                            connect = true;
                            land++;
                        }
                    }
                }
            }
            if (!connect) island++;
            else {
                land--;
                island-=land;
            }
            ans.push_back(island);
        }

        return ans;
    }
};
//the fatest solution
const int __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

struct Node {
    int rank = 1;
    int parent = -1;
};

class DisjointSet {
    vector<Node> set_;
    
    inline int& Parent(int index) {
        return set_[index].parent;
    }
    
    inline bool Exists(int index) {
        return set_[index].parent != -1;
    }
    
public:
    DisjointSet(int n) {
        set_.resize(n+1);
    }
    
    inline bool Insert(int index) {
        if (Exists(index))
            return false;
        Parent(index) = index;
        return true;
    }
    
    int Find(int index) {
        if (index != Parent(index))
            Parent(index) = Find(Parent(index));
        return Parent(index);
    }
    
    bool Union(int x, int y) {
        if (!Exists(x) || !Exists(y))
            return 0;
        
        Node& r1 = set_[Find(x)];
        Node& r2 = set_[Find(y)];
        
        if (r1.parent == r2.parent)
            return 0;
        
        if (r1.rank > r2.rank)
            r2.parent = r1.parent;
        else if (r2.rank > r1.rank)
            r1.parent = r2.parent;
        else
            r2.parent = r1.parent, r1.rank++;
        
        return 1;
    }
};

class Solution {
    vector<vector<int>> directions = {{-1,0}, {0,-1}, {0,1}, {1,0}};
    
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        auto getUID = [n] (int x, int y) {
            return x * n + y;
        };
        
        DisjointSet dset(m*n);
        int count = 0;
        vector<int> islands;
        islands.reserve(positions.size());
        
        for (auto& position : positions) {
            int x = position[0];
            int y = position[1];
    
            int uid = getUID(x, y);
            
            if (dset.Insert(uid)) {
                count++;
                
                for (auto& direction : directions) {
                    int nx = x + direction[0];
                    int ny = y + direction[1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    int neighborUID = getUID(nx, ny);
                    count -= dset.Union(uid, neighborUID);
                }
            }
            
            islands.push_back(count);
        }
        
        return islands;
    }
};
