class Solution {
public:
    static bool strcmp (string a, string b) {
        return a.size() < b.size();
    }
    vector<string> commonChars(vector<string>& A) {
        vector<string>ans;
        sort(A.begin(),A.end(), strcmp);
        for (int j = 0; j < A.size(); j++) {
            sort(A[j].begin(), A[j].end());
        }
        size_t found;
        bool notfound;
        vector<size_t>pos;
        string str;
        //cout <<"use: " << A[0] << endl;
        for (int i = 0; i < A[0].size(); i++) {
            notfound = false;
            pos.clear();
            for (int j = 1; j < A.size(); j++) {
                found = A[j].find(A[0][i]);
                if (found == string::npos) {
                    notfound = true;
                    break;
                } else {
                    pos.push_back (found);
                }
            }
            if (!notfound) {
                for (int j = 1; j < A.size(); j++) {
                    A[j][pos[j-1]] = '$';
                    //cout <<"become: " << A[j] << endl;
                }
                str = A[0][i];
                ans.push_back(str);
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        char common_count[256];
        for(char c = 'a'; c <= 'z'; c++)
            common_count[c] = 0;
        {
            const string& s = A[0];
            int SN = s.length();
            for(int c = 0; c < SN; c++)
            {
                common_count[ s[c] ]++;
            }
        }
        
        int N = A.size();
        for(int i = 1; i < N; i++)
        {
            char repeat_count[256];
            for(char c = 'a'; c <= 'z'; c++)
                repeat_count[c] = 0;
            
            const string& s = A[i];
            int SN = s.length();
            for(int c = 0; c < SN; c++)
            {
                repeat_count[s[c]]++;
            }
            
            for(unsigned char c = 'a'; c <= 'z'; c++)
                if(repeat_count[c] < common_count[c])
                    common_count[c] = repeat_count[c];
        }
        
        vector<string> ret;
        for(char c = 'a'; c <= 'z'; c++)
        {
            if(int rep_end = common_count[c])
            {
                for(int rep = 0; rep < rep_end; rep++)
                    ret.push_back(string(1, c));
            }
        }
        
        return ret;
    }
    
};
