class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
 		vector<int>element;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size();j++) {
				element.push_back(matrix[i][j]);
			}
		}
		sort(element.begin(), element.end());
		return element[k-1];
    }
};
//the fatest method
static
auto unused = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        if(!rows) return 0;
        int cols = matrix[0].size();
        
        int low = matrix[0][0];
        int high = matrix[rows-1][cols-1];
        int mid;
        int count;

        while(low <= high){
            mid = low + (high - low)/2;
            count = getCountLessAndEqual(matrix, mid);
            if(count < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    
    int getCountLessAndEqual(vector<vector<int>>& matrix, int mid){
        int count = 0;
        for(auto v: matrix){
            int distance = upper_bound(v.begin(), v.end(), mid) - v.begin();
            count += distance;
        }
        return count;
    }

};
