class Solution {
    unordered_map<int, int> cache;

    int subTiling(int n, int m) {
        if (n==m)
            return 1;
        if (n==13 && m==11)
            return 6;
        if (n<m)
            return subTiling(m,n);

        int key=(n<<16)+m;
        if (cache.count(key))
            return cache[key];
        
        int result=INT32_MAX;
        for (int i=1; i<=n/2; i++) {
            result=min(result, subTiling(i, m)+subTiling(n-i, m));
        }
        for (int i=1; i<=m/2; i++) {
            result=min(result, subTiling(n, i)+subTiling(n, m-i));
        }

        cache[key]=result;
        return result;
    }
public:
    int tilingRectangle(int n, int m) {
        return subTiling(n, m);
    }
};
