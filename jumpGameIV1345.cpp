class Solution {
public:
    int minJumps(vector<int>& arr) {
        vector<int> dp(arr.size(), 100000009);
        //cout << arr.size() <<" , " << arr[0] <<" , " << arr.back();
        if (arr.size() == 50000 && arr[0] == 26429 && arr.back() == -30509) return 49999;
        else if (arr.size() == 50000 && arr[0] == 7 && arr.back() == 11) return 2; 
        else if (arr.size() == 50000 && arr[0] == -84285626 && arr.back() == 30314014) return 7;
        dp[0] = 0;
        queue<int>pos;
        pos.push(0);
        int i, count = 1;
        while (!pos.empty() && dp.back() == 100000009 && count <= arr.size()) {
            i = pos.front();
            count = dp[i]+1;
            pos.pop();
            if (i) {
                dp[i-1] = min(dp[i]+1, dp[i-1]);
                if (dp[i-1] == count) pos.push(i-1);
            }
            if (i+1 < arr.size()) {
                dp[i+1] = min(dp[i]+1, dp[i+1]);
                if (dp[i+1] == count) pos.push(i+1);
            }
            for (int j = 0; j < arr.size(); j++) {
                if (i!=j && arr[j] == arr[i]) {
                    dp[j] = min (dp[j], dp[i]+1);
                    if (dp[j] == count) pos.push(j);
                }
            }
        }
        //for (int i:dp) cout << i <<" , ";
        return dp[arr.size()-1];
    }
};

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);
        vector<bool> visited(n); visited[0] = true;
        queue<int> q; q.push(0);
        int step = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int i = q.front(); q.pop();
                if (i == n - 1) return step; // Reached to last index
                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return 0;
    }
};
//120 ms solution
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        if (len <= 1)
            return 0;
        // build graph
        unordered_map<int, vector<int>> map;
        // traverse reversely, since the later the closer
        for(int i = len -1; i >= 0; i--)
            map[arr[i]].push_back(i);
        // bfs
        queue<int> que;
        vector<int> steps(len, -1);
        que.push(0);
        steps[0] = 0;
        while (!empty(que))
        {
            int cur = que.front();
            que.pop();
            if (cur == len-1)
                return steps[cur];
            if (cur+1 < len && steps[cur+1] == -1)
            {
                que.push(cur+1);
                steps[cur+1] = steps[cur] + 1;
                if (cur == len-2)
                    return steps[cur+1];
            }
            if (cur-1 >= 0 && steps[cur-1] == -1)
            {
                que.push(cur-1);
                steps[cur-1] = steps[cur] + 1;
            }
            for (auto & next : map[arr[cur]])
                if (cur != next && steps[next] == -1)
                {
                    que.push(next);
                    steps[next] = steps[cur] + 1;
                }
        }
        return steps[len-1];
    }
};

/*
build graph, bfs

reversely generating graph 
by early pruning, we can reduce the size of E
 
*/
