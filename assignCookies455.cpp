class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
 		int ans = 0;
		sort(s.begin(), s.end());
		sort(g.begin(), g.end());
		for (int i = 0; i < g.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				if (g[i]<=s[j]) {
					s[j] = -1;
					ans++;
					break;
				}
			}
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
       int i=0,j=0;
        int sum=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<g.size()&&j<s.size())
        {
            if(s[j]>=g[i])
            {
                
                i++;
            
            }
             j++;
        }
        return i;
    }
};
