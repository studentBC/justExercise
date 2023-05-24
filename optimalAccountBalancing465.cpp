class Solution {
public:
    vector<long>bb;
    int go (int i) {
        while (i < bb.size() && !bb[i]) i++;
        int ans = INT_MAX;
        for (int j = i+1; j < bb.size(); j++) {
            if (bb[j]*bb[i] < 0) {
                bb[j]+=bb[i];
                ans = min(ans, 1+go(i+1));
                bb[j]-=bb[i];
            }
        }
        return ans != INT_MAX? ans : 0;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, long>balance;
        for (int i = 0; i < transactions.size(); i++) {
            balance[transactions[i][0]]-=transactions[i][2];
            balance[transactions[i][1]]+=transactions[i][2];
        }
        
        for (auto& it: balance) {
            if (it.second) bb.push_back(it.second);
        }

        return go(0);
    }
};
