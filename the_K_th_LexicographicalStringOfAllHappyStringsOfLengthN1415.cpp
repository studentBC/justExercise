class Solution {
public:
    char alpha[3] = {'a','b','c'};
	unordered_set<string>visited;
    string ans;
    void go (int n, vector<char>& temp, int& k) {
        if ( temp.size() == n || k <= visited.size()) {
            string tmp(temp.begin(), temp.end());
			if (visited[tmp]) return;
			visited.insert(tmp);
            if (k == visited.size()) {
                ans = tmp;
            }
            return;
        }
		for (int j = 0; j < 3; j++) {
			if (temp.size() == 0 || temp.back()!=alpha[j]) {
				temp.push_back(alpha[j]);
				go (n, temp, k);
				temp.pop_back();
			}
		}
    }
    string getHappyString(int n, int k) {
        vector<char>temp;
        go (n, temp, k);
        return ans;
    }
};
//the fatest solution
class Solution {
public:
string getHappyString(int n, int k) {
    string ans;
    int m = pow(2, double(n-1));
    if (3 * m < k) return ans;
    int idx = (k-1) / m;
    int inner = (k % m + m - 1) % m;
    vector<int> vec;
    for (int i = 0; i < n-1; ++i) {
        vec.push_back(inner % 2);
        inner = inner / 2;
    }

    char pre = 'a' + idx;
    ans.push_back(pre);
    for (int i = vec.size()-1; i >= 0; --i) {
        int cur = 0;
        for (int j = 0; j < 3; ++j) {
            if ('a'+j == pre) continue;
            if (cur == vec[i]) {
                ans.push_back('a'+j);
                pre = 'a' + j;
            }
            ++cur;
        }
    }
    return ans;
}
};
