class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, std::vector<int>, std::greater<int> >pq;
        unordered_set<int>pass;
        int count = 1, temp;
        pq.push(1);
        pass.insert(1);
        //cout << INT_MAX/2 << endl;
        while (count < n) {
            if (pq.top() < 1073741823) {
                temp = pq.top()<<1;
                if (pass.find(temp) == pass.end()) {
                    pass.insert(temp);
                    pq.push(temp);
                    //count++;
                }
            }
            if (pq.top() <= 715827882) {
                temp = pq.top()*3;
                if (pass.find(temp) == pass.end()) {
                    pass.insert(temp);
                    pq.push(temp);
                    //count++;
                }
            }
            if (pq.top() < 429496729) {
                temp = pq.top()*5;
                if (pass.find(temp) == pass.end()) {
                    pass.insert(temp);
                    pq.push(temp);
                    //count++;
                }
            }
            pq.pop();
            count++;
        }
        while (count < n) {
            pq.pop();
            count++;
        }
        return pq.top();
    }
};
//the fatest solution
class Solution {
public:
    static vector<long long> result;
    static vector<long long> initial(){
        vector<long long> dp {1};
        int i = 0, j = 0, k = 0; //i->times 2; j->times 3; k->times 5;
        while (dp.size() != 1690){
            long long by2 = 2 * dp[i];
            long long by3 = 3 * dp[j];
            long long by5 = 5 * dp[k];
            long long min_num = min(min(by2, by3), by5);
            if (min_num != dp.back())  //In case of duplicates.
                dp.push_back(min_num);
            if (min_num == by2){
                ++i;
                continue;
            }
            else if (min_num == by3){
                ++j;
                continue;
            }
            else{
                ++k;
                continue;
            }
        }
        return dp;
    }
    int nthUglyNumber(int n) {
        return result[n-1];
    }
};
vector<long long> Solution::result = Solution::initial();
