class MyCalendar {
public:
    MyCalendar() {
        day.clear();
        return;
    }
    
    bool book(int start, int end) {
        for (auto it = day.begin(); it!= day.end(); it++) {
            if (it->first <= start && start < it->second) {
                return false;
            } else if (start <= it->first && it->first < end) {
                return false;
            }
        }
        day.push_back(pair<int,int>(start,end));
        return true;
    }
private:
    vector<pair<int,int>>day;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
//the fatest method
class MyCalendar {
    map<int, int> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound(s); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books[s] = e;
        return true;
    }
};

