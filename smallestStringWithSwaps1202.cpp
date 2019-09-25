/*
The core of the idea is that if (0, 1) is an exchange pair and (0, 2) is an exchange pair, then any 2 in (0, 1, 2) can be exchanged.

This implies, we can build connected components where each component is a list of indices that can be exchanged with any of them. In Union find terms, we simply iterate through each pair, and do a union on the indices in the pair.
At the end of the union of all the pairs, we have built connected component of indices that can be exchanged with each other.

Then we build a sorted list of characters for every connected component.

The final step is, we iterate through all the indices, and for each index we locate its component id and find the sorted list correspondng to that component and grab the next lowest character from that list.

This way for every index, we find the lowest possible character that can be exchanged and fitted there.
*/
class Solution {
public:
    int find(vector<int>& ds, int i) {
      return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      vector<int> ds(s.size(), -1);
      vector<vector<int>> m(s.size());
      for (auto& p : pairs) {
        auto i = find(ds, p[0]), j = find(ds, p[1]);
        if (i != j) ds[j] = i;
      }
      for (auto i = 0; i < s.size(); ++i) m[find(ds, i)].push_back(i);
      for (auto ids : m) {
        string ss = "";
        for (auto id : ids) ss += s[id];
        sort(begin(ss), end(ss));
        for (auto i = 0; i < ids.size(); ++i) s[ids[i]] = ss[i];
      }
      return s;
    }

};
//my solution the last test case wont pass
class Solution {
public:
    void go (int start, int mark, vector<vector<int>>& pairs, vector<int>& group) {
        if (group[start] > -1) return;
        group[start] = mark;
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i][0] == start) {
                go (pairs[i][1], mark, pairs, group);
            } else if (pairs[i][1] == start) {
                go (pairs[i][0], mark, pairs, group);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> group(s.size(), -1);
        for (int i = 0; i < pairs.size(); i++) {
            if (group[i] < 0) go (i, i, pairs, group);
        }
        int target;
        for (int i = 0; i < group.size(); i++) {
            //cout << group[i] <<" , ";
            if (group[i] > -1) {
                target = group[i];
                vector<char>temp;
                vector<int>index;
                for (int j = 0; j < group.size(); j++) {
                    if (group[j] == target) {
                        temp.emplace_back(s[j]);
                        index.emplace_back(j);
                        group[j] = -1;
                    }
                }
                sort(temp.begin(), temp.end());
                for (int j = 0; j < index.size(); j++) {
                    s[index[j]] = temp[j];
                }
            }
        }
        return s;
    }
};
