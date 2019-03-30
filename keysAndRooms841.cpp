class Solution {
public:
    void go (int i, int j, vector<vector<int>>& rooms, vector<bool>& visited) {
        if (i >= rooms.size() || j >= rooms[i].size() || visited[rooms[i][j]]) {
            return;
        }
        //cout << rooms[i][j] <<" , " ;
        visited[rooms[i][j]] = true;
        for (int k = 0; k < rooms[rooms[i][j]].size(); k++) {
            go (rooms[i][j], k, rooms, visited);
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),false);
        for (int i = 0; i < rooms[0].size(); i++) {
            go (0,i,rooms,visited);
        }
        
        for (int i = 1; i < visited.size(); i++) {
            if (visited[i] == false) return false;
        }
        return true;
    }
};
