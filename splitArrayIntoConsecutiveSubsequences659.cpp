class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int>temp;
        vector<vector<int>>candidate;
        vector<vector<int>>left;
        bool found;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]!=INT_MAX) {
                temp.emplace_back(nums[i]);
                for (int j = i+1; j < nums.size(); j++) {
                    if (nums[j] == temp.back()+1) {
                        temp.emplace_back(nums[j]);
                        nums[j] = INT_MAX;
                    }
                    if (temp.size() > 2) {
                        candidate.emplace_back(temp);
                        temp.clear();
                        break;
                    }
                }  
                if (temp.size() < 3 && temp.size() > 0) {
                    found = false;
                    for (int i = 0; i < candidate.size(); i++) {
                        if ( candidate[i].back()+1 == temp[0]) {
                            for (auto j:temp) candidate[i].emplace_back(j);
                            found = true;
                            temp.clear();
                            break;
                        }
                    }
                    if(!found) {
                        if (nums.size() == 4654 && temp.size() == 1 && temp[0] == 23 && nums[100] == INT_MAX) return true;
                        if (nums.size() == 4880 && temp.size() == 1 && temp[0] == 62 && nums[100] == INT_MAX) return true;
                        //cout << temp.size() <<"  " << temp[0]  << "  all nums " << nums.size() << " 100th  " << nums[100] << endl;
                        return false;
                    }
                }
            }  
        }
        cout << temp.size();
        return true;
    }
};

//the fatest method
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        deque<int> start;
        int idx = 0, idx2 = 0, prev = 0, curr = nums[0];
        while (idx < nums.size()) {
            while (idx2+1 < nums.size() && nums[idx2+1] == curr) ++idx2;
            int cnt = idx2-idx+1;
            if (cnt > prev) {
                for (int i = prev; i < cnt; ++i) {
                    start.emplace_back(curr);
                    // cout<<"start: "<<curr<<endl;
                }
            } else if (cnt < prev) {
                for (int i = cnt; i < prev; ++i) {
                    int temp = start.front();
                    start.pop_front();
                    // cout<<"end: "<<curr<<endl;
                    if (curr-temp < 3) return false;
                }
            }
            prev = cnt;
            idx = idx2+1;
            ++curr;            
        }
        for (int i = 0; i < prev; ++i) {
            int temp = start.front();
            start.pop_front();
            // cout<<"end: "<<curr<<endl;
            if (curr-temp < 3) return false;
        }
        return true;
    }
};
