class Solution {
public:
    class UnionFind {
        vector<int>id;
        public:
            UnionFind(int n): id(n) {
                iota(begin(id), end(id), 0);
            }
            void connect (int a, int b) {
                id[find(b)] = find(a);
            }
            int find(int i) {
                return id[i] == i? i : (id[i] = find(id[i]));
            }
            bool connected (int a, int b) {
                return find(a) == find(b);
            }
            void reset(int i) {
                id[i] = i;
            }
    };
    class vertex {
        public:
            int dist;
            int x;
            int y;
            vertex (int a, int b, int c) {
                dist = a; x = b; y = c;
            }
    };
    struct Comp{
        bool operator()(const vertex& a, const vertex& b){
            return a.dist > b.dist;
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size(), ans = 0, count = 0, dist;
        if (len == 1) return 0;
        UnionFind uf(len);
        priority_queue< vertex, vector<vertex>, Comp> pq;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push(vertex(dist, i, j));
            }
        }
        len--;
        while (count < len && !pq.empty()) {
            vertex v = pq.top();
            pq.pop();
            if (!uf.connected(v.x, v.y)) {
                uf.connect(v.x, v.y);
                ans += v.dist;
                count++;
            }
        }
        return ans;
    }
};
