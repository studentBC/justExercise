class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>ans(n,0);
        vector<int>id;
        vector<int>time;
        vector<char>isstart;
        int start, end, ID, t;
        string pos,temp;
        vector<bool>used(1e8, false);
        //cout << logs.size() << endl;
        for (string s:logs) {
            istringstream ss(s);
            getline(ss,temp,':');
            ID = stoi(temp);
            temp = "";
            getline(ss,temp,':');
            pos = temp;
            temp = "";
            getline(ss,temp,':');
            t = stoi(temp);
            if (pos.compare("start") == 0) {
                id.emplace_back(ID);
                time.emplace_back(t);
            } else {
                for (int i = time.back(); i <= t; ++i) {
                    if (!used[i]) {
                        ans[ID]++;
                        used[i] = true;
                    }
                }
                id.pop_back();time.pop_back();
            }
        }

        return ans;
    }
};
//8 ms solution
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        std::vector<int> res(n,0);
        std::stack<std::pair<int,int>> log_stack;
        for(auto &str:logs){
            int index = 0;
            int id = 0;
            int len = str.size();
            int flag = true;
            while(isdigit(str[index])){
                id = id*10 + str[index] - '0';
                index++;
            }
            index++;
            if(str[index]=='s'){ 
                index += 6;
            }else{
                flag = false;
                index += 4;
            }
            
            int time = 0;
            while(index<len){
                time = time*10 + str[index] - '0';
                index++;
            }
            
            if(flag){
                if(!log_stack.empty()){
                    int last_id = log_stack.top().first;
                    int start = log_stack.top().second;
                    res[last_id] += time - start;
                }
                log_stack.push({id,time});
            }else{
                int satrt = log_stack.top().second;
                res[id] += time - satrt + 1;
                log_stack.pop();
                if(!log_stack.empty()){
                    log_stack.top().second = time + 1;
                }
            }
            
        }
        return res;
    }
};

