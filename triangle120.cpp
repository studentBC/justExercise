class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>temp(triangle.size());
        for (int i = 0; i < triangle.size(); i++) {
            temp[i] = vector<int>(triangle[i].size());
        }
        for (int i = triangle.size()-1; i > -1 ; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (first) {
                    temp[i][j] = triangle[i][j];
                } else {
                    //if (j == 0) {
                        temp[i][j] = min(temp[i+1][j],temp[i+1][j+1]) + triangle[i][j];
                    //} else if (j == triangle[i].size()-1) {
                    //    temp[i][j] = min(temp[i+1][j],temp[i+1][j-1]) + triangle[i][j];
                    //} else {
                    //    mini = min(temp[i+1][j],temp[i+1][j-1]);
                    //    temp[i][j] = min(mini, temp[i+1][j+1]) + triangle[i][j];
                    //}
                }
                //cout << "( " << i <<" , " << j <<" ) : " << temp[i][j] << endl;
            }
        }
        
        return temp[0][0];

    }
};
//the fatest method
static const auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const int m = triangle.size();
        vector<int> dp(m+1, INT_MAX);
        dp[1] = triangle[0][0];
        for (int i = 1;i<m;++i){
           for(int j = i;j>=0;--j){
               dp[j+1] = std::min(dp[j+1], dp[j]) + triangle[i][j];
           } 
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};
