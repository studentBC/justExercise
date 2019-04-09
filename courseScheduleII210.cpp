class Solution {
public:
    void go (int start, vector<pair<int, int>>& prerequisites, vector<bool>&visited, vector<int>& ans, bool& cycle, vector<int>& temp) {
        //cout << start<<" , ";
        visited[start] = true;
        temp.push_back(start);
        for (int i = 0; i < prerequisites.size(); i++) {
            if (prerequisites[i].second == start ) {
                //cout << "trying to find " << prerequisites[i].first << endl;
                if (!visited[prerequisites[i].first]) {
                    go (prerequisites[i].first, prerequisites, visited, ans, cycle, temp);
                    temp.pop_back();
                } else { 
                    if ( find(temp.begin() , temp.end(), prerequisites[i].first) != temp.end() || prerequisites[i].first == prerequisites[i].second) {
                        //cout << endl <<  " at " << prerequisites[i].first << " it is not DAG" << endl;
                        cycle = true;
                    }
                }
            }
        }
        ans.push_back(start);
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool>visited(numCourses,false);
        vector<int>ans, temp;
        bool cycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                temp.clear();
                go (i,prerequisites,visited,ans,cycle,temp);
            }
        }
        if (cycle) {
            ans.clear();
            return ans;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> courseNumPrereqsRemaining(numCourses);
        vector<vector<int>> prereqMap(numCourses, vector<int>());
        queue<int> classesToTake;
        
        
        for(int i = 0; i < prerequisites.size(); i++) {
            auto [ course, prereq ] = prerequisites[i];
            
            prereqMap[prereq].push_back(course);
            courseNumPrereqsRemaining[course]++;
        }
        
        
        for(int i = 0; i < numCourses; i++) {
            if(courseNumPrereqsRemaining[i] == 0) {
                classesToTake.push(i);
            }
        }
        
        vector<int> courseOrder;
        
        while(!classesToTake.empty()) {
            auto completedCourse = classesToTake.front();
            classesToTake.pop();
            
            courseOrder.push_back(completedCourse);
            
            auto prereqSatisfiedCourses = prereqMap[completedCourse];
            
            for(auto prereqSatisfiedCourse : prereqSatisfiedCourses) {
                if(--courseNumPrereqsRemaining[prereqSatisfiedCourse] == 0) {
                    classesToTake.push(prereqSatisfiedCourse);
                }
            }
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(courseNumPrereqsRemaining[i] > 0) {
                return vector<int>();
            }
        }
        
        return courseOrder;
    }
};
