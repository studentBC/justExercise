static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
std::list<int> *adj;

public:
void AddEdge(int u, int v) {
    adj[u].push_back(v);
}

bool IsCyclic(int i, vector<bool> &processed, vector<bool> &recStack) {
    if(processed[i] == false) {
        processed[i] = true;
        recStack[i] = true;
        std::list<int>::iterator it;
        for(it = adj[i].begin(); it != adj[i].end(); ++it) {
            if(processed[*it] == false) {
                if(IsCyclic(*it, processed, recStack)) {
                    return true;
                }
            }
            else if(recStack[*it]) {
                return true;
            }
        }
    }
    recStack[i] = false;
    return false;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if(prerequisites.size() == 0) {
        return true;
    }
    adj = new list<int>[numCourses];
    bool flag = false;
    int first;
    for(auto &v: prerequisites) {
        if(not flag) {
            first = v.first;
            flag = true;
        }
        AddEdge(v.first, v.second);
    }
    vector<bool> processed(numCourses, false);
    vector<bool> recStack(numCourses, false);
    
    
    for(int i = 0; i < numCourses; ++i) {
        if(IsCyclic(i, processed, recStack)) {
            return false;
        }
    }
    return true;
}
};
//my method
class Solution {
public:
    void go (vector<vector<int>>&map, int target, int* count, bool* ans, int numCourses, bool* mark) {
        count[target]++;
        if (count[target]>1 || !*ans) {
            *ans = false;
            return;
        }
        //cout << target << " its size: " <<  map[target].size() << endl;
        mark[target] = true;
        for (int i = 0; i < map[target].size(); i++) {
            if (i > 0) {
                free(count);
                count = (int*)calloc(numCourses , sizeof(int));
                //for (int j = 0; j < numCourses; j++)count[j] = 0;
                count[target] = 1;
            }
            //if (map[target][i] != INT_MAX) {
              //  map[target][i] = INT_MAX;
                go(map,map[target][i],count,ans,numCourses, mark);  
            //} 
        }
        return;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>map(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            map[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        int* count;
        bool* ans = (bool*)malloc(sizeof(bool));
        bool* mark = (bool*)calloc(numCourses , sizeof(bool));
        //if (!mark[0]) cout << "mark is false" << endl;
        *ans = true;
        for (int i = 0; i < numCourses; i++) {
            if (!mark[i]) {
                count = (int*)calloc(numCourses , sizeof(int));
                go(map,i,count,ans,numCourses, mark);
                //free(count);
            }
        }
        return *ans;
    }
};
