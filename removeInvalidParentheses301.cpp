class Solution {
public:
    void go (int start, int end, int count, string s, vector<bool>mark, vector<string>& ans, int& length) {
        if (count == 0 || start+1 == s.size() ) {
            string temp = "";
            for (int i = 0; i < mark.size(); i++) {
                if (mark[i] || (s[i] != '(' && s[i] != ')')) {
                    temp+=s[i];
                }
            }
            //cout << temp << " : " << temp.size() << " length " << length << endl;
            int len = temp.size();
            if (len >= length) {
                length = temp.size();
                if (find(ans.begin(),ans.end(),temp) == ans.end())
                    ans.push_back(temp);
            }
        } else {
            for (int i = start; i < s.size(); i++) {
                if (s[i] == '(' && !mark[i]) {
                    mark[i] = true;
                    for (int j = i+1; j < s.size(); j++) {
                        if (s[j] == ')' && !mark[j]) {
                            mark[j] = true;
                            //count--;
                            //cout << "find at " << i << " and " << j << endl;
                            go (i,j,count-1,s,mark,ans, length);
                            mark[j] = false;
                        }
                    }
                    mark[i] = false;
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string temp = "";
        vector<string>ans;
        vector<bool>mark(s.size(),false);
        int length = -1, count = 0;
        stack<char>parenthese;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                parenthese.push(s[i]);
            } else if (s[i] == ')') {
                if (!parenthese.empty() && parenthese.top() == '(') {
                    parenthese.pop();
                    count++;
                }
            }
        }
        //cout << "there are " << count << " parenthese" << endl;
        go (0,-1,count,s,mark,ans,length);
        if (ans.size() == 0) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '(' && s[i] != ')') {
                    temp+=s[i];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//the fatest method
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long i64;
#define pb push_back
#define fi first
#define se second

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
  	int left_c = 0, right_c = 0;
  	for(int i=0; i<s.length(); i++) {
  		if(s[i] == '(') left_c++;
  		else if(s[i] == ')') {
  			if(left_c <= 0) right_c++;
  			else left_c--; 
  		}
  	}
  	vector<string> res;
  	dfs(0,left_c,right_c,s,res);
  	return res;
  }
  void dfs(int start, int left_c, int right_c, string str, vector<string> &res) {
  	if(left_c == 0 && right_c == 0){
  		// cout << "came " << str << " " << is_valid(str) <<  endl;
  		if(is_valid(str)) res.pb(str);
  		return;	
  	}
  	for(int i=start; i<str.length(); i++) {
  		if(right_c == 0 && left_c > 0 && str[i]=='(') {
  			if(i == start || str[i] != str[i-1]) {
  				string to_send = str;
  				to_send.erase(i,1);
  				dfs(i, left_c-1, right_c, to_send, res);
  			}
  		}
  		else if(right_c > 0 && str[i] == ')') {
  			if(i == start || str[i] != str[i-1]) {
  				string to_send = str;
  				to_send.erase(i,1);
  				dfs(i, left_c, right_c-1, to_send, res);
  			}
  		}
  	}
  }
  int is_valid(string str) {
  	int count = 0;
  	for(auto s: str) {
  		if(s=='(') count++;
  		else if(s==')') count--;
  		if(count<0) return 0;
  	}
  	return count==0;
  }
};
