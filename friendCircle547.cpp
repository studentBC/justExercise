
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int* people = (int*)calloc(M.size(),sizeof(int));
        int count = 0 , mark;
        for (int i = 0; i < M.size(); i++) {
            if (people[i]!=0) {
                mark = people[i];
            } else {
                count++;
                mark = count;
            }
            for (int j = 0; j < M[i].size(); j++) {
                if (M[i][j] == 1) {
                    if (people[j] == 0) {
                        people[j] = mark;
                    } else {
                        for (int k = 0; k < M[i].size(); k++) {
                            if (people[j] == people[k]) people[k] = mark;
                        }  
                    }
                }
            }
        }
        for (int i = 0; i < M.size(); i++) {
            if (people[i]!=0) {
                mark = people[i];
            } else {
                count++;
                mark = count;
            }
            for (int j = 0; j < M[i].size(); j++) {
                if (M[i][j] == 1) {
                    if (people[j] == 0) {
                        people[j] = mark;
                    } else {
                        for (int k = 0; k < M[i].size(); k++) {
                            if (people[j] == people[k]) people[k] = mark;
                        }  
                    }
                }
            }
        }
        set<int>ans;
        for (int i = 0; i < M.size(); i++) {
            //cout <<people[i] <<" , ";
            ans.insert(people[i]);
        }
        return ans.size();

    }


};
//fatest method
int static fast = [](){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;}();
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        
        vector<bool> visited(N);
        int count = 0;
        queue<int> q;
        int current;
        
        int j;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                visited[i]=1;
                count++;
                q.push(i);
                
                while(!q.empty()){
                    current=q.front();
                    q.pop();
                    
                    for(j=0;j<N;j++){
                        if(M[current][j]==1 && !visited[j]){
                            visited[j]=1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
};
