class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        if(words.size() ==0 || s.size() == 0) return ans;
        unordered_map<string,int>count;
        for (string s: words) count[s]++;
        int length = words.size()*words[0].size(), len = words[0].size(), end = s.size()-length;
        string temp;
        bool match;
        for (int i = 0; i <= end; i++) {
            unordered_map<string,int>candidate;
            match = true;
            for (int j = 0, start = i; j < words.size(); j++, start+=len) {
                temp = s.substr(start, len);
                if (count[temp]) {
                    candidate[temp]++;
                    if (candidate[temp] > count[temp]) {
                        match = false;
                        break;
                    }
                } else {
                    match = false;
                    break;
                }
            }
            if (match) ans.emplace_back(i);
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> ret;
        if(!s.size() || !words.size())
            return ret;
        
        size_t words_hash = 0;
        for(const auto& word : words)
            words_hash += hash<string>{}(word);
        
        const int word_size = words[0].size();
        const int num_chars = words.size() * word_size;
        vector<size_t> word_hashes(words.size(), 0);
        
        for(int k = 0; k < word_size; ++k) {
            
            size_t s_hash = 0;
            int num_words = 0;
            
            for(int i = k; i + word_size <= s.size(); i += word_size) {

                size_t h = hash<string_view>{}(string_view(&s[i], word_size))    ;             
                s_hash += h;
                
                if(++num_words < words.size()) {
                    word_hashes[num_words % word_hashes.size()] = h;
                    continue;
                }
                
                if(num_words > words.size())
                    s_hash -= word_hashes[num_words % word_hashes.size()];
                word_hashes[num_words % word_hashes.size()] = h;    
                
                if(s_hash == words_hash)
                    ret.push_back(i+word_size-num_chars);
            }
        }       
        return ret;
    }
};

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
