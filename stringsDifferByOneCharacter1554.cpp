// https://leetcode.com/problems/strings-differ-by-one-character/discuss/802871/Rabin-Karp-O(nm)

/*
1. Compute a hash for each string i in [0, n) as hash[i] = a[0] * 26 ^ (m - 1) + a[1] * 26 ^ (m - 2) + ... + a[m - 2] * 26 + a[m - 1]

2. For each char position, we compute the hash without that char for each string, check if that string has seen before.

3. We are using mod. So, there might be collisions. We use vector<int> to solve collisions.

//*/
class Solution3 {
public:
    bool differByOne(vector<string>& dict) {
        int MOD = 1e9+7, n = dict.size(), m = dict[0].size();
        vector<int> hash(n);
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                hash[i] = (1ll*hash[i]*26 + dict[i][j] - 'a') % MOD;
        for(int j=m-1, mult=1; j>=0; --j){
            unordered_map<int, vector<int>> um;
            for(int i=0; i<n; ++i){
                int h = (hash[i] + MOD - 1ll*(dict[i][j] - 'a')*mult % MOD ) % MOD;
                auto it = um.find(h);
                if(it!=um.end())
                    for(auto k:it->second)
                        if(dict[i].substr(0,j)==dict[k].substr(0,j) && dict[i].substr(j+1) == dict[k].substr(j+1))
                            return true;
                um[h].push_back(i);
            }
            mult = 1ll*mult*26 % MOD;
        }
        return false;
    }
};


class Solution {
public:
  bool differByOne(vector<string>& A) {
    const int n = A.size();
    if (n <= 1) return false;
    int L = A[0].length();
    for (int j = 0; j < L; ++j) {

      sort(A.begin(), A.end(), [j,L](const auto& lhs, const auto& rhs){
        for (int i = j; i < L; ++i) {
          if (lhs[i] < rhs[i]) {
            return true;
          }
          if (lhs[i] > rhs[i]) {
            return false;
          }
        }
        for (int i = 0; i < j; ++i) {
          if (lhs[i] < rhs[i]) {
            return true;
          }
          if (lhs[i] > rhs[i]) {
            return false;
          }
        }
        return true;
      });

      for (int i = 1; i < n; ++i) {
        const string& p = A[i-1];
        const string& s = A[i];
        int numDiff = 0;
        for (int j = 0; j < L; ++j) {
          if (p[j] == s[j]) continue;
          if (++numDiff > 1) break;
        }
        if (numDiff == 1) return true;
      }
    }

    return false;
  }
};
