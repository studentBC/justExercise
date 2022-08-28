class StockPrice {
public:
    int cur = -1, p = -1;
    map<int, unordered_set<int>>pt; //price timestamp
    unordered_map<int, int>tp;// timestamp price
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (cur <= timestamp) {
            cur = timestamp;
            p = price;
        } 
        
        if (tp.count(timestamp) && pt.count(tp[timestamp])  && pt[tp[timestamp]].count(timestamp)) {
            //the bug is that we still need to keep every legal price and timestamp so that we can get the correct value
            pt[tp[timestamp]].erase(timestamp);
            if (pt[tp[timestamp]].empty()) pt.erase(tp[timestamp]);
            pt[price].insert(timestamp);
        }
        tp[timestamp] = price;
        
        pt[price].insert(timestamp);
        
    }
    
    int current() {
        return p;
    }
    
    int maximum() {
        for (auto it = pt.rbegin(); it != pt.rend(); it++) {
            
            return it->first;
        }
        return 0;
    }
    
    int minimum() {
        for (auto& it : pt) {
            //cout << it.second <<", ";
            return it.first;
        }
        return -1;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
class StockPrice {
public:
	map<int,int>sp;
	multiset<int>p;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if (sp.count(timestamp)) p.erase(p.find(sp[timestamp]));
		sp[timestamp] = price;
		p.insert(price);
    }
    
    int current() {
        return sp.rbegin()->second;
    }
    
    int maximum() {
        return *p.rbegin();
    }
    
    int minimum() {
        return *p.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
