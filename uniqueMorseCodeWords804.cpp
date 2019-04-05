class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>ans;
        string temp;
        for (int i = 0; i < words.size(); i++) {
            temp = "";
            for (int j = 0; j < words[i].size(); j++) {
                temp+=morse[words[i][j]-'a'];
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};
