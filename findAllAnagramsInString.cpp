class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int target[26] = {0};
        for (int i = 0; i < p.size(); i++) {
            target[p[i]-'a']++;
        }
        
        bool record;
        int* temp;
        int end = s.size() - p.size();
        vector<int> ans;
        for (int i = 0; i <= end; i++) {
            temp = (int*)calloc(26,sizeof(int));
            for (int j = 0; j < p.size(); j++) {
                temp[s[j+i]-'a']++;
            }
            record = true;
            for (int k = 0; k < 26; k++) {
                if (temp[k] != target[k]) {
                    record = false;
                    break;
                }
            }
            free(temp);
            if (record) ans.push_back(i);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> pv(26,0);
        vector<int> ps(26,0);
        int plen = p.length();
        for(char ch : p)
            ps[ch-'a']++;
        for(int i=0; i<s.length(); i++)
        {
            
                
            if(i >= plen)
            {
                pv[s[i-plen]-'a']--;
                
            }
            pv[s[i]-'a']++;
            if(ps==pv && i>= plen-1)
                result.push_back(i-plen+1);
        }
        return result;
    }
};
