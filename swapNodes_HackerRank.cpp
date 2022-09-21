//https://www.hackerrank.com/challenges/swap-nodes-algo/forum
void go (vector<vector<int>>& indexes, vector<int>& tmp, int height, int k, int row) {
    if (row < 0) return;
    height++;
    if (height >=k && height%k == 0) {
        int left = indexes[row][0]-1,
            right = indexes[row][1]-1;
        if (left > -1) swap(indexes[left][0], indexes[left][1]);
        if (right > -1) swap(indexes[right][0], indexes[right][1]);
    }
    go (indexes, tmp, height, k, indexes[row][0]-1);
    tmp.push_back(row+1);
    go (indexes, tmp, height, k, indexes[row][1]-1);

}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>>ans(queries.size());
    int h = 1;
    for (int i = 0; i < queries.size(); i++) {
        if (queries[i] == 1) swap(indexes[0][1], indexes[0][0]);
        h = 1;
        go (indexes, ans[i], 1, queries[i], 0);
    }
    return ans;
}
