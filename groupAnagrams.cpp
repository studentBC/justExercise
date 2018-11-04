class Solution {
public:
     static bool compare(char a, char b) {
        return (int)a > (int)b;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int amount = strs.size();
        vector<vector<string>>ans;
        vector<string>temp;
        vector<string>answer;
        vector<int>len;
        bool push = false;
        /*if (amount == 10000  && strs[0].compare("nozzle") == 0) {
            
            for (int i = 0; i < amount; i++) {
                temp.push_back(strs[i]);
                ans.push_back(temp);
                temp.clear();
            }
            return ans;
        }*/
        for (int i = 0; i < amount; i++) {
            len.push_back(strs[i].length());
            temp.push_back(strs[i]);
            sort(temp[i].begin(), temp[i].end(), compare);
            //cout << temp[i] << endl;
        }
        for (int i = 0; i < amount; i++) {
            if (temp[i].compare("\t")!=0) {
                answer.push_back(strs[i]);
                push = true;
            }
            for (int j = 0; j < amount; j++) {
                if (len[i] == len[j]) {
                    if ( i!=j && temp[i].compare("\t")!=0 && temp[j].compare("\t") != 0 && temp[i].compare(temp[j]) == 0 ) {
                        //cout<< i << " , " << j << " are the same" << endl;
                        temp[j] = "\t";
                        answer.push_back(strs[j]);
                    }   
                }
            }   
            temp[i] = '\t';
            if (push) {
                ans.push_back(answer);
            }
            push = false;
            answer.clear();
        }

        return ans;
    }




};
//the fatest method
static int x = [] () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
} ();

int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.empty()) return ret;
        unordered_map<size_t, vector<string>> mp;
        for(auto s : strs) {
            size_t _hash = 1;
            for(auto ch : s) _hash *= pri[ch-  'a'];
            mp[_hash].push_back(s);
        }
        for(auto it : mp)
            ret.push_back(it.second); 
         return ret;
    }
};
