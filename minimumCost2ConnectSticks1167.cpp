/*
You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

 

Example 1:

Input: sticks = [2,4,3]
Output: 14
Example 2:

Input: sticks = [1,8,3,5]
Output: 30
 

Constraints:

1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4


*/
class Solution {
public:
int connectSticks(vector<int>& sticks) {
        if (!sticks.size()) return 0;
        int a, b, ans = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int> >temp;
        for (int i :sticks) temp.push(i);
        while (temp.size() > 1) {
            a = temp.top();
            temp.pop();
            b = temp.top();
            temp.pop();
            temp.push(a+b);
            ans+=(a+b);
            //cout << ans <<" , ";
        }
        return ans;
    }
};
//120 ms solution
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int ans = 0;
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        return ans;
    }
};
