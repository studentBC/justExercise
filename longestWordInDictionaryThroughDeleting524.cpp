class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int count = 0, most = 0, start;
        bool found, nomatch;
        string ans = "";
        for (int i = 0; i < d.size(); ++i) {
            count = 0;nomatch = false;
			start = 0;
            for (int j = 0; j < d[i].size(); ++j) {
				found = false;
				for (int k = start; k < s.size(); ++k) {
					if (d[i][j] == s[k]) {
						found = true;
						start = k+1;
						break;
					}
				}
				if (!found) {
					nomatch = true;break;
				}
            }
            if (!nomatch) {
                if (d[i].size() > most) {
                    most = d[i].size();
                    ans = d[i]; 
                } else if (d[i].size() == most) {
                    for (int j = 0; j < ans.size(); ++j) {
                        if (ans[j] > d[i][j]) {
                            ans = d[i];
                            break;
                        } else if (ans[j] < d[i][j]) break;
                    }
                }
            }
        }
        if (ans.size() > 0) return ans;
        return "";
    }
};
//the fatest method
const int N=1005,CH=26;
int q[CH][N],q1[CH],d1[N];
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n=s.size(),m=d.size();
		for (int i=0;i<CH;++i)q1[i]=0;
		for (int i=0;i<m;++i){
			int c=d[i][0]-'a';
			d1[i]=0; q[c][q1[c]++]=i;
		}
		for (int i=0;i<n;++i){
			int c=s[i]-'a',k=q1[c]; q1[c]=0;
			for (int j=0;j<k;++j){
				int id=q[c][j]; ++d1[id];
				if (d1[id]<d[id].size()){
					int c1=d[id][d1[id]]-'a';
					q[c1][q1[c1]++]=id;
				}
			}
		}
		string ans="";
		for (int i=0;i<m;++i)
			if ((d1[i]==d[i].size())&&(d[i].size()>ans.size()||d[i].size()==ans.size()&&d[i]<ans))ans=d[i];
		return ans;
    }
};

//IO
int _IO=[](){
    std::ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    return 0;
}();
