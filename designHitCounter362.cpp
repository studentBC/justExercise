/*
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:

HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?

wrong test case:
["HitCounter","hit","hit","hit","getHits","getHits","getHits","getHits","getHits","hit","getHits"]
[[],[2],[3],[4],[300],[301],[302],[303],[304],[501],[600]]
*/
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        tp.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int start = timestamp - 300;
        while (!tp.empty() && tp.front() <= start) {
            tp.pop();
        }
        return tp.size();
    }
private:
    int earliest = 1;
    queue<int>tp;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
//the fatest method
class HitCounter {
// private:
    list<pair<int,int>> hit_count;
    int total;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        total = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while (!hit_count.empty() && timestamp - hit_count.front().first >= 300) {
            total -= hit_count.front().second;
            hit_count.pop_front();
        }
        if (hit_count.empty() || hit_count.back().first != timestamp)
            hit_count.push_back({timestamp, 1});
        else
            hit_count.back().second++;
        total++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!hit_count.empty() && timestamp - hit_count.front().first >= 300) {
            total -= hit_count.front().second;
            hit_count.pop_front();
        }
        return total;
    }
};
/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
