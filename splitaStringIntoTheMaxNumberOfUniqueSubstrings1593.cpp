class Solution {
public:
    void go (int start, string& s, vector<int>pos, int& ans) {
        if (start == s.size()) {
            unordered_set<string>ss;
            string tmp;
            for (int i = 0; i < pos.size(); i++) {
                tmp = "";
                if (i) {
                    for (int j = pos[i-1]+1; j <= pos[i]; j++) tmp+=s[j];
                } else {
                    for (int j = 0; j <= pos[i]; j++) tmp+=s[j];
                }
                if (ss.count(tmp)) return;
                else ss.insert(tmp);
            }
            ans = max(ans, (int)ss.size());
            return;
        }
        for (int i = start; i < s.size(); i++) {
            pos.push_back(i);
            go (i+1, s, pos, ans);
            pos.pop_back();
        }
    }
    int maxUniqueSplit(string s) {
        vector<int>pos;
        int ans = 1;
        go (0,s,pos, ans);
        return ans;
    }
};
//the fatest solution
class Solution {
    typedef vector<unordered_map<string, bool>> type;
    string GetString(int start, int end, string& str)
    {
        return str.substr(start, end-start+1);
    }
    
public:
    int maxUniqueSplit(string s) {
        int N = s.size();
        int maxi = 1;
        type ans[21][21];
      
        for(int i = 0 ; i < N ;i++)
        {
            for(int j = i ; j < N ;j++)
            {
                 if(i==0)
                 {  
                     unordered_map<string, bool> tempMp;
                     tempMp.insert(make_pair(GetString(0, j, s), true));
                     ans[i][j].push_back(tempMp); 
                     continue;
                 }
                  
                int maxSoFar = 0;
               
                for(int k  = j-1 ; k >= 0 ; k--)
                {
                    const auto& curStr = GetString(k+1, j, s);
                    auto& vecMp = ans[i-1][k];
                    
                    for(auto& mp : vecMp)
                    {
                        int curSize = mp.size(); 
                        //cout<<curSize<<" ";
                        if(curSize > maxSoFar && mp.find(curStr) == mp.end())
                        {
                            maxSoFar = curSize;  
                        }
                    }                    
                }
                
                for(int k  = j-1 ; k >= 0 ; k--)
                {
                    const auto& curStr = GetString(k+1, j, s);
                    auto& vecMp = ans[i-1][k];
            
                    for(auto& mp : vecMp)
                    {
                        int curSize = mp.size(); 
                    
                        if(curSize == maxSoFar && mp.find(curStr) == mp.end())
                        {   
                            ans[i][j].emplace_back(mp);
                            ans[i][j][ans[i][j].size()-1][curStr] = 1;
                              
                        } 
                    }   
                     maxi = max(maxi, maxSoFar+1); 
                }
                
            }
        }
        return maxi;
    }
};
