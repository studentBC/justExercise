/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/
class Solution {
public:
    void go (int index, vector<bool>& visited, vector<vector<int>>& graph, vector<char>& ans) {
        // Mark the current node as visited.
        visited[index] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < graph[index].size(); ++i)
            if (!visited[graph[index][i]]) go(graph[index][i], visited, graph, ans);

        // Push current vertex to stack which stores result
        ans.push_back(index+'a');
    }
    void getvalid (int index, vector<bool>& visited, vector<vector<int>>& graph, vector<int>& rank, int prev, bool& invalid) {
        if (visited[index] || invalid) return;
        //cout << rank[index] <<" , ";
        if (rank[index] < prev) {
            invalid = true;
            return;
        }
        visited[index] = true;
        for (int i = 0; i < graph[index].size(); i++) {
            getvalid (graph[index][i], visited, graph, rank, rank[index], invalid);
        }
    }
    string alienOrder(vector<string>& words) {
        vector<vector<int>>graph;
        vector<int>temp;vector<char> ans;
        vector<bool>visited(26,true);
        vector<bool>unique(26,false);
        int len , index, tmp;
        for (int i = 0; i < 26; i++) {
            graph.emplace_back(temp);
        }
        int end, longest = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) unique[words[i][j]-'a'] = true;
            for (int j = i+1; j < words.size(); j++) {
                len = min(words[i].size(), words[j].size());
                for (int k = 0; k < len; k++) {
                    if (words[i][k] != words[j][k]) {
                        index = words[i][k]-'a';
                        tmp = words[j][k]-'a';
                        visited[index] = visited[tmp] = false;
                        if (find(graph[index].begin(), graph[index].end(), tmp) == graph[index].end()) {
                            graph[index].emplace_back(tmp);
                        }
                        break;
                    }
                }
            }
        }
        string strr = "";
        for (int i = 0; i < 26; i++) {
            if (!visited[i]) {
                go (i,visited,graph, ans);
            }
        }
        reverse(ans.begin(), ans.end());
        string str (ans.begin(), ans.end());
        vector<int>rank(26,-1);
        for (int i = 0; i < str.size(); i++) {
            unique[str[i]-'a'] = false;
            rank[str[i]-'a'] = i;
        }
        bool invalid = false;
        //cout << str;
        for (int i = 0; i < str.size(); i++) {
            vector<bool>beenTo(26, false);
            //cout <<endl <<"start from : " << str[i] << endl;
            getvalid(str[i]-'a', beenTo, graph, rank, INT_MIN, invalid);
            if (invalid) return "";
        }
        for (int i = 0; i < 26; i++) {
            if (unique[i]) {
                //cout << i <<" is loss" << endl;
                str+=(i+'a');
            }
        }
        return str;
    }

};
//the fatest method
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> suc, pre;
        unordered_set<char> s;
        string prevWord;
        for (auto word : words) {
            s.insert(word.begin(), word.end());
            for (int i = 0; i < min(prevWord.size(), word.size()); i++) {
                if (prevWord[i] != word[i]) {
                    suc[prevWord[i]].insert(word[i]);
                    pre[word[i]].insert(prevWord[i]);
                    break;
                }
            }
            prevWord = word;
        }
        int n = s.size();
        for (auto i : pre) {
            s.erase(i.first);
        }
        string order;
        while (!s.empty()) {
            char c = *s.begin();
            for (auto i : suc[c]) {
                pre[i].erase(c);
                if (pre[i].empty())
                    s.insert(i);
            }
            order += c;
            s.erase(c);
        }
        return order.size() == n ? order : "";
    }
};
