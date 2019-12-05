class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double** champagne = new double* [query_row+1];
        double crammed;
        bool found;
        for (int i = 0; i <= query_row; i++) champagne[i] = new double[i+1]();
        champagne[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j < i+1; j++) {
                if (champagne[i][j] > 1) {
                    crammed = (champagne[i][j]-1)/2;
                    champagne[i][j] = 1;
                    if (i+1 <= query_row) {
                        champagne[i+1][j]+=crammed;
                        champagne[i+1][j+1]+=crammed;
                    }
                }
            }
        }
        return champagne[query_row][query_glass];
    }
};
//the fatest solution
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double result[101][101] = {0.0};
        result[0][0] = poured;
        for (int i = 0; i < query_row+1; i++) {
            for (int j = 0; j <= i; j++) {
                if (result[i][j] >= 1) {
                    result[i + 1][j] += (result[i][j] - 1) / 2.0;
                    result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
                    result[i][j] = 1;
                }
            }
        }
        return result[query_row][query_glass];
    }
};
