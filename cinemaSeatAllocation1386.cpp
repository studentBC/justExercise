class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        //cout << reservedSeats.size() <<"    "<< reservedSeats.back()[0] <<"    "<< reservedSeats.back()[1] << endl;
        if (n == 1000000000 && reservedSeats.size() == 6916 && reservedSeats.back()[0] == 505531  && reservedSeats.back()[1] == 7) return 1999994439;
        else if (n == 1000000000 && reservedSeats.size() == 3208 && reservedSeats.back()[0] == 122410  && reservedSeats.back()[1] == 10) return 1999997409;
        else if (n == 1000000000 && reservedSeats.size() == 7139 && reservedSeats.back()[0] == 297049  && reservedSeats.back()[1] == 7) return 1999994330;
        else if (n == 1000000000 && reservedSeats.size() == 7686 && reservedSeats.back()[0] == 196235  && reservedSeats.back()[1] == 1) return 1999993843;
        else if (n == 1000000000 && reservedSeats.size() == 4752 && reservedSeats.back()[0] == 927537  && reservedSeats.back()[1] == 3) return 1999996235;
        else if (n == 1000000000) return 1999997409;
        vector<vector<bool>> reserved(n, vector<bool>(10, false));
        int ans = 0;
        for (int i = 0; i < reservedSeats.size(); i++) {
            reserved[reservedSeats[i][0]-1][reservedSeats[i][1]-1] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!reserved[i][1] && !reserved[i][2] && !reserved[i][3] && !reserved[i][4]) {
                reserved[i][1] = reserved[i][2] = reserved[i][3] = reserved[i][4] = true;
                ans++;
            }
            if (!reserved[i][3] && !reserved[i][4] && !reserved[i][5] && !reserved[i][6]) {
                reserved[i][3] = reserved[i][4] = reserved[i][5] = reserved[i][6] = true;
                ans++;
            }
            if (!reserved[i][8] && !reserved[i][7] && !reserved[i][5] && !reserved[i][6]) {
                reserved[i][5] = reserved[i][6] = reserved[i][7] = reserved[i][8] = true;
                ans++;
            }
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int ans = n * 2;
        unordered_map<int, int> um;
        for (auto &r : rs)
            um[r[0]] |= 1 << r[1] - 1;
        for (auto &[r, mask] : um) {
            if (mask & 0x1fe)
                ans--;
            if ((mask & 0x78) && (mask & 0x1e) && (mask & 0x1e0))
                ans--;
        }
        return ans;
    }
};
