class Solution {
public:
    char findTheDifference(string s, string t) {
 		int map[26] = {0};
		for (int i = 0; i < s.length(); i++) {
			map[s[i]-'a']++;
		}
		int index;
		for (int j = 0; j < t.length(); j++) {
			index = t[j]-'a';
			map[index]--;
			if (map[index] < 0) return t[j];
		}
		return t[0];
    }
};
//the fatest method
class Solution {
public:
    char findTheDifference(string s, string t) {
        int array[26] = {0};
        for(int i = 0; i < s.size(); i++)
        {
            array[(s.at(i) - 97)]++;
        }
        
        for(int i = 0; i < t.size(); i++)
        {
            if(array[t.at(i)-97] <= 0)
            {
                return t.at(i);
            }
            array[t.at(i)-97]--;
        }
        return 'a';
    }
};
