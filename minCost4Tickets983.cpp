class Solution {
public:
    int tmin (int a, int b, int c) {
        int smaller = min (a,b);
        return min(smaller,c);
    }
    void containMost (vector<int>& days, int sindex, int& buy, int& exp, int duration) {
        //cout << " at day " << days[sindex] << " duration: " << duration << endl;
        int count , canstart = days[sindex]-duration+1, canend = days[sindex]+duration-1, si, ei, max = 0, end;
        if (canstart <= 0)canstart = 1;
        for (int i = buy; i < days.size(); i++) {
            if (days[i] >= canstart) {
                si = i;
                break;
            }
        }
        for (int i = days.size()-1; i > -1; i--) {
            if (days[i] <= canend) {
                ei = i;
                break;
            }
        }
        //cout <<endl << "range start from " << si << " end at " << ei << endl;
        for (int i = si; i <= ei; i++) {
            count = 0;
            for (int j = i; days[j] < days[i]+duration; j++) {
                count++;
                end = j;
                if (count>=duration)break;
            }
            if (count > max) {
                buy = i;
                exp = end;
                max = count;
            }
        }
        //cout << "buy at: " << buy << " exp at: " << exp << " max is " << max << endl;
        buy++;exp++;
    }
    int findStart(vector<int>& days, int date, vector<int>& cost) {
        if (date <= 0) return 0;
        //cout << "try to find " << date << endl;
        for (int i = 0; i < days.size(); i++) {
            if (date <= days[i]) {
                if (cost[i+1] == 0) {
                    for (int j = i; j > -1; j--) {
                        if (cost[j]>0)return j;
                    }  
                }
                return i+1;
            }
        }
        //cout << "fucking no match to " << date << endl;
        return days.size()-1;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>cost(days.size()+1,0);
        int ws = 0, ms = 0, lw = 0, lm = 0, week = 0, month = 0;
        for (int i = 1; i < cost.size(); i++) {
            if (cost[i] == 0) {
                //cout <<"go to find " << days[i-1] -7 << endl;
                ws = findStart(days,days[i-1]-7,cost);
                ms = findStart(days,days[i-1]-30,cost);
                //cout << cost[ws]+costs[1] << " , " << cost[i-1]+costs[0] << " , " << cost[ms]+costs[2] << endl;
                cost[i] = tmin (cost[ws]+costs[1] , cost[i-1]+costs[0], cost[ms]+costs[2]);
                //cout<<endl <<"ws: " << ws << "  ms:  " << ms <<" min cost " << cost[i] << endl;
                if (cost[i] == cost[ws]+costs[1]) {
                    //find when to start week ticket
                    containMost (days,i-1,ws,lw,7);
                    cout <<endl << "  week start: " << ws << "  week end: " << lw << endl;
                    for (int j = ws; j <= lw; j++) cost[j] = cost[i];
                } else if (cost[i] == costs[ms]+costs[2]) {
                    //find when to start month ticket
                    containMost (days,i-1,ms,lm,30);
                    cout <<endl << "  month start: " << ms << "  month end: " << lm << endl;
                    for (int j = ms; j <= lm; j++) cost[j] =  cost[i];
                }
            }
            cout<<"i: "<<i<<"  cost:  " << cost[i] << endl;
        }
        return cost[days.size()];
    }
};
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      unordered_set<int> travel(days.begin(), days.end());
      int end = days[days.size()-1];
      int dp[end+1] = {0};
      for (int i = 1; i <= end; ++i) {
        if (travel.find(i) == travel.end()) dp[i] = dp[i - 1];
        else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
        //cout << dp[i] << " , ";
      }
      return dp[end];
    }

};

