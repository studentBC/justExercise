class Solution {
public:
    void go (string start, string end, vector<vector<string>>& equations, vector<double>& values, double& len, double length, bool& found, map<string, bool>& visited) {
        if (found || visited.find(start) == visited.end() || visited[start]) return;
        //cout << start <<" , ";
        if (start == end) {
            len = length;
            found = true;
        }
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][0] == start) {
                visited[start] = true;
                go (equations[i][1], end, equations, values, len, length * values[i], found, visited);
            } else if (equations[i][1] == start) {
                visited[start] = true; 
                go (equations[i][0], end, equations, values, len, length/values[i], found, visited);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        map<string, bool>visited, beenTo;
        double length = 1;
        bool found;
        for (int i = 0; i < equations.size(); ++i) {
            if (visited.find(equations[i][0]) == visited.end()) {
                visited.insert(pair<string,bool>(equations[i][0], false));
            }  
            if (visited.find(equations[i][1]) == visited.end()) {
                visited.insert(pair<string,bool>(equations[i][1], false));
            }
        }
        for (int i = 0; i < queries.size(); ++i) {
            found = false;
            beenTo = visited;
            go (queries[i][0], queries[i][1], equations, values, length, 1, found, beenTo);
            if (found) {
                ans.emplace_back(length);
            } else {
                ans.emplace_back(-1);
            }
            //cout << ans.back() <<endl;
        }
        return ans;
    }
};
//the fatest method
struct Division {
    string to_divide;
    double result;
    Division(const string& t, float r) : to_divide(t), result(r) {}
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        buildGraph(equations, values);
        
        vector<double> result;
        for (const auto& query : queries) {
            result.push_back(search(query[0], query[1]));
        }
        
        return result;
    }
    
private:
    std::unordered_map<string, vector<Division>> graph_;
    
    void buildGraph(const vector<vector<string>>& equations, const vector<double>& values) {
        for (auto i = 0; i < equations.size(); ++i) {
            graph_[equations[i][0]].push_back(Division(equations[i][1], values[i]));
            graph_[equations[i][1]].push_back(Division(equations[i][0], 1/values[i]));
        }
    }
    
    double search(const string& src, const string& dst) {
        if (graph_.find(src) == graph_.end()) {
            return -1.0;
        }
        unordered_set<string> visited;
        std::stack<Division> n_stack;
        n_stack.push(Division(src, 1.0));
        
        while (!n_stack.empty()) {
            auto tmp = n_stack.top();
            n_stack.pop();
            if (tmp.to_divide == dst) {
                return tmp.result;
            }
            
            visited.insert(tmp.to_divide);
            
            for (const auto& d : graph_[tmp.to_divide]) {
                if (visited.find(d.to_divide) == visited.end()) {
                    n_stack.push(Division(d.to_divide, tmp.result*d.result));
                }
            }
        }
        
        return -1.0;
    }
};
