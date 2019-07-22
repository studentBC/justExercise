class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            for (int j = i+1; j < dominoes.size(); j++) {
                if (dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1]) {
                    ans++;
                } else if (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
//48 ms solution
class Solution 
{
public:
    int numEquivDominoPairs(vector<vector<int>>& v) 
    {
        map<pair<int,int>, int> mp;
        for(int i=0;i<v.size();i++)
        {
            if(v[i][1]<v[i][0])
                swap(v[i][0],v[i][1]);
            mp[make_pair(v[i][0],v[i][1])]++;
        }
        int ans=0;
        for(map<pair<int,int>, int>::iterator it=mp.begin();it!=mp.end();it++)
            ans+=(it->second*(it->second-1)/2);
        return ans;
    }
};
