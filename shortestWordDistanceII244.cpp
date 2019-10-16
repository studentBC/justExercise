class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
			pos[words[i]].emplace_back(i);
		}
    }
    
    int shortest(string word1, string word2) {
		int ans = INT_MAX;
        for (int i = 0; i < pos[word1].size(); i++) {
			for (int j = 0; j < pos[word2].size(); j++) {
				ans = min (ans, abs(pos[word1][i]-pos[word2][j]));
			}
		}
		return ans;
    }
private:
	unordered_map<string, vector<int>>pos;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
class WordDistance {
private:
  unordered_map<string, vector<int>> wordLocationMap;
public:
  WordDistance(vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
      wordLocationMap[words[i]].push_back(i);
    }
  }

  int shortest(string word1, string word2) {
    auto& location1 = wordLocationMap[word1];
    auto& location2 = wordLocationMap[word2];

    int dist = INT_MAX;
    for (int i = 0, j = 0; i < location1.size() && j < location2.size();) {
      dist = min(dist, abs(location1[i] - location2[j]));

      if (location1[i] < location2[j]) ++i;
      else ++j;
    }

    return dist;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
