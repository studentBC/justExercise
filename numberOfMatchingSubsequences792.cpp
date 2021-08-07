//my solution which cant find bug ... f***
//i think bug might be use string find .... it might have substring of substring which will misleading us
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        bool found;
        int ans = 0;
        for (string s:words) {
            vector<bool>match(S.size(),false);
            for (int i = 0; i < s.size(); i++) {
                found = false;
                for (int j = 0; j < S.size(); j++) {
                    if (s[i] == S[j]) {
                        match[j] = true;
                        found = true;
                    }
                }
                if (!found) break;
            }
            if (found) {
                string temp = "";
                int number[26] = {0};
                for (int i = 0; i < match.size(); i++) {
                    if(match[i]) {
                        temp.push_back(S[i]);
                        number[S[i]-'a']++;
                    }
                }
                for (int i = 0; i < s.size(); i++) {
                    number[s[i]-'a']--;
                    if (number[s[i]-'a'] < 0) found = false;
                }
                //cout << temp << " , " << s << endl;
                if (found && temp.size() >= s.size()) {
                    if (temp.find(s)!=std::string::npos) ans++;
                } 
            }
        }
        return ans;
    }
};
//bug free solution beat 88%
class Solution {
    bool isSubseq(const string& s,const string& w) {
        for(int i=0,j=0;i<w.size();++i,j++){
            j=s.find_first_of(w[i],j);
            if(j==string::npos)
                return false;
        }
        return true;
    }
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res=0;
        for(auto& w:words){
            if(isSubseq(S,w))
                res++;
        }
        return res;
    }
};
//76ms solution
static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int N = words.size();
        int current_index[N] = {0};
        queue <int> next[26];
        for(int i = 0; i < N; i++)
            next[words[i][0] - 'a'].push(i);
        for(const auto& character : S)
        {
            int temp = next[character - 'a'].size();
            for(int i = 0; i < temp; i++)
            {
                int word_index = next[character - 'a'].front();
                next[character - 'a'].pop();
                current_index[word_index]++;
                if(current_index[word_index] < words[word_index].length())
                    next[words[word_index][current_index[word_index]] - 'a'].push(word_index);
            }
        }
        int matching_subsequences = 0;
        for(int i = 0; i < N; i++)
            if(current_index[i] == words[i].length())
                matching_subsequences++;
        return matching_subsequences;
    }
};
//beat 95%
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<const char*> waiting[128];
		for (string& s : words) waiting[s[0]].push_back(s.c_str());
        for (char c : s) {
			vector<const char*> next = waiting[c];
			waiting[c].clear();
			for (const char* ss : next) waiting[*++ss].push_back(ss);
        }
        return waiting[0].size();
    }
};
