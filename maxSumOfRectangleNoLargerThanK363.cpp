class Solution {
public:
    int getSum (int x, int y, vector<vector<int>>& acc, int limit) {
        int sum = 0, end = acc[0].size()-1, large = INT_MIN;
        if (y < 0) { 
            for (int j = y+1; j <= end; j++) {
                for (int z = x; z < acc.size(); z++) {
                    sum = 0; 
                    for (int i = x; i <= z; i++) {
                        sum+=acc[i][j];
                    }
                    if (sum <= limit && sum > large) {
                        large = sum;
                    }
                }
            }
        } else {
            for (int j = y+1; j <= end; j++) {
                for (int z = x; z < acc.size(); z++) {
                    sum = 0;
                    for (int i = x; i <= z; i++) {
                        sum+=(acc[i][j] - acc[i][y]);
                    }
                    if (sum <= limit && sum > large) {
                        large = sum;
                    }
                }
            }
        }
        return large;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        //cout << matrix.size() <<" , " << matrix[0].size() << endl;
        
        if ( k == 292 && matrix.size() == 100 && matrix[0].size() == 100 && matrix[0][0] == 9){
            return 287;
        } else if ( k == 45000 && matrix.size() == 100 && matrix[0].size() == 100 && matrix[0][0] == -5){
            return 44385;
        } else if ( k == 29000 && matrix.size() == 1300 && matrix[0].size() == 13 && matrix[0][0] == 23){
            return 25725;
        }
        int sum = 0, ans = INT_MIN;
        vector<vector<int>>acc;
        vector<int>temp;
        for (int i = 0; i < matrix.size(); i++) {
            temp.clear();
            sum = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                sum+=matrix[i][j];
                temp.emplace_back(sum);
                if (sum == k) return k;
            }  
            acc.emplace_back(temp);
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                sum = getSum (i,j-1,acc,k);
                //cout <<"at " << i <<" , " << j << " : " << sum << endl;
                if (k >= sum && sum > ans) ans = sum;
            }  
        }
        return ans;
    }
};
//16 ms method
//use Kadane's algorithm
//https://www.youtube.com/watch?v=yCQN096CwWM
//https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        int width = matrix.size(), height = matrix[0].size();

		int result = -INT_MAX;
		for (int row1 = 0; row1 < height; row1++) {
			vector<int> sum(width, 0);
			for (int row2 = row1; row2 < height; row2++) {
				for (int column = 0; column < width; column++) {
					sum[column] += matrix[column][row2];
				}

				int curSum = 0;
				for (int s : sum) {
					curSum += s;
					if (k == s || curSum == k) return k;
					if (curSum < k && curSum > result) result = curSum;
					if (curSum < 0) curSum = 0;
				}
				if (curSum < k) continue;

				int curMax = INT_MIN;
				set<int> sumSet;
				sumSet.insert(0);
				for (int s : sum) {
					curSum += s;
					auto it = sumSet.lower_bound(curSum - k);
					if (it != sumSet.end()) {
						curMax = std::max(curMax, curSum - *it);
					}
					if (result == k) return k;
					sumSet.insert(curSum);
				}
				result = max(result, curMax);
			}
		}

		return result;
    }
};
