class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<vector<int>>alpha;
        vector<string>ans;
        vector<int>target(26,0);int index;
        for (int i = 0; i < A.size(); ++i) {
            vector<int>temp(26,0);
            for (int j = 0; j < A[i].size(); ++j) {
                temp[A[i][j]-'a']++;
            }
            alpha.emplace_back(temp);
        }
        for (int i = 0; i < B.size(); ++i) {
			vector<int>tmp(26,0);
            for (int j = 0; j < B[i].size(); ++j) {
                index = B[i][j]-'a';
                tmp[index]++;
                target[index] = max (tmp[index], target[index]);
            }
        }
        bool match = false;
        for (int i = 0; i < alpha.size(); ++i) {
            match = true;
            for (int j = 0; j < 26; ++j) {
                if (alpha[i][j] < target[j]) {
                    match = false;
                    break;
                }
            }
            if (match) ans.emplace_back(A[i]);
        }
        return ans;
    }
};
//the fatest method
static auto fast=[]{ios_base::sync_with_stdio(false); cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) 
    {
        vector<string> res;   //resultant vector
        char max_freq[26]={0}; //max frequency of all charcters in all strings in 'B'
        char freq[26];
        for(int i=0;i<B.size();i++)
        {
            memset(freq,0,26);
            for(int k=0;k<B[i].size();k++)
            {
                freq[B[i][k]-'a']++;
                if(freq[B[i][k]-'a']>max_freq[B[i][k]-'a'])
                   max_freq[B[i][k]-'a']=freq[B[i][k]-'a']; 
            }
        }
        char flag;
        for(int i=0;i<A.size();i++)
        {
           memset(freq,0,26);
           for(int k=0;k<A[i].size();k++)
               freq[A[i][k]-'a']++;
           flag=1; 
           for(int k=0;k<26;k++)
           {
               if(max_freq[k]>freq[k])
               {
                   flag=0;
                   break;
               }
           }
           if(flag) res.push_back(A[i]); 
        }
        return res;
    }
};
