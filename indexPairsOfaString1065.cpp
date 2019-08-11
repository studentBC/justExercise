/*
Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] is in the list of words.

 

Example 1:

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
Example 2:

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: 
Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].
 

Note:

All strings contains only lowercase English letters.
It's guaranteed that all strings in words are different.
1 <= text.length <= 100
1 <= words.length <= 20
1 <= words[i].length <= 50
Return the pairs [i,j] in sorted order (i.e. sort them by their first coordinate in case of ties sort them by their second coordinate).
*/
class Solution {
public:
    static bool compare (pair<int,int>&a , pair<int,int>&b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        size_t found = 0;
        vector<pair<int,int>>pos;
        int len;
        for (string str: words) {
            found = text.find(str);
            len = str.size()-1;
            while (found!=std::string::npos) {
                pos.emplace_back(pair<int,int>(found, found+len));
                found = text.find(str, found+1);
            }
        }
        sort(pos.begin(), pos.end(), compare);
        vector<vector<int>>ans;
        for (auto& it: pos) {
            vector<int>temp{it.first, it.second};
            ans.emplace_back(temp);
        }
        return ans;
    }
};
//the fatest method
class TrieNode {
    public:
    bool isword;
    int length;
    TrieNode* children[26];
    
    TrieNode(int n) {
        this->length=n;
        isword=false;
        memset(children, 0, 26*sizeof(TrieNode*));
    }
};

class Trie {
    public:
    TrieNode* root;
    Trie() {
        root=new TrieNode(0);
    }
    void insert(string word) {
        TrieNode* cur=root;
        for(auto& c : word) {
            if(cur->children[c-'a']==NULL) cur->children[c-'a'] = new TrieNode(cur->length+1);
            cur=cur->children[c-'a'];
        }
        cur->isword=true;
    }
    void searchIdx(string& text,vector<vector<int>>& res){
        TrieNode* p=root;
        
        for(int j=0;j<text.size();j++){
            if(p->children[text[j]-'a']==NULL) continue;
            int idx=j;
            TrieNode* k=p->children[text[j]-'a'];
            while(idx<text.size()&&k!=NULL){
                if(k->isword) {
                    res.push_back({idx-k->length+1,idx});
                    cout<<k->length<<endl;
                }
                ++idx;
                if(idx>=text.size()) break;
                k=k->children[text[idx]-'a'];                
            }
        }
        sort(res.begin(),res.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]) return b[1]>a[1];
            return b[0]>a[0]; 
        });
    }
}; 


class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        Trie* t=new Trie;
        for(auto& w:words){
            t->insert(w);
        }
        t->searchIdx(text,res);
        return res;
    }
};
