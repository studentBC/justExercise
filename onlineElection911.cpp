class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int id = -1;
        for (int p: persons) id = max(p,id);
        id++;
        total = id;
        //cout << id << endl;
        st = times; people = persons;
        vote = new int *[times.size()];
        for (int i = 0; i < times.size(); i++) {
            //cout <<i<<" , ";
            vote[i] = new int[id];
            if (i == 0) {
                for (int j = 0; j < total; j++) {
                    if (j == persons[i]) {
                        vote[i][j] = 1;
                    } else {
                        vote[i][j] = 0;
                    }
                }
            } else {
                for (int j = 0; j < total; j++) {
                    if (j == persons[i]) {
                        vote[i][j]= vote[i-1][j]+1;
                    } else {
                        vote[i][j] = vote[i-1][j];
                    }
                }
            }
        }
        //cout <<"here "<< endl;
    }
    int q(int t) { 
        //cout << t << endl;
        int left = 0, right = st.size()-1, mid, most = 0, elect;
        while (left <= right) {
            mid = left+(right-left)/2;
            if (st[mid] == t) {
                //cout <<"found " << mid << endl;
                for (int i = 0; i < total; i++) {
                    most = max(most, vote[mid][i])  ;
                }
                for (int i = mid; i > -1; i--) {
                    if (vote[mid][people[i]] == most) return people[i];
                }   
            } else if (st[mid] > t) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        left--;
        //cout <<"found " << left << endl;
        for (int i = 0; i < total; i++) {
            most = max(most, vote[left][i]) ;
        }
        for (int i = left; i > -1; i--) {
            if (vote[left][people[i]] == most) return people[i];
        }
        return -1;
    }
private:
    int** vote;
    vector<int>st, people;
    int total;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
//244 ms solution

static const int __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class TopVotedCandidate {
private:
    vector<int> maxVals, *times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& tim) {
        int val = 0;
        vector<int> t(persons.size() + 1, 0);
        for (int p : persons) {
            t[p]++;
            if (t[val] <= t[p]) val = p;
            maxVals.push_back(val);
        }
        times = &tim;
    }
    
    int q(int t) {
        int r = upper_bound((*times).begin(), (*times).end(), t) - (*times).begin();
        return maxVals[--r];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */


