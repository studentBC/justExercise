class Solution {
public:
    int check (vector<int>& color) {
        for (int i = 0; i < color.size(); i++) {
            if (color[i] == -1) {
                return i;
            }
        }
        return -1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        int point;
        queue<int>next;
        while (1) {
            point = check(color);
            if (point == -1) return true;
            next.push(point);
            color[point] = 1;

            while (!next.empty()) {
                point = next.front();
                next.pop();
                for (int i = 0; i < graph[point].size(); i++) {
                    if (color[graph[point][i]] == color[point]) {
                        return false;
                    } else if (color[graph[point][i]] == -1) {
                        next.push(graph[point][i]);
                        color[graph[point][i]] = 1-color[point];
                        //cout << "point " << graph[point][i] <<" color is " << color[graph[point][i]] << endl;
                    }
                }
            }
        }
        return true;
    }
};
//the fatest solution
static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int len = graph.size();
        if (len <= 1) return true;

        vector<char> color;
        color.resize(len, -1);
        
        for (int i = 0; i < len; i++)
        {
            if (color[i] == -1)
            {
                if (!isBP(graph, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBP(vector<vector<int> > & graph, int source, vector<char>& color)
    {
        queue<int> q;
        q.push(source);
        color[source] = 1;
        
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            for (auto& ii : graph[n])
            {
                if (color[ii] == -1)
                {
                    color[ii] = 1 - color[n];
                    q.push(ii);
                }
                else if (color[ii] == color[n])
                {
                    return false;
                }
            }
        }
        return true;
    
    }
};
