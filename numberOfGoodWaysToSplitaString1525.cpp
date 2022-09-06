class Solution {
public:
    int numSplits(string s) {
        vector<vector<int>>alpha;
        vector<int>num(26,0);
        num[s[0]-'a'] = 1;
        alpha.push_back(num);
        for (int i = 1; i < s.size(); i++) {
            vector<int>tmp(alpha.back().begin(), alpha.back().end());
            tmp[s[i]-'a']++;
            alpha.push_back(tmp);
        }
        int left, right, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            left = right = 0;

            for (int k = 0; k < 26; k++) {
                if (alpha[i][k]) left++;
            }
            
            
            for (int k = 0; k < 26; k++) {
                if (alpha.back()[k]-alpha[i][k]) right++;
            }
            
            if (left == right) ans++;
        }
        return ans;
    }
};
//4 ms solution
class Solution {
public:
    int numSplits(string s)
    {
        int n=s.size();
        
        int freq[26];
        memset(freq, 0, sizeof(freq));
        
        int lr[n],rl[n];
        lr[0]=1;
        freq[s[0]-'a']=1;
        for(int i=1;i<n;i++)
        {
            if(freq[s[i]-'a']==0)
            {
                lr[i]=lr[i-1]+1;
                freq[s[i]-'a']=1;
            }
            else
            {
                lr[i]=lr[i-1];
            }
        }
        memset(freq, 0, sizeof(freq));
        freq[s[n-1]-'a']=1;
        rl[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(freq[s[i]-'a']==0)
            {
                rl[i]=rl[i+1]+1;
                freq[s[i]-'a']=1;
            }
            else
            {
                rl[i]=rl[i+1];
            }
        }
        
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(lr[i]==rl[i+1])
            {
                count++;
            }
        }
        return count;
    }
};
//my solution on 2022 beats 90%
class Solution {
public:
    int numSplits(string s) {
        unordered_set<char>l, r;
        int len = s.size(), mid, count = 0;
        vector<int>left(len), right(len);
        for (int i = 0; i < len; i++) {
            l.insert(s[i]);
            left[i] = l.size();
        }
        //if (left.back()%2) return 0;
        mid = left.back()/2;
        for (int i = len-1; i > -1; i--) {
            r.insert(s[i]);
            right[i] = r.size();
        }
        len--;
        // for (int i = 0; i <= len; i++) {
        //     cout << left[i] <<", ";
        // }
        // cout << endl;
        // for (int i = 0; i <= len; i++) {
        //     cout << right[i] <<", ";
        // }
        for (int i = 0; i < len; i++) {
            if (left[i] == right[i+1]) count++;
        }
        return count;
    }
};
