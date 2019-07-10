/*
 * Since ranges are continuous, what if we add reservations to the first flight in the range, and remove them after the last flight in range? We can then use the running sum to update reservations for all flights.
 */
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (int i = 0; i < bookings.size(); ++i) {
            ans[bookings[i][0]-1]+=bookings[i][2];
            if (bookings[i][1] < n) ans[bookings[i][1]] -= bookings[i][2];
        }
        for (int i = 1; i < n; i++) ans[i] += ans[i-1];
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);

        for(vector<int>& it: bookings) {
            res[it[0]-1] += it[2];
            if(it[1] < n) 
                res[it[1]] -= it[2];
        }
        
        for(int i = 1; i < n; ++i) {
            res[i] += res[i-1];
        }
        
        return res;
    }
};

int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
