class MyCalendarTwo {
public:
    bool book(int start, int end) {
        for (auto i : overlap) {
            if (start < i.second && i.first < end) return false;
        }        
        for (auto i : schedule) {
            if (start < i.second && i.first < end) {
                overlap.push_back({max(i.first,start),min(i.second,end)});
            }
        }        
        schedule.push_back({start,end});
        return true;
    }
    
    vector<pair<int,int>> schedule, overlap;
};

static auto x = [] {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        day.clear();
        return;
    }

    bool book(int start, int end) {
        //cout << start <<" , " << end << endl;
        int count = 0;
        vector<int>repeat;
        for (int i = 0; i < day.size(); i++) {
            if (day[i].first >= end || day[i].second <= start) {

            } else  {
                //cout <<"intersect with " << day[i].first <<" , " << day[i].second << endl;
                repeat.emplace_back(i);
                count++;
            }
        }
        //cout << count << endl;
        if (count < 2) {
            day.push_back(pair<int,int>(start,end));
            return true;
        } else {
            for (int i = 0; i < repeat.size(); i++) {
                for (int j = i+1; j < repeat.size(); j++) {
                    if (day[repeat[j]].first >= day[repeat[i]].second || day[repeat[j]].second <= day[repeat[i]].first) {

                    } else  {
                        return false;
                    }
                }
            }
            day.push_back(pair<int,int>(start,end));
            return true;
        }
    }
private:
    vector<pair<int,int>>day;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
