/*
Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.

 

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
 

Note:

1 <= items.length <= 1000
items[i].length == 2
The IDs of the students is between 1 to 1000
The score of the students is between 1 to 100
For each student, there are at least 5 scores
*/
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,priority_queue<int>>student;
        for (int i = 0; i < items.size(); i++) {
            student[items[i][0]].push(items[i][1]);
        }
        int sum = 0, count;
        vector<vector<int>>ans;
        for (auto& it:student) {
            count = sum = 0;
            vector<int>temp;
            for (int i = 0; i < 5 && !it.second.empty(); i++,count++) {
                sum+=it.second.top();
                it.second.pop();
            }
            temp.emplace_back(it.first);
            temp.emplace_back(sum/count);
            ans.emplace_back(temp);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> scores;
        vector<vector<int>> return_scores;
        for(vector<int> &score : items) {
            scores[score[0]].push(score[1]);
        }
        for(auto &final_scores : scores) {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += final_scores.second.top();
                final_scores.second.pop();
            }
            return_scores.push_back({final_scores.first, sum/5});
        }
        return return_scores;
    }
};
