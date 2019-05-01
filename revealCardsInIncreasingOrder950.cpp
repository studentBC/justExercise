class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end(),greater<int>());
        vector<int>ans(deck.size(),-1);
        int start = 1, count = 0, prev;
        for (int i = 0; i < ans.size(); i+=2) {
            ans[i] = deck.back();
            deck.pop_back();
            start = i;
        }
        start++;
        prev = start;
        while (deck.size() > 0) {
            //cout << "start from "<< start << endl;
            for (int i = start; i < ans.size(); i++) {
                if (ans[i] == -1) {
                    count++;
                    if (count == 2) {
                        //cout <<"record "<< deck.back() <<" at " << i << endl;
                        ans[i] = deck.back();
                        deck.pop_back();
                        prev = i;
                        break;
                    } else if (deck.size() == 1) {
                        ans[i] = deck.back();
                        deck.pop_back();
                        break;
                    }
                }
                prev = i;
            }
            start = prev+1;
            if(count == 2) count = 0;
            if (start >= ans.size()) start = 0;
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      std::sort( deck.begin(), deck.end() );
      std::deque<int> dq;
      for( int i = 0; i < deck.size(); ++i ) dq.push_front( i );
      vector<int> res( deck.size() );
      int count = 0;
      while( !dq.empty() )
      {
        res[dq.back()] = deck[count++]; dq.pop_back();
        dq.push_front( dq.back() );
        dq.pop_back();
      }
      return res;
    }
};

static int x = []() {
	// toggle off cout & cin, instead, use printf & scanf
	std::ios::sync_with_stdio(false);
	// untie cin & cout
	cin.tie(NULL);
	return 0;
}();
