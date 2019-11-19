class Solution {
public:
    void go (string start, unordered_map<string, vector<string>>& graph, string target, vector<string>& temp, vector<string>& path, unordered_set<string>& visit) {
        if (visit.count(start) || visit.count(target)) return;
        visit.insert(start);
        if (start == target) {
            for (string i: temp) {
                path.emplace_back(i);
                //cout << i <<" , ";
            }
            //cout << endl;
        }
        for (int i = 0; i < graph[start].size(); i++) {
            temp.emplace_back(graph[start][i]);
            go (graph[start][i], graph, target, temp, path, visit);
            temp.pop_back();
        }
    }
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, vector<string>>node;
        for (int i = 0; i < regions.size(); i++) {
            for (int j = 1; j < regions[i].size(); j++) {
                node[regions[i][0]].emplace_back(regions[i][j]);
            }
        }
        vector<string>path, temp;
        unordered_set<string>visit;
        path.emplace_back(regions[0][0]);
        go (regions[0][0], node, region1, temp, path, visit);
        vector<string>path1;
        visit.clear();
        temp.clear();
        path1.emplace_back(regions[0][0]);
        go (regions[0][0], node, region2, temp, path1, visit);
        int end = min (path.size(), path1.size());
        //cout << end;
        for (int i = 0; i < end; i++) {
            if (path[i] != path1[i]) {
                return path[i-1];
            }
        }
        return path[end-1];
    }
};
//the fatest solution
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        
        int r1=-1, r2=-1, r1_list, r2_list;
        for (int i = 0; i < regions.size(); i++) { 
            for (int j = 0; j < regions[i].size(); j++){
                if(regions[i][j] == region1){
                    r1  = i;
                }

                if(regions[i][j] == region2){
                    r2 = i;
                }
                
                if( r1!= -1 && r2 != -1)
                    break;
            } 
            
            if(r1!= -1 && r2 != -1)
                break;    
        }   
        
        string head1 = regions[r1][0];
        string head2 = regions[r2][0];
        
        int i;
        
        if(r1 > r2){
            i = r1;
        }
        else {
            i = r2;
        }
            
        
        while(head1 != head2){
            i--;
            
            for(int j=1; j<regions[i].size(); j++){
                
                if(regions[i][j] == head1){
                    head1 = regions[i][0];
                }
                else if(regions[i][j] == head2){
                    head2 = regions[i][0];
                }

                if(head1 == head2)
                    break;
            }
        }
        
        return head1;
        
    }
};
