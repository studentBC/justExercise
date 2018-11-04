//my method only beat 52%
class Solution {
public:
    bool match(pair<int, int>person , int front, vector<pair<int, int>>& candidate) {
        int count = 0;
        for (int i = 0; i < front; i++) {
            if (get<0>(person) <= get<0>(candidate[i])) {
                count++;
            }
        }
        if (front >= get<1>(person) && count == get<1>(person)) {
            return true;
        } else {
            return false;
        }
    
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
       int len = people.size();
       int front = 0 , height = INT_MAX;
       int chosen;
       vector<pair<int, int>>ans;
       pair<int, int>candidate;
       for (int i = 0; i < len; i++) {
            for (int j = 0; j < people.size(); j++) {
                if (match(people[j],front,ans)) {
                    //cout << i << ":    " << get<0>(people[j]) <<" , " << get<1>(people[j]) << endl;
                    if (height > get<0>(people[j])) {
                        height = people[j].first;
                        candidate = people[j];
                        chosen = j;
                    }
                }
            }

          
            people.erase(people.begin() + chosen);
            front++;
            //cout << "candidate: "  << get<0>(candidate) << "  ,   " <<  get<1>(candidate) << endl;
            ans.push_back(candidate);
            height = INT_MAX;
       }
        return ans;
    }

};
//others simple method
 sort(people.begin(), people.end(), [] (const pair<int,  int> p1, const pair<int,  int> p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    });
    
    for (int i = 0; i < people.size(); i++) {
        if (i != people[i].second) {
            int height = people[i].first;
            int num = people[i].second;
            for (int j = i; j >= num;j-- ) {
                people[j] = people[j-1];
            }
            people[num].first = height;
            people[num].second = num;
        }
    }

//another people solution
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        auto HdescendingKascending = [](pair<int, int>& a, pair<int, int> b)
        {
            // return true when you want to put a in front of b.
            
            if (a.first > b.first) 
            {
                // tallest first. "h" descending
                return true;
            }
            else
            if (a.first == b.first &&
                a.second < b.second)
            {
                // for same height, put people with smaller "k" first. "k" ascending
                return true;
            }

            return false;                
        };

        sort(people.begin(),
             people.end(),
             HdescendingKascending);
        
        
        vector<pair<int, int>> res;
        for (auto &e : people)
        {
            cout<<e.first<<":"<<e.second<<endl;
            res.insert(res.begin() + e.second, e);
        }
        
        return res;
    }
