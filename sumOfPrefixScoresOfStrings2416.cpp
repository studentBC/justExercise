class Solution {
public:
    class Trie {
        public:
            int count = 0;
            Trie* nodes[26]={};
    };
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie root;
        vector<int>ans;
        for (string& s: words) {
            Trie* n = &root;
            for (char c : s) {
                if (n->nodes[c-'a'] == NULL) {
                    n->nodes[c-'a'] = new Trie;
                }
                n->nodes[c-'a']->count++;
                n = n->nodes[c-'a'];
            }
        }
        for (string& s: words) {
            int sum = 0;
            Trie* n = &root;
            for (char c : s) {
                sum+=n->nodes[c-'a']->count;
                n = n->nodes[c-'a'];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
