/*
 * wrong test case
 * ["an","excellent","lunch"]
 * ["one","good","dinner"]
 * [["great","good"],["extraordinary","good"],["well","good"],["wonderful","good"],["excellent","good"],["fine","good"],["nice","good"],["any","one"],["some","one"],["unique","one"],["the","one"],["an","one"],["single","one"],["a","one"],["truck","car"],["wagon","car"],["automobile","car"],["auto","car"],["vehicle","car"],["entertain","have"],["drink","have"],["eat","have"],["take","have"],["fruits","meal"],["brunch","meal"],["breakfast","meal"],["food","meal"],["dinner","meal"],["super","meal"],["lunch","meal"],["possess","own"],["keep","own"],["have","own"],["extremely","very"],["actually","very"],["really","very"],["super","very"]]
 */
class Solution {
public:
    class UnionFind{
    public:
        unordered_map<string, string> parent;
        UnionFind() {
        }
        string Find(string child) {
            if(parent.find(child) == parent.end() ) {
                parent[child] = child;
            }
            return parent[child] == child ? child : parent[child] = Find(parent[child]);
        }

        bool Union(string c1, string c2){
            string p1 = Find(c1);
            string p2 = Find(c2);
            if(p1 == p2) return false;
            parent[p1] = p2;
            return true;
        }
    };
     bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        UnionFind uf;
        for (int i = 0; i < pairs.size(); i++) {
            uf.Union(pairs[i][0], pairs[i][1]);
        }
        for (int i = 0; i < words1.size(); i++) {
            if (uf.Find(words1[i]) != uf.Find(words2[i])) return false;
        }
        return true;
    }
};
//my time limit approach
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        bool found;
        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i]) {
                found = false;
                queue<string>next;
                next.push(words1[i]);
                unordered_set<string>visited;
                while (!next.empty()) {
                    string source = next.front();
                    if (source == words2[i]) {
                        found = true;
                        break;
                    }
                    next.pop();
                    if (!visited.count(source)) {
                        visited.insert(source);
                        for (int i = 0; i < pairs.size(); i++) {
                            if (pairs[i][0] == source) {
                                next.push(pairs[i][1]);
                            } else if (pairs[i][1] == source) {
                                next.push(pairs[i][0]);
                            }
                        }
                    }
                }
                if (!found) return false;
            }
        }
        return true;
    }

};
//the fatest solution
class DisjointSet {
private:
	vector<int> p, rank;
	int nSet;
public:
	DisjointSet(int n) : p(n), rank(n), nSet(n) {
		iota(p.begin(), p.end(), 0);
	}
	int FindSet(int x) {
		if (p[x] != x)
			p[x] = FindSet(p[x]);
		return p[x];
	}
	void Union(int x, int y) {
		x = FindSet(x), y = FindSet(y);
		if (x != y) {
			--nSet;
			if (rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				//if (rank[x] == rank[y])
					rank[y] += rank[x];
			}
		}
	}
	int CountSet() const {
		return nSet;
	};
};

class Solution {
public:
    static bool areSentencesSimilarTwo(const vector<string>& words1, const vector<string>& words2, const vector<vector<string>>& pairs) {
        const int n = words1.size(), m = words2.size(), k = pairs.size();
        
        
        DisjointSet s(k * 2);
        unordered_map<string, int> str2dictID;
        int dictID = 0;
        for (const auto& it : pairs) {
            int u, v;
            const auto x = str2dictID.find(it[0]), y = str2dictID.find(it[1]);
            if (x == str2dictID.end())
                u = str2dictID[it[0]] = dictID++;
            else
                u = x->second;
            if (y == str2dictID.end())
                v = str2dictID[it[1]] = dictID++;
            else
                v = y->second;
            s.Union(u, v);
        }
        if (n != m)
            return false;
        for (int i = 0; i < n; ++i) {
            if (words1[i] != words2[i]) {
                const auto x = str2dictID.find(words1[i]), y = str2dictID.find(words2[i]);
                if (x == str2dictID.end() || y == str2dictID.end())
                    return false;
                if (s.FindSet(x->second) != s.FindSet(y->second))
                    return false;
            }
        }
        return true;
    }
};
static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
