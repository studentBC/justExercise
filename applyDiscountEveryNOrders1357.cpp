class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        hit = n;
		dis = 1-(discount/100);
		for (int i = 0; i < products.size(); i++) {
			price[products[i]] = prices[i];
		}
    }
    
    double getBill(vector<int> product, vector<int> amount) {
		double bill = 0;
        count++;
		for (int i = 0; i < product.size(); i++) {
			bill+=price[product[i]]*amount[i];
		}
		if (count == hit) {
			count = 0;
			return bill*dis;
		} else return bill;
    }
	int count = 0, hit;
	double dis;
	unordered_map<int,int>price;
	//vector<int>p, price;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
//168 ms solution
// Moustafa
// O(products.length) per query
class Cashier {
private:
    int cost[202], user, win, disc;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        win = n, disc = discount, user = 0;
        for (int i = 0; i < prices.size(); ++i) {
            cost[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> products, vector<int> amount) {
        if (!products.size())
            return 0.0;
        ++user;
        int ans = 0;
        for (int i = 0; i < amount.size(); ++i)
            ans += amount[i] * cost[products[i]];
        double bill = ans;
    	if (user % win == 0)
            bill = bill - bill * disc * 0.01;
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(producs,amount);
 */
