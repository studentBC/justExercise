class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        number.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        for (int i = number.size()-1, j = k; i > -1 && j ; i--,j--) ans*=number[i];
        return ans;
    }
    vector<int>number;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
class ProductOfNumbers {
    vector<int> a;
    
public:
    ProductOfNumbers() {
        a.push_back(1);
    }
    
    void add(int num) {
        if (num != 0)
            a.push_back(a.back() * num);
        else {
            a.clear();
            a.push_back(1);
        }
    }
    
    int getProduct(int k) {
        if (a.size() > k)
            return a.back() / a[a.size() - k - 1];
        else
            return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
