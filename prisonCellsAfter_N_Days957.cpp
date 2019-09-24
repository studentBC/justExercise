class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int>next(cells.size(),0);
        vector<vector<int>>number;
        int end = cells.size()-1, sum = 0;
        unordered_set<int> order;
        bool cycle = false;
        /*
        for (int i = 0; i < 8; i++) {
            if (cells[i]) {
                sum += pow(2,i);
            }
        }*/
        //order.insert(sum);
        //cout << sum << endl;
        if (N == 0) return cells;
        //number.emplace_back(cells); 
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < end; j++) {
                if (cells[j-1] == cells[j+1]) {
                    next[j] = 1;
                } else {
                    next[j] = 0;
                }
            }
            sum = 0;
            for (int j = 0; j < 8; j++) {
                if (next[j]) {
                    sum += pow(2,j);
                }
            }
            //cout << sum << endl;
            if (order.find(sum) == order.end()) {
                order.insert(sum);
                number.emplace_back(next);
            } else {
                //cout <<"break at " << i << endl;
                cycle = true;
                break;
            }
            cells = next;
        }
        if (!cycle) return next;
        int index = (N-1)%(number.size());
        return number[index];
    }
};
//the fatest solution
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& c, int N) {
      vector<int> f_c, next_c(c.size(), 0);
      for (int cycle = 0; N-- > 0; c = next_c, ++cycle) {
        for (auto i = 1; i < c.size() - 1; ++i) next_c[i] = c[i - 1] == c[i + 1];
        if (cycle == 0) f_c = next_c;
        else if (next_c == f_c) N %= cycle;
      }
      return c;
    }
};
