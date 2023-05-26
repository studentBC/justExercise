/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans = -1, big = 0;
    unordered_map<int, Employee*>graph;
    int go (int id) {
        if (graph[id]->subordinates.empty()) return graph[id]->importance;
        int s = 0;
        for (int i : graph[id]->subordinates) {
            s+=go (i);
        }
        graph[id]->importance+=s;
        return graph[id]->importance;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (auto it: employees) {
            graph[it->id] = it;
        }
        return go (id);
    }
};
