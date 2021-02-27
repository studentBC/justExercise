class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9+7, c = 1;
        long long sum = 0;
        vector<unordered_map<long,long>>count(26);
        s+="$";
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                c = 1;
            } else if (s[i-1] == s[i]) {
                c++;
            } else {
                count[s[i-1]-'a'][c]++;
                c = 1;
            }
        }
        for (int i = 0; i < 26; i++) {
            for (auto& it: count[i]) {
                if (it.first > 1) sum+=it.second*((it.first+1)*it.first/2);
                else sum+=(it.first*it.second);
                sum%=mod;
            }
        }
        return sum;
    }
};
//the fatest solution
class Solution {
public:
int countHomogenous(string s)
{
    if (s.length() == 0)
        return 0;

    vector<unordered_map<int, int> > charCount(26);

    int sameCharLen = 0;
    char prev = '0';
    for (int i = 0; i < s.length(); ++i)
    {
        char curr = s[i];
        if (i > 0 && curr != prev)
        {
            // find prev of length sameCharLen
            if (charCount[prev - 'a'].count(sameCharLen) > 0)
            {
                charCount[prev - 'a'][sameCharLen]++;
            }
            else
            {
                charCount[prev - 'a'][sameCharLen] = 1;
            }

            sameCharLen = 1;
        }
        else
        {
            sameCharLen++;
        }

        prev = curr;
    }

    if (charCount[prev - 'a'].count(sameCharLen) > 0)
    {
        charCount[prev - 'a'][sameCharLen]++;
    }
    else
    {
        charCount[prev - 'a'][sameCharLen] = 1;
    }

    int res = 0;
    for (int i = 0; i < 26; ++i)
    {
        unordered_map<int, int> &count = charCount[i];
        for (auto iter = count.begin(); iter != count.end(); ++iter)
        {
            //cout << char('a' + i) << " length " << iter->first << " count " << iter ->second << endl;
            long newCount = ((long)iter->first * (long)(iter->first+1) / 2) * (long)(iter->second);
            
            res = ((long)res + newCount) % 1000000007;
        }
    }

    return res;
}
};
