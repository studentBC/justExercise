/*
"1. Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group."
So for any two workers in the paid group,
we have wage[i] : wage[j] = quality[i] : quality[j]
So we have wage[i] : quality[i] = wage[j] : quality[j]
We pay wage to every worker in the group with the same ratio compared to his own quality.

"2. Every worker in the paid group must be paid at least their minimum wage expectation."
For every worker, he has an expected ratio of wage compared to his quality.

So to minimize the total wage, we want a small ratio.
So we sort all workers with their expected ratio, and pick up K first worker.
Now we have a minimum possible ratio for K worker and we their total quality.

As we pick up next worker with bigger ratio, we increase the ratio for whole group.
Meanwhile we remove a worker with highest quality so that we keep K workers in the group.
We calculate the current ratio * total quality = total wage for this group.

We redo the process and we can find the minimum total wage.
Because workers are sorted by ratio of wage/quality.
For every ratio, we find the minimum possible total quality of K workers.

Time Complexity
O(NlogN) for sort.
O(NlogK) for priority queue.
*/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>>ratio;
        for (int i = 0; i < wage.size(); i++) ratio.push_back({(double)wage[i]/(double)quality[i], (double)quality[i]});
        sort(ratio.begin(), ratio.end());
        double ans = INT_MAX, s = 0;
        priority_queue<int>pq;
        for (auto r : ratio) {
            s+=r[1];
            pq.push(r[1]);
            if (pq.size() > k) s-=pq.top(), pq.pop();
            if (pq.size() == k) ans = min(ans, s*r[0]);
        }
        return ans;
    }
};
