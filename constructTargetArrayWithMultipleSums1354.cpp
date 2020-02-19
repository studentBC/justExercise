/*
 * Given that the sum is strictly increasing, the largest element in the target must be formed in the last step by adding the total sum in the previous step. Thus, we can simulate the process in a reversed way.
 * Subtract the largest with the rest of the array, and put the new element into the array. Repeat until all elements become one
 */
//time limit case:  
//[2,900000001]
//[2,900000002]
class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            if (target[0] != 1) return false;
            else return true;
        }
        long long sum = 0, big, prev, ps;
        priority_queue<int>pq;
        for (int i: target) {
            pq.push(i);
            sum+=i;
        }
        ps = sum;
        while (1) {
            prev = big = pq.top();
            pq.pop();
            if (big == 1) return true;
            if (big%(sum-big) == 0) big = sum-big;
            else big%=(sum-big);
            ps = sum;
            sum-=(prev-big);
            if (ps <= sum) return false;
            pq.push(big);
        }
        return true;
    }
};
//the 16 ms solution
class Solution {
public:
    bool isPossible(vector<int>& target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        long s = 0;
        priority_queue<int> pq;
        for (auto& t : target) {
            s += t;
            if (t != 1) {
                pq.push(t);
            }
        }
        
        while (pq.empty() == false) {
            int t = pq.top();
            pq.pop();
            
            if (t <= s - t) {
                return false;
            }
            else {
                if (t > s - t + 1) {
                    pq.push(2 * t - s);
                }
                s = t;
            }
        }
        
        return true;
    }
};
