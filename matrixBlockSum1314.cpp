class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>>acc(mat.size(), vector<int>(mat[0].size())), ans(mat.size(), vector<int>(mat[0].size(), 0));
        int sum, left, right, up, down, r = mat[0].size()-1, d = mat.size()-1;
        for (int i = 0; i < mat.size(); i++) {
            sum = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                sum+=mat[i][j];
                acc[i][j] = sum;
            }
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                left = max(j-K, 0);
                right = min (j+K, r);
                up = max(i-K, 0);
                down = min (i+K, d);
                for (int k = up; k <= down; k++) {
                    if (left) ans[i][j]+=acc[k][right]-acc[k][left-1];
                    else ans[i][j]+=acc[k][right];
                }
            }
        }
        return ans;
    }
};
//24 ms solution
template<typename TElem>
class partial_sum_2d {
	vector<vector<TElem>> _ps;
public:
	template<typename Ctnr>
	partial_sum_2d(const Ctnr& data) {
		size_t n = data.size(), m = data[0].size();
		_ps.assign(n + 1, vector<TElem>(m + 1));
		for (size_t i = 0; i < n; ++i)
			for (size_t j = 0; j < m; ++j)
				_ps[i + 1][j + 1] = _ps[i][j + 1] + _ps[i + 1][j] - _ps[i][j] + data[i][j];
	}
	// [left, right), [top, bottom)
	TElem sum(size_t left, size_t top, size_t right, size_t bottom) {
		return _ps[bottom][right] - _ps[bottom][left] - _ps[top][right] + _ps[top][left];
	}
};
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int K) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> r(n, vector<int>(m));
        partial_sum_2d<int> ps(matrix);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                r[i][j] = ps.sum(max(j - K, 0), max(i - K, 0), min(j + K + 1, m), min(i + K + 1, n));
        return r;
    }
};
