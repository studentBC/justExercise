class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
		int i = 0;
		bool one = true;
 		while ( i < bits.size()) {
			if (bits[i] == 0) {
				i++;
				one = true;
			} else {
				i+=2;
				one = false;
			}
		}
		return one;
    }
};
