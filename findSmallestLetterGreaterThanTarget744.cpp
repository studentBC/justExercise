class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
 		for (int i = 0; i < letters.size(); i++) {
			if (letters[i]>target) return letters[i];
		}
		return letters[0];
    }
};
//the fatest method
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        if (letters[size-1] <= target) return letters[0];
        return *upper_bound(letters.begin(), letters.end(), target);
    }
};

static int ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
