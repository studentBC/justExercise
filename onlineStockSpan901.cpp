class StockSpanner {
public:
    StockSpanner() {
    	data.clear();    
    }
    
    int next(int price) {
		vector<int>pos;
        int count = 1, i = data.size()-1, start = data.size();
		while (i > -1) {
			if (p[i]<=price) {
				count+=(data[i][1]-data[i][0]+1);
				start = data[i][0];
				i = data[i][0]-1;
			} else {
				break;
			}
		}
		p.emplace_back(price);
		pos.emplace_back(start, data.size());
		data.emplace_back(pos);
		return count;
    }
private:
	vector<vector<int>>data;
	vector<int>p;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
//the fatest method
class StockSpanner {
public:
    
    stack<pair<int,int> > stk;
  
    StockSpanner() {
      ios::sync_with_stdio(false);
      cin.tie(0);
    }
    
    int next(int price) {
      
      if(stk.empty())
      {
        stk.push(make_pair(price,1));
        return 1;
      }

      int ans = 1;
      
      while(!stk.empty() && price >= stk.top().first)
      {
        
        ans+=stk.top().second;
        stk.pop();
      }
      
      stk.push(make_pair(price,ans));
      return ans;
      
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
