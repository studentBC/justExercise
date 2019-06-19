class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
		vector<int>target(26,0);
		for (char c:licensePlate) {
			if (isalpha(c)) {
				c = tolower(c);
				target[c-'a']++;
			}
		}
		bool m;
		int length = INT_MAX;
		string ans;
		for (string s:words) {
			vector<int>temp(target);
			for (char c:s) {
				temp[c-'a']--;
			}
			m = true;
			for (int i = 0; i < 26; ++i) {
				if (temp[i] > 0) {
					m = false;
					break;
				}
			}
			if (m && length > s.size()) {
				length = s.size();ans = s;
			}
		}
		return ans;
    }
};
//the fatest method
class Solution {
public:
    void count(string& str, int* table){
        for(char c : str){
            char upper = c & (~0x20);
            if(upper >= 'A' && upper <= 'Z') 
                table[upper - 'A']++;
        }
    }
    
    bool compare(int* ref, int* curr, const int size){
        for(int idx = 0;idx < size;idx++){
            if(ref[idx] > curr[idx]){
                return false;
            }
        }
        return true;
    }
    
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int minLen = INT_MAX, refTable[26] = {0}, currTable[26];
        string complete;
        
        count(licensePlate, refTable);
        
        for(string word : words){
            memset(currTable, 0, sizeof(currTable));
            count(word, currTable);
            if(compare(refTable, currTable, 26) && minLen > word.size()){
                minLen = word.size();
                complete = word;
            }
        }
        
        return complete;
    }
};
