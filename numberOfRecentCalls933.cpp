class RecentCounter {
public:
    RecentCounter() {
		
    }
    
    int ping(int t) {
        time.emplace_back(t);
		int limit = t-3000, count = 0;
		for (int i = left; i < time.size(); i++) {
			if (time[i] < limit) {
				left++;
			} else {
				break;
			}
		}
		return time.size()-left+1;
    }
private:
	vector<int>time;
	int left = 0;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
//132 ms solution
static const auto optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() : q() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (t - q.front() > 3000)
            q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
