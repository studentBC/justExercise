class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int width = mat[0].size(), length = mat.size(), sum = 0;
        vector<vector<int>>acc(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++) {
            sum = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                sum+=mat[i][j];
                acc[i][j] = sum;
            }
        }
        for (int l = min(width, length); l > 0; l--) {
            for (int i = 0; i <= length-l; i++) {
                sum = 0;
                for (int a = i,b = 0; b < l; b++,a++) {
                    sum+= acc[a][l-1];
                    if (sum > threshold) break;
                }
                if (sum <= threshold) return l;
                for (int j = l, prev = 0; j < width; j++, prev++) {
                    sum = 0;
                    for (int k = 0, m = i; k < l; k++, m++) {
                        sum+=(acc[m][j]-acc[m][prev]);
                        if (sum > threshold) break;
                    }
                    if (sum <= threshold) return l;
                }
            }
        }
        return 0;
    }

};
//the fatest solution 36 ms solution
class Solution {
    int count_sum(pair<int, int> left, vector<vector<int>>& Prefix, int& side_length){
        if((left.first + side_length - 1 >= (int)Prefix.size()) || (left.second + side_length - 1 >= (int)Prefix[0].size()))
            return INT_MAX;
        else if (left.first == 0 && left.second  == 0)
            return Prefix[left.first + side_length - 1][left.second + side_length - 1];
        else if(left.first == 0)
            return Prefix[left.first + side_length - 1][left.second + side_length - 1] - Prefix[left.first + side_length - 1][left.second - 1];
        else if(left.second == 0)
            return Prefix[left.first + side_length - 1][left.second + side_length - 1] - Prefix[left.first - 1][left.second + side_length - 1];
        else
            return Prefix[left.first + side_length - 1][left.second + side_length - 1] - Prefix[left.first + side_length - 1][left.second - 1] -
                    Prefix[left.first - 1][left.second + side_length - 1] + Prefix[left.first - 1][left.second - 1];
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> Prefix(mat.size(), vector<int>(mat[0].size(), 0));
        Prefix[0][0] = mat[0][0];
        int n = mat.size();
        int m = mat[0].size();
        int result = 0;
        int size = min(m, n);
        for(int i = 1; i < m; i++)
            Prefix[0][i] = Prefix[0][i - 1] + mat[0][i];
        for(int i = 1; i < n; i++)
            Prefix[i][0] = Prefix[i - 1][0] + mat[i][0];
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                Prefix[i][j] = Prefix[i - 1][j] + Prefix[i][j - 1] - Prefix[i - 1][j - 1] + mat[i][j];
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                for(int t = max(result, 1); t <= size; t++)
                {
                    if(count_sum({i, j}, Prefix, t) <= threshold)
                        result = t;
                    else 
                        break;
                }
            }
        }
        return result;
    }
};
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
