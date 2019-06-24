class Solution {
public:
    Solution(int n_rows, int n_cols) {
        srand(time(nullptr));
        row = n_rows; col = n_cols;
    }

    vector<int> flip() {
        int cr, cc;
        string temp;
        do {
            temp = "";
            cr = rand()%row;
            cc = rand()%col;
            temp+=to_string(cr);
            temp+=":";
            temp+=to_string(cc);
        } while(used.find(temp)!=used.end());
		used.insert(temp);
        return {cr,cc};
    }

    void reset() {
        used.clear();
    }
private:
    unordered_set<string>used;
    int row, col;
}; 
   
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
//the fatest method
class Solution {
public:
    Solution(int n_rows, int n_cols) {
        total = n_rows * n_cols;
        rows = n_rows;
        cols = n_cols;
    }
    
    vector<int> flip() {
        int r = rand()%(total--);
        int x = m[r]?m[r]:r;
        m[r]=m[total]?m[total]:total;
        return vector<int>{x/cols, x%cols};
    }
    
    void reset() {
        m.clear();
        total = rows * cols;
    }
private:
    unordered_map<int,int> m;
    int rows, cols, total;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
