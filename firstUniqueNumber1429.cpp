class FirstUnique {
public:
    unordered_map<int,int>count;
    vector<int>number;
    int start = 0;
    FirstUnique(vector<int>& nums) {
        for (int i: nums) {
            count[i]++;
            if (count[i] == 1) {
                number.push_back(i);
            }
        }
    }
   
    int showFirstUnique() {
        for (int i = start; i < number.size(); ++i) {
            if (count[number[i]] == 1) {
                start = i;
                return number[i];
            }
        }
        return -1;
    }

    void add(int value) {
        count[value]++;
        if (count[value] == 1) number.push_back(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
//the 340 ms solution
class FirstUnique {
private:
    unsigned char seen[100000000/5] = {0,};
    queue<int> q;
    const unsigned char pow3[5] = {1, 3, 9, 27, 81};
    
    unsigned char saw (int n) {
        return (seen[n/5] / pow3[n%5]) % 3;
    }
public:
    FirstUnique(const vector<int>& nums) {
        for (const auto x: nums) add(x);
    }
    
    int showFirstUnique() {
        while (!q.empty() && saw(q.front()) == 2) q.pop();
        if (q.empty()) return -1;
        return q.front();
    }
    
    void add(const int value) {
        const unsigned char s = saw(value);
        
        if (s == 2) return;
        if (s == 0)
            q.push(value);
        seen[value/5] += pow3[value%5];
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

static int faster=[](){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 13;}();
