/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match (string target, string a) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == target[i]) count++;
        }
        return count;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int hit;
        string gg;
        for (int i = 0; i < 10; i++) {
            unordered_map<string, int> count;
            for (string w1 : wordlist)
                for (string w2 : wordlist)
                    if (match(w1, w2) == 0)
                        count[w1]++;
            pair<string, int> minimax = make_pair(wordlist[0], 1000);
            for (string w : wordlist)
                if (count[w] <= minimax.second)
                    minimax = make_pair(w, count[w]);
            gg = minimax.first;
            hit = master.guess(gg);
            //cout << hit <<" , ";
            if (hit == 6) return;
            vector<string>possible;
            for (int i = 0; i < wordlist.size(); i++) {
                if (match(gg, wordlist[i]) == hit) {
                    possible.emplace_back(wordlist[i]);
                }
            }
            wordlist = possible;
        }
    }
};
//the fatest solution
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int check(string a,string b){
        int ret=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i])
                ret++;
        }
        return ret;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        set<string>allWords,tmp;
        
        for(auto s : wordlist)
            allWords.insert(s);
        
        for(int count=1;count<=10;count++){
            string now = *allWords.begin();
            
            int match= master.guess(now);
            
            if(match==6)break;
            
            tmp.clear();
            for(auto s : allWords){
                if(check(s,now)==match)
                    tmp.insert(s);
            }
            tmp.swap(allWords);
        }
    }
};
//2022/8/21
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int freq[6][26] = {};
    int similarity(string_view s1, string_view s2) {
        int count = 0;
        for(int i = 0; i < 6; ++i) {
            if(s1[i]==s2[i]) ++count;
        }
        return count;
    }
    set<string_view> filter_out(string_view word, int count, const set<string_view>& avail) {
        set<string_view> avail_next;
        for(const auto& s : avail) {
            if(similarity(word, s) == count) {
                avail_next.emplace(s);
            }
        }
        return avail_next;
    }
   //interesting solution it choose the most frequent character as next candidate to elimiate most other or get the right target 
    string_view choose(const set<string_view>& avail) {
        string_view choice;
        int max_score = 0;
        for(const auto& s : avail) {
            int score = 0;
            for(int i = 0; i < 6; ++i) {
                score += freq[i][s[i]-'a'];
            }
            if(score > max_score) {
                choice = s;
                max_score = score;
            }
        }
        return choice;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        set<string_view> avail;
        for(const auto& word : wordlist) {
            avail.emplace(word);
            for(int i = 0; i < 6; ++i) {
                freq[i][word[i]-'a']++;
            }
        }
        
        while(true) {
            auto sv = choose(avail);
            auto guess = string(sv.begin(), sv.end());
            auto count = master.guess(guess);
            if(count == 6) break;
            avail.erase(sv);
            avail = filter_out(guess, count, avail);
        }
    }
};
