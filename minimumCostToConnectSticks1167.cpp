class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for (int i : sticks) pq.push(i);
        int f, s, ans = 0;
        while (pq.size() > 1) {
            f = pq.top();
            pq.pop();
            s = pq.top();
            ans+=(f+s);
            pq.pop();
            pq.push(f+s);
        }
        return ans;
    }
};
