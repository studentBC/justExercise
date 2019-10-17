class Solution {
public:
    void go (long num, long& target, vector<int>& factors, vector<int>& number, vector<vector<int>>& ans) {
        if (num == target) {
            vector<int>temp(factors.begin(), factors.end());
            sort(temp.begin(), temp.end());
            string tmp;
            for (int i:temp) tmp.push_back(i+'0');
            //cout << tmp << endl;
            if (tmp.size() && visited.find(tmp) == visited.end()) {
                ans.emplace_back(factors);
                visited.insert(tmp);
            }
        } else {
             for (int i = 0; i < number.size(); i++) {
                if (num*number[i] <= target) {
                    factors.emplace_back(number[i]);
                    go (num*number[i], target, factors, number, ans);
                    factors.pop_back();
                }
             }
        }
    }
    void get_primeFactors(int n, vector<int>& factors)
    {
         double total = n*(n);
         for (int i = 2; i <= total; i++)
             while (n % i == 0) {
                factors.emplace_back(i);
                //cout << i << ", ";
              get_primeFactors(n /= i, factors);
                return;        
            }
    }
    void getDivisors(int n, vector<int>& factors)
    {
        // Note that this loop runs till square root 
        for (int i=2; i<=sqrt(n); i++)
        { 
            if (n%i == 0) 
            { 
                // If divisors are equal, print only one 
                if (n/i == i) {
                    //printf("%d ", i);
                    factors.emplace_back(i);
      
                } else {// Otherwise print both 
                    //printf("%d %d ", i, n/i); 
                    factors.emplace_back(i);
                    factors.emplace_back(n/i);
                }
            } 
        } 
    } 
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>>ans;
        vector<int>factors, temp;
        //get_primeFactors(n, factors);
        getDivisors(n,factors);
        long N = n;
        go (1, N, temp, factors, ans);
        return ans;
    }
private:
    unordered_set<string>visited;
};
//the fatest solution
#include<bits/stdc++.h>

using namespace std;

static int fast_io = [] () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
} ();

class Solution {
public:

	void dfs (int n, vector<int>& path, vector<vector<int>>& ans, int& on) {
		for (int i = path.empty() ? 2 : path.back(); i <= trunc(sqrt(n)); i++) {
			if (n % i == 0) {
				path.push_back(i);
				dfs(n / i, path, ans, on);
				path.pop_back();
			}
		}
		if (n != on) {
			path.push_back(n);
			ans.push_back(path);
			path.pop_back();
		}
		return;
	}

    vector<vector<int>> getFactors(int n) {
		vector<vector<int>> ans;
		vector<int> path;
		int on = n;
		dfs(n, path, ans, n);
		return ans;
    }
};

