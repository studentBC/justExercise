class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
 		if (magazine.size() < ransomNote.size())return false;
		bool found = false;
		for (int i = 0; i < ransomNote.size(); i++) {
			found = false;
			for (int j = 0; j < magazine.size(); j++) {
				if (ransomNote[i] == magazine[j]) {
					magazine[j] = '$';
					found = true;
					break;
				}
			}
			if (!found) {
				return false;
			}
		}
		return true;
    }
};
