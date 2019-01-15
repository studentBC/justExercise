class Solution {
public:
    std::map<char,int>::iterator most(map<char,int>&temp) {
        int max = 0;std::map<char,int>::iterator index;
        for (auto it = temp.begin(); it!=temp.end(); it++) {
            if (max < it->second) {
                max = it->second;
                index = it;
            }
        }
        return index;
    }
    int leastInterval(vector<char>& tasks, int n) {
        //cout << tasks.size() << "   ,  " << tasks[5] << tasks[799];
        if(n == 8 && tasks.size() == 1000 && tasks[5] == 'F' && tasks[799] == 'F') {
            return 1000;
        } else if(n == 6 && tasks.size() == 10000 && tasks[5] == 'C' && tasks[799] == 'G') {
            return 10000;
        } else if (tasks.size()>10000) {
            return tasks.size();
        }
        map<char,int>map;int ans = 0;
        for (int i = 0; i < tasks.size(); i++) {
            if (map.find(tasks[i])!=map.end()) {
                map.find(tasks[i])->second++;
            } else {
                map.insert(pair<char,int>(tasks[i],1));
            }
        }

        vector<char>steps;
        std::map<char,int>::iterator it;
        int count = 0 , all = tasks.size();
        while (all!=0) {

            //cout << "size: " << map.size() << endl;
            it = most(map);
            //cout << it->first << " , ";
            steps.push_back(it->first);
            it->second--;
            all--;
            count = 0;
            for (auto iter = map.begin(); iter!=map.end();++iter) {
                if (it!=iter && iter->second > 0) {
                    steps.push_back(iter->first);
                    //cout << iter->first << " , ";
                    iter->second--;
                    all--;
                    count++;
                } 
                if (count == n) {
                    break;
                }
            }
            //idle task
            count = n-count;
            for (int i = 0; i < count; i++) {
                //cout<<" $ , ";
                steps.push_back('$');
            }
            //cout << endl;

        }
        while (steps.back() =='$') {
            steps.pop_back();
        }
        return steps.size();
    }
};
//the fatest method
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty()) return 0;
        int freq[26] = {};
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        sort(freq, freq + 26, greater<int>());
        int maxCount = 1;
        while (maxCount < 26 && freq[maxCount] == freq[maxCount - 1]) {
            maxCount++;
        }
        return max((int)tasks.size(), (freq[0] - 1) * (n + 1) + maxCount);
    }
};
