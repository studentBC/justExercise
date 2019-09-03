/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]
n = 4
["1001","1111","1691","1881","1961","6009","6119","6699","6889","6969","8008","8118","8698","8888","8968","9006","9116","9696","9886","9966"]
*/
class Solution {
public:
    void go (int left, int right, vector<char>& temp, vector<char>& candidate, vector<string>& ans) {
        if (left == right) {
            char mid[3] = {'0','1','8'};
            for (int i = 0; i < 3; i++) {
                temp[left] = mid[i];
                string s(temp.begin(), temp.end());
                //cout << s << endl;
                ans.emplace_back(s);
            }
        }  else if (left < right) {
            int start = 0;
            if (temp.size() > 1 && left == 0) {
                start = 1;
            }
            for (int i = start; i < candidate.size(); i++) {
                if (candidate[i] == '6') {
                    temp[left] = '6';temp[right] = '9';
                } else if (candidate[i] == '9') {
                    temp[left] = '9';temp[right] = '6';
                } else {
                    temp[left] = temp[right] = candidate[i];
                }
                go (left+1, right-1, temp, candidate, ans);
            }            
        } else {
            string s(temp.begin(), temp.end());
            //cout << s << endl;
            ans.emplace_back(s);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        vector<char>candidate{'0','1','6','8','9'};
        vector<char>temp(n);
        vector<string>ans;
        go (0, n-1, temp, candidate, ans);
        return ans;
    }
};
//the 20 ms method
class Solution {
private:
    vector<char> first = {'0','1','6','8','9'},second = {'0','1','9','8','6'};
public:
    //0 1 2 3 4 5 6 7 8 9
    //0 1 69 8
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        string s(n,'0');
        BackTracking(res,s,0,n/2);
        return res;
    }
    void BackTracking(vector<string>& res, string& cur,int index,int upper_bound){
        if(index == upper_bound){
            res.push_back(cur);
            if(index * 2 == cur.size())
                return;
            cur[index] = '1';
            res.push_back(cur);
            cur[index] = '8';
            res.push_back(cur);
            cur[index] = '0';
            return;
        }
        int start_mask = (index == 0) ? 1 : 0;
        for(int i = start_mask;i<5;i++){
            cur[index] = first[i];
            cur[cur.size()-1-index] = second[i];
            BackTracking(res,cur,index+1,upper_bound);
            cur[index] = '0';
            cur[cur.size()-1-index] = '0';
        }
    }
};
