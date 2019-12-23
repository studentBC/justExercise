/*
wrong test case:
["2.000","2.000","2.000","2.000","2.000"]
11
["1.500","2.500","3.500"]
5
["2.000","2.000","2.000","2.000","2.000"]
10
*/
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        vector<double>p;
        vector<pair<double,int>>cf; //0 is floor 1 is ceiling
        int si; double sd, ans = 0, over = 0;
        for (string s: prices) {
            si = stoi(s);
            sd = stod(s);
            target-=si;
            p.push_back(sd);
            cf.push_back(make_pair(sd-si, 0));
            if (sd-si) {
                over++;
                cf.push_back(make_pair(si+1-sd, 1));
            } else {
                cf.push_back(make_pair(0, 1));
            }
        }
        //cout << over <<" target " << target << endl;
        if (over < target || target < 0) return "-1";
        sort(cf.begin(), cf.end());
        int floor = prices.size()-target;
        for (int i = 0; i < cf.size()&&(target || floor); i++) {
            if (cf[i].second) {
                if (target && cf[i].first) {
                    ans+=cf[i].first;
                    target--;
                }
            } else {
                if (floor) {
                    ans+=cf[i].first;
                    floor--;
                }
            }
        }
        //if (ans == 0) return "-1";
        std::ostringstream strs;
        strs << ans;
        string answer = strs.str();
        bool found = false;
        size_t pos = answer.find('.');
        if (pos == string::npos) {
            answer+=".000";
        } else {
            int left = 3-(answer.size()-1-pos);
            for (int i = 0; i < left; i++) {
                answer+="0";
            }
        }
        return answer;
    }
};
//the fatest solution
class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        vector<double> diffs;
        int sum = 0;
        double error = 0.0;
        for (const auto& str : prices) {
            double price = stod(str);
            int fprice = floor(price), cprice = ceil(price);
            sum += cprice;
            if (fprice != cprice) {
               error += cprice - price;
               diffs.push_back(2 * price - cprice - fprice);    
            } 
        }
        if (sum < target || sum > target && sum - target > diffs.size()) return "-1";
        nth_element(diffs.begin(), diffs.begin() + sum - target, diffs.end());
        for (int i = 0; i < sum - target; ++i) {
            error += diffs[i];
        }
        string res = to_string(error);
        return res.substr(0, res.find('.') + 4);
    }
};
