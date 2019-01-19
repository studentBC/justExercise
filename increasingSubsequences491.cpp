class Solution {
public:
	bool check(vector<vector<int>>&ans,  vector<int>&temp) {
		int prev = temp[0]
		for (int i = 1; i < temp.size(); i++) {
			if (temp[i] < prev) return true;
			prev = temp[i];
		}
		int count = 0;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i].size() == temp.size()) {
				count = 0;
				for (int j = 0; j < temp.size(); j++) {
					if (temp[j] == ans[i][j]) {
						count++;
					}
				}
				if (count == temp.size())return true;
			} else if (ans[i].size() > temp.size()){
				break;
			}
		}
		return false;
	}
	void find(int start, int total, vector<vector<int>>&ans,  vector<int>&temp, vector<int>&nums) {
		if (temp.size() == total) {
			if (!check(ans,temp)) {
				ans.push_back(temp);
			}
		} else {
			for (int i = start; i < nums.size(); i++) {
				temp.push_back(nums[i]);
				find (i+1,total,ans,temp,nums);
				temp.pop_back();
			}
		}
	}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int>temp;
		vector<vector<int>>ans;
		for (int i = 2; i <= nums.size(); i++) {
			find(0,i,ans,temp,nums);
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> seq;
        seq.reserve(nums.size());
        dfs(result, seq, nums.begin(), nums.end());
        return result;
    }
    
    static void printSeq(vector<int>& seq, int distance) {
        cout << distance << " from end: ";
        for (auto i : seq) {
            cout << i << ",";
        }
        cout << endl;
    }
    
    void dfs(
        vector<vector<int>>& result,
        vector<int>& seq,
        const vector<int>::iterator& itr,
        const vector<int>::iterator& end) {

        if (seq.size() > 1) {
            // add the sequence to the list of results, then append any larger sequences
            result.push_back(seq);
        }

        unordered_set<int> used;

        // for each character from current to end
        for (auto i = itr; i != end; i++) {
            // if the sequence has no values yet OR
            // if the value is greater, and it hasn't been done yet
            if ((!seq.empty() && *i < seq.back()) || used.count(*i)) {
                continue;
            }
            // replace the last int in the sequence
            seq.emplace_back(*i);
            // run a depth first search, pushing the sequence onto the stack, for a dfs, then popping it
            //printSeq(seq, distance(i, end));
            dfs(result, seq, next(i), end);
            seq.pop_back();
            used.insert(*i);
        }
    }
};
