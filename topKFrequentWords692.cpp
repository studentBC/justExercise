class Solution {
public:
    static bool compare (pair<string,int>a , pair<string,int>b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>dict;
        auto it = dict.begin();
        for (int i = 0; i < words.size(); i++) {
            it = dict.find(words[i]);
            if (it == dict.end()) {
                dict.insert(pair<string,int>(words[i],1));
            } else {
                it->second++;
            }
        }
        vector<pair<string,int>>temp(dict.begin(),dict.end());
        sort(temp.begin(), temp.end(), compare);
        vector<string>ans;
        for (int i = 0; i < k; i++) {
            ans.emplace_back (temp[i].first);
        }
        return ans;
    }
};
//the fatest method
void beforeMain(void) __attribute__((constructor));

void beforeMain(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

class Solution {
 public:
  vector<string> topKFrequent(const vector<string>& words, int k) {
    typedef std::pair<string, int> keyVal;
    std::unordered_map<string, int> Freq;
    for (const string& word : words) {
      ++Freq[word];
    }
    vector<keyVal> M;
    M.reserve(Freq.size());
    for (const auto& e : Freq) {
      M.emplace_back(e);
    }
    // M.shrink_to_fit();
    auto cmp =  [&](const keyVal& a, const keyVal& b) {
      return a.second < b.second || (a.second == b.second && a.first > b.first);
    };
    std::make_heap(M.begin(), M.end(),cmp);

    vector<string> res;
    res.reserve(Freq.size());
    for (int i = 0; i < k; ++i) {
      std::pop_heap(M.begin(), M.end(), cmp );
      res.emplace_back(M.back().first);
      M.pop_back();
    }
    // res.shrink_to_fit();
    return res;
  }
};
