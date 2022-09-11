class maxSegmentTree {
    public:
        int n;
        vector<int>tree;
        maxSegmentTree(int nodes) : n(nodes) {
            int s = (int)ceil(log2(n));
            s = 2*pow(2, s)-1;
            tree = vector<int>(s);
        }
        int query(int l, int r) {
            return query_util(0, l, r, 0, n-1);
        }
        int query_util (int i, int ql, int qr, int l, int r) {
            if (l >= ql && r <= qr) return tree[i];
            if (l > qr || r < ql) return INT_MIN;
            int mid = (l+r)/2;
            return max(query_util(2*i+1, ql, qr, l, mid), query_util(2*i+2, ql, qr, mid+1, r));
        }
        void update(int i, int val) {
            update_util(0, 0, n-1, i, val);
        }
        void update_util (int i, int l, int r, int pos, int val) {
            if (pos < l || pos > r) return;
            if (l == r) {
                tree[i] = max(val, tree[i]);
                return;
            }
            int mid = (l+r)/2;
            update_util(2*i+1, l, mid, pos, val);
            update_util(2*i+2, mid+1, r, pos, val);
            tree[i] = max(tree[2*i+1], tree[2*i+2]);
        }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int ans = 0, low, cur;
        maxSegmentTree tree(1e5+1);
        for (int i : nums) {
            low = max(0, i-k);
            cur = 1+tree.query(low, i-1);
            tree.update(i, cur);
            ans = max(ans, cur);
        }
        return ans;
    }
    
};
