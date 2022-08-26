/*
Intuition

Since the length of S is large, let's think about ways to iterate through S only once, instead of many times as in the brute force solution.

We can put words into buckets by starting character. If for example we have words = ['dog', 'cat', 'cop'], then we can group them 'c' : ('cat', 'cop'), 'd' : ('dog',). This groups words by what letter they are currently waiting for. Then, while iterating through letters of S, we will move our words through different buckets.

For example, if we have a string like S = 'dcaog':

heads = 'c' : ('cat', 'cop'), 'd' : ('dog',) at beginning;
heads = 'c' : ('cat', 'cop'), 'o' : ('og',) after S[0] = 'd';
heads = 'a' : ('at',), 'o' : ('og', 'op') after S[0] = 'c';
heads = 'o' : ('og', 'op'), 't': ('t',) after S[0] = 'a';
heads = 'g' : ('g',), 'p': ('p',), 't': ('t',) after S[0] = 'o';
heads = 'p': ('p',), 't': ('t',) after S[0] = 'g';
Algorithm

Instead of a dictionary, we'll use an array heads of length 26, one entry for each letter of the alphabet. For each letter in S, we'll take all the words waiting for that letter, and have them wait for the next letter in that word. If we use the last letter of some word, it adds 1 to the answer.
*/
class Solution {
public:
    struct node {
        string word;
        int index;
        node(string w, int i): word(w), index(i) {};
    };
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        vector<vector<node>> head(26);
        for (string& ss: words) {
            head[ss[0]-'a'].push_back(node(ss, 0));
        }
        for (char c : s) {
            vector<node>temp = head[c-'a'];
            head[c-'a'].clear();
            for (node n : temp) {
                n.index++;
                if (n.index == n.word.size()) ans++;
                else head[n.word[n.index]-'a'].push_back(n);
            }
        }
        return ans;
    }
};
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
