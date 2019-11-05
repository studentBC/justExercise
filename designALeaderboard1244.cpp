class Leaderboard {
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (player[playerId]) {
			player[playerId] += score;
		} else {
			player[playerId] = score;
			/*vector<int>temp;
			while (!rank.empty() && rank.back() > score ) {
				temp.emplace_back(rank.back());
				rank.pop_back();
				rank.emplace_back(score);
			}*/
		}
    }
    
    int top(int K) {
		priority_queue<int> rank;        
		for (auto& it: player) rank.push(it.second);
		int sum = 0;
		for (int i = 0; i < K; i++) {
			sum+=rank.top();
			rank.pop();
		}
		return sum;
    }
    
    void reset(int playerId) {
       player[playerId] = 0; 
    }
private:
	unordered_map<int,int>player;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
//the fatest solution
//https://www.techiedelight.com/use-std_pair-as-key-std_set-cpp/
//Internally, the elements in a set are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).
class Leaderboard {
public:
    map<int, int> M;
    set<pair<int,int>> S;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        S.erase({M[playerId], playerId});
        M[playerId] += score;
        S.insert({M[playerId], playerId});
    }
    
    int top(int K) {
        int res = 0;
        int c = 0;
        for(auto it = S.rbegin(); it != S.rend() && c<K; ++it,++c)
            res += it->first;
        return res;
    }
    
    void reset(int playerId) {
        S.erase({M[playerId], playerId});
        M[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
