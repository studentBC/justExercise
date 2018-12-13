class Solution {
public:
    bool stoneGame(vector<int>& piles) {
		return true;
		/*
		if (piles.size() == 1) return true;
		int half = piles.size()/2;
		int alex = 0, lee = 0;
		for (int i = 0; i < half; i++) {
			//alex turn
			if (piles[0] > piles[piles.size()-1]) {
				alex+=piles[0];
				piles.erase(piles.begin());
			} else {
				alex+=piles[piles.size()-1];
				piles.pop_back();
			}
			//lee turns
			if (piles[0] > piles[piles.size()-1]) {
				lee+=piles[0];
				piles.erase(piles.begin());
			} else {
				lee+=piles[piles.size()-1];
				piles.pop_back();
			}
		}
		if (alex > lee) {
			return true;
		} else {
			return false;
		}
		*/
    }
};
