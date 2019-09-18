class Solution {
public:
    Solution(vector<int>& w) {
		discrete_distribution<int> temp(w.begin(), w.end());
		distr = temp;
    }
    
    int pickIndex() {
        return distr(generator);
    }
private:
 	default_random_engine generator;
	discrete_distribution<int> distr
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
int __x__ = []() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 1010;
}();

class Solution {
    vector<double> rec;
    double random_double() { return (double)rand() / (double)RAND_MAX; }

   public:
    Solution(vector<int> &w) {
        rec.resize(w.size());
        int64_t sum = 0;
        for (auto &x : w) {
            sum += x;
        }

        for (int i = 0; i < w.size(); i++) {
            double cur = (double)w[i] / (double)sum;
            rec[i] = cur + (i > 0 ? rec[i - 1] : 0);
        }
    }

    int pickIndex() {
        double r = random_double();
        auto iter = upper_bound(rec.begin(), rec.end(), r);
        return iter - rec.begin();
    }
};
