class Solution {
public:
    int convert (string s, int start, int end) {
        int sum = 0;
        for (int i = start,j=0; j < end; i++,j++) {
            //cout << s[i];
            sum = sum*10+(s[i]-'0');
        }
        //cout << endl << sum << endl;
        return sum;
    }
    void go (int start, string s, vector<int>& pos, vector<string>& ans) {
        if (pos.size() == 4) {
            int one = pos[1]-pos[0], two =pos[2]-pos[1], three = pos[3]-pos[2], four = s.size()-pos[3], sum = one+two+three+four;
            if ( one < 4 && two < 4 && three < 4 && four < 4 && sum == s.size()) {
                    //cout << pos[0] <<" , " << pos[1] <<" , " << pos[2] <<" , " << pos[3] << endl;
                    //cout << one <<" , " << two <<" , " << three <<" , " << four << endl;
                    int s1 = convert(s,pos[0],one);
                    if ((one == 2 && s1 < 10) || (one == 3 && s1 < 100) || (s1 == 0 && one < 1)) return;
                    int s2 = convert(s,pos[1],two);
                    if ((two == 2 && s2 < 10) || (two == 3 && s2 < 100)|| (s2 == 0 && two < 1)) return;
                    int s3 = convert(s,pos[2],three);
                    if ((three == 2 && s3 < 10) || (three == 3 && s3 < 100)|| (s3 == 0 && three < 1)) return;
                    int s4 = convert(s,pos[3],four);
                    if ((four == 2 && s4 < 10) || (four == 3 && s4 < 100)|| (s4 == 0 && four < 1)) return;
                    if (s1 < 256 && s2 < 256 && s3 < 256 && s4 < 256 ) {
                        //cout << one <<" , " << two <<" , " << three <<" , " << four << endl;
                        string temp = to_string(s1)+"."+to_string(s2)+"."+to_string(s3)+"."+to_string(s4);
                        //cout << temp << endl;
                        ans.emplace_back(temp);
                    }
            }
        } else {
            for (int i = start; i < s.size(); i++) {
                pos.emplace_back(i);
                go (start+1,s,pos,ans);
                pos.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        if (s.size() > 12) return ans;
        vector<int>pos;
        go (0,s,pos,ans);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++){
            for (int b=1; b<=3; b++){
                for (int c=1; c<=3; c++){
                    for (int d=1; d<=3; d++){
                        if (a+b+c+d == s.length()) {
                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a+b, c));
                            int D = stoi(s.substr(a+b+c, d));
                                if (A<=255 && B<=255 && 
                                    C<=255 && D<=255){
                                        if ( (ans=to_string(A)+"."+to_string(B)+
                                            "."+to_string(C)+"."+to_string(D)).length()
                                             == s.length()+3){
                                            ret.push_back(ans);
                                        }
                                }
                        }
                    }
                }    
            }
        }    
        
        return ret;
    }
};
