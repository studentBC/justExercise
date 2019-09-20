class Solution {
public:
    void go (int cc, vector<bool>& visited, vector<vector<string>>& accounts, vector<int>& group, unordered_set<string>& email) {
        for (int i = 0; i < accounts.size(); i++) {
            if ( group[i] < 0) {
                for (int j = 1; j < accounts[i].size(); j++) {
                    if (email.find(accounts[i][j]) == email.end()) {
                        continue;
                    } else {
                        for (int k = 1; k < accounts[i].size(); k++) {
                            email.insert(accounts[i][k]);
                        }
                        group[i] = cc; 
                        go (cc, visited, accounts, group, email);
                        break;
                    }
                }
                visited[i] = true;
                
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int>group(accounts.size(), -1);
        vector<vector<string>>ans;
        for (int i = 0; i < accounts.size(); i++) {
            if (group[i] < 0) {
                vector<bool>visited(accounts.size(), false);
                unordered_set<string>temp;
                for (int j = 1; j < accounts[i].size(); j++) temp.insert(accounts[i][j]);
                go (i, visited, accounts, group, temp);
                vector<string>email(temp.begin(), temp.end());
                sort(email.begin(), email.end());
                email.insert(email.begin(), accounts[i][0]);
                ans.emplace_back(email);
            }
        }
        return ans;
    }
};
//60 ms solution
class Solution {
public:
    unordered_map<string, int> lookup_;
    vector<int> parent_;
    vector<vector<string>> ans;
    
      
    int findParent(int i){
        while(parent_[i]!=i) i=parent_[i];
        return i;
    }
    
    void merge(int i, int j){
        parent_[findParent(i)] = findParent(j);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        parent_ = vector<int>(accounts.size());
        for(int i=0; i<accounts.size(); i++){
            parent_[i]=i;
            ans.push_back({accounts[i][0]});
        }
        
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(lookup_.find(accounts[i][j])!=lookup_.end()) merge(i, lookup_[accounts[i][j]]);
                else lookup_[accounts[i][j]] = i;
            }
        }
        
        for(auto account:lookup_){
            ans[findParent(account.second)].push_back(account.first);
        }
        
        for(auto p = ans.end()-1; p>=ans.begin(); p--){
            if((*p).size()<=1){ans.erase(p); continue;}
            sort((*p).begin(), (*p).end());
        }
        
        return ans;
    }
};

static const auto ______ = []() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
