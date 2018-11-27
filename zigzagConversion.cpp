class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows <= 1) return s;
        vector<vector<char>>pattern(numRows);
        int len = (numRows-1)*2 , a = numRows-2;
        int count[len];
        for (int i = 0; i < numRows; i++) {
            count[i] = i;
        }
        for (int i = numRows; i < len; i++) {
            count[i] = a;
            a--;
        }
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            pattern[count[i%len]].push_back(s[i]);
        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < pattern[i].size(); j++) {
                cout << pattern[i][j];
                ans+=pattern[i][j];
                //ans.append((string)pattern[i][j]);
            }
        }
        return ans;
    }
};
//fatest method
static auto x = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if(numRows==1)
            return s;
        for(int i = 0 ; i< numRows; i++)
        {
            //cout << i << endl;
            for(int j = i ; j < s.size(); j+=2*(numRows-1))
            {
                
                //cout << i << "," << j <<s[j]<<endl;
                result+= s[j];
                if(i>0 && i<numRows-1){
                    if(2*(numRows-i-1)+j< s.size())
                        result+=s[2*(numRows-i-1)+j];
                    //cout<< i << "," << j<< ", "<<2*(numRows-i-1)+j <<s[2*(numRows-i-1)+j]<<"!"<<endl;
                }
            }
        }
        return result;
    }
};
