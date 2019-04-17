/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
	void go (int start, vector<Employee*>& employees , map<int,int>& location,  int& ans) {
		auto it = location.find(id);
		ans+=(employees[it->second]->importance);
		for (int i = 0; i < employees[it->second]->subordinates.size(); i++) {
 			go (employees[it->second]->subordinates[i], employees, location, ans);
		}
	}
    int getImportance(vector<Employee*> employees, int id) {
		map<int,int>location; //id , location
		for (int i = 0; i < employees.size(); i++) {
			location.insert(pair<int,int>(employees[i]->id,i));
		}
		auto it = location.begin();
		it = location.find(id);
		int ans = 0;
 		go (id, employees, location, ans);
		return ans;
    }
};
//the fatest method
class Solution {
  unordered_map<int, Employee*> data;
  int getImportance(int id) {
    const auto& employee = data[id];
    int importance = employee->importance;
    for (const auto& subordinateID : employee->subordinates) {
      importance += getImportance(subordinateID);
    }
    return importance;
  };

 public:
  int getImportance(vector<Employee*> employees, int id) {
    for (const auto& employee : employees) {
      data[employee->id] = employee;
    }
    return getImportance(id);
  }
};
