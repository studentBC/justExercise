class Solution {
public:
    void go (int start, vector<vector<int>>& stones, vector<int>&cc, int mark) {
        if (start < stones.size()) {
            int x = stones[start][0];
            int y = stones[start][1];
            for (int i = 0; i < stones.size(); i++) {
                if ((x == stones[i][0] || y == stones[i][1]) && cc[i]==-1) {
                    //cout << i << " , ";
                    cc[i] = mark;
                    go (i, stones, cc, mark);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        set<int>remove;vector<int>cc(stones.size(),-1);
        //cout << endl;
        for (int i = 0; i < stones.size(); i++) {
            if (cc[i] < 0) go (i,stones,cc,i);
        }
        for (int i = 0; i < stones.size(); i++) {
            //cout << cc[i] << " , ";
            remove.insert(cc[i]);
        }
        return stones.size()-remove.size();
    }
};
//the fatest method
class _disjoint_set {
	vector<int> _parent;
	int _size;

public:
	_disjoint_set(int n) {
		_parent.reserve(n);
		for (int i = 0; i < n; i++)
			_parent.push_back(i);
		_size = n;
	}

	int find(int i) {
		if (i != _parent[i])
			_parent[i] = _parent[find(_parent[i])];
		return _parent[i];
	}

	void join(int i, int j) {
		int ri = find(i), rj = find(j);
		if (ri != rj) {
			_parent[ri] = rj;
			_size--;
		}
	}

	inline int size() { return _size; }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        _disjoint_set ds(stones.size());
        vector<pair<int, int>> vp;
        for (int i = 0; i < stones.size(); i++)
            vp.emplace_back(stones[i][0], i);
        sort(vp.begin(), vp.end());
        for (int i = 1; i < vp.size(); i++)
            if (vp[i].first == vp[i - 1].first)
                ds.join(vp[i].second, vp[i - 1].second);
        vp.clear();
        for (int i = 0; i < stones.size(); i++)
            vp.emplace_back(stones[i][1], i);
        sort(vp.begin(), vp.end());
        for (int i = 1; i < vp.size(); i++)
            if (vp[i].first == vp[i - 1].first)
                ds.join(vp[i].second, vp[i - 1].second);
        return stones.size() - ds.size();
    }
};
