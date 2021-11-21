class RangeFreqQuery {
public:
	unordered_map<int,vector<int>>index;
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) index[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        return upper_bound(index[value].begin(), index[value].end(), right) - lower_bound(index[value].begin(), index[value].end(), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
