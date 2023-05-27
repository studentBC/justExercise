/*
We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode" can be represented as arr = ["I","am",happy","with","leetcode"].

Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string pairs similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

Return true if sentence1 and sentence2 are similar, or false if they are not similar.

Two sentences are similar if:

They have the same length (i.e., the same number of words)
sentence1[i] and sentence2[i] are similar.
Notice that a word is always similar to itself, also notice that the similarity relation is transitive. For example, if the words a and b are similar, and the words b and c are similar, then a and c are similar.

 

Example 1:

Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.
Example 2:

Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","onepiece"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: true
Explanation: "leetcode" --> "platform" --> "anime" --> "manga" --> "onepiece".
Since "leetcode is similar to "onepiece" and the first two words are the same, the two sentences are similar.
Example 3:

Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","hunterXhunter"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: false
Explanation: "leetcode" is not similar to "onepiece".
 

Constraints:

1 <= sentence1.length, sentence2.length <= 1000
1 <= sentence1[i].length, sentence2[i].length <= 20
sentence1[i] and sentence2[i] consist of lower-case and upper-case English letters.
0 <= similarPairs.length <= 2000
similarPairs[i].length == 2
1 <= xi.length, yi.length <= 20
xi and yi consist of English letters.
*/


class Solution {
public:
    class UnionFind {
        public:
            unordered_map<string, string>id;
            unordered_map<string, int>rank;
            UnionFind() {

            }
            void connect (string a, string b) {
                string ar = find(a);
                string br = find(b);
                if (ar == br) return;
                if (rank[ar] < rank[br]) {
                    id[ar] = br;
                } else if (rank[ar] > rank[br]) {
                    id[br] = ar;
                } else {
                    id[ar] = br;
                    rank[br]++;
                }
            }
            string find(string a) {
                return id[a] == a? a : (id[a] = find(id[a]));
            }
            bool connected (string a, string b) {
                return find(a) == find(b);
            }
    };
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size()!=sentence2.size()) return false;
        UnionFind uf;
        for (int i = 0; i < similarPairs.size(); i++) {
            uf.id[similarPairs[i][0]] = similarPairs[i][0];
            uf.id[similarPairs[i][1]] = similarPairs[i][1];
        }
        for (int i = 0; i < sentence1.size(); i++) {
            uf.id[sentence1[i]] = sentence1[i];
            uf.id[sentence2[i]] = sentence2[i];
        }
        for (int i = 0; i < similarPairs.size(); i++) {
            uf.connect(similarPairs[i][0], similarPairs[i][1]);
        }
        for (int i = 0; i < sentence1.size(); i++) {
            //cout << i <<", ";
            if(!uf.connected(sentence1[i], sentence2[i])) return false;
        }
        return true;
    }
};
