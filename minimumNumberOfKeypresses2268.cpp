class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int>count(26, 0);
        for (char c : s) {
            count[c-'a']++;
        }
        priority_queue<int>pq;
        for (int i : count) {
            if (i) pq.push(i);
        }
        int ans = 0, i = 0;
        while (!pq.empty()) {
            ans+=pq.top()*(i/9+1);
            i++;
            pq.pop();
        }
        return ans;
    }
};
