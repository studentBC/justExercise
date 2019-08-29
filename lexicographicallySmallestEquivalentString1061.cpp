/*
Given strings A and B of the same length, we say A[i] and B[i] are equivalent characters. For example, if A = "abc" and B = "cde", then we have 'a' == 'c', 'b' == 'd', 'c' == 'e'.

Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'
Symmetry: 'a' == 'b' implies 'b' == 'a'
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'
For example, given the equivalency information from A and B above, S = "eed", "acd", and "aab" are equivalent strings, and "aab" is the lexicographically smallest equivalent string of S.

Return the lexicographically smallest equivalent string of S by using the equivalency information from A and B.

 

Example 1:

Input: A = "parker", B = "morris", S = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in A and B, we can group their characters as [m,p], [a,o], [k,r,s], [e,i]. The characters in each group are equivalent and sorted in lexicographical order. So the answer is "makkek".
Example 2:

Input: A = "hello", B = "world", S = "hold"
Output: "hdld"
Explanation:  Based on the equivalency information in A and B, we can group their characters as [h,w], [d,e,o], [l,r]. So only the second letter 'o' in S is changed to 'd', the answer is "hdld".
Example 3:

Input: A = "leetcode", B = "programs", S = "sourcecode"
Output: "aauaaaaada"
Explanation:  We group the equivalent characters in A and B as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in S except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
 

Note:

String A, B and S consist of only lowercase English letters from 'a' - 'z'.
The lengths of string A, B and S are between 1 and 1000.
String A and B are of the same length.

wrong test case:
"dfeffdfafbbebbebacbbdfcfdbcacdcbeeffdfebbdebbdafff"
"adcdfabadbeeafeabbadcefcaabdecabfecffbabbfcdfcaaae"
"myickvflcpfyqievitqtwvfpsrxigauvlqdtqhpfugguwfcpqv"
*/
class UnionFind {
public:
    int* parent;
    UnionFind() {
        parent = new int[26];
        for (int i = 0; i < 26; i++) parent[i] = -1;
    }

    int Find(int child) {
        if(parent[child] < 0){
            parent[child] = child;
        }
        
        return parent[child] == child ? child : parent[child] = Find(parent[child]);
    }
    
    bool Union(int c1, int c2){
        int p1 = Find(c1);
        int p2 = Find(c2);
        if(p1 == p2) return false;
        if (p1 > p2) { 
            parent[p1] = p2;
        } else {
            parent[p2] = p1;
        }
        return true;
    }
};
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        UnionFind uf;
        vector<vector<char>>cc;
        bool found;
        for (int i = 0; i < A.size(); i++) {
            uf.Union(A[i]-'a', B[i]-'a');
        }
        string ans;
        for (char c:S) {
            ans+=(uf.Find(c-'a')+'a');
        }
        return ans;
    }
};

//the fatest method
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        for(int i = 0 ; i < 128; i++) {
            vroot[i] = i;
        }
        
        for(int i = 0; i < A.size(); i++) {
            join(A[i], B[i]);
        }
        
        for(auto& c: S) {
            c = root(c);
        }
        
        return S;
    }
    
    void join(int i, int j) {
        auto ri = root(i);
        auto rj = root(j);
        vroot[max(ri, rj)] = min(ri, rj);
    }
    
    int root(int i) {
        if(vroot[i] != i) vroot[i] = root(vroot[i]);
        return vroot[i];
    }
    
    vector<int> vroot= vector<int>(128, 0);
};
