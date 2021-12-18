class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_set<int>visit;
        queue<pair<int, int>>next;
        next.push({start, 0});
        int x, d, ans = INT_MAX;
        while (!next.empty()) {
            x = next.front().first;
            d = next.front().second;
            next.pop();
            if (x == goal) return d;
            if (visit.count(x) || x < 0 || x > 1000) continue;
            visit.insert(x);
            d++;
            for (int i : nums) {
                next.push({x+i, d});
                next.push({x-i, d});
                next.push({x^i, d});
            }
        }
        return ans == INT_MAX?-1: ans;
    }
};
// 8ms solution
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        bool visited[1001] = {};
        
        queue<pair<int, int>> bfs;
        bfs.push({goal, 0}); 
        
        pair<int, int> curr;
        int x, s;
        int y;
        while(!bfs.empty()) {
            curr = bfs.front();
            x = curr.first;
            s = curr.second;
            bfs.pop();
            
            for (int a: nums){
                y = x - a;
                if (0 <= y && y <= 1000) {
                    if (y == start) return s + 1;
                    else if (!visited[y]) {
                        visited[y] = true;
                        bfs.push({y, s + 1});
                    }
                }
                
                y = x + a;
                if (0 <= y && y <= 1000) {
                    if (y == start) return s + 1;
                    else if (!visited[y]) {
                        visited[y] = true;
                        bfs.push({y, s + 1});
                    }
                }
    
                y = x ^ a;
                if (0 <= y && y <= 1000) {
                    if (y == start) return s + 1;
                    else if (!visited[y]) {
                        visited[y] = true;
                        bfs.push({y, s + 1});
                    }
                }
            }
        }
        return -1; 
    }
    
    
};
