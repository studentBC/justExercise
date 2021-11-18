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
