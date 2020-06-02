class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
		bool found;
 		for (int i = 0; i < arr.size(); i++) {
			found = false;
			for (int j = 0; j < target.size(); j++) {
				if (arr[i] == target[j]) {
					target[j] = INT_MIN;
					found = true;
					break;
				}
			}
			if (!found) return false;
		}
		return true;
    }
};
//the 12 ms solution
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {//use vector
        vector<int> result(1001,0);
        for(int t:target)result[t]++;
        for(int a:arr)result[a]--;
        for(int r:result)if(r)return false;
        
        return true;
    }
};
