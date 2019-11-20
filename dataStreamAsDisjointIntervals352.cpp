class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        used[val] = true;
        upper = max (val, upper);
        lower = min (val, lower);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        vector<int>temp;
        //cout << lower <<" , " << upper << endl;
        for (int i = lower; i < upper+2; i++) {
            if (!used[i]) {
                if (temp.size()) {
                    temp.emplace_back(i-1);
                    ans.emplace_back(temp);
                    temp.clear();
                }
            } else {
                if (temp.size() == 0) temp.emplace_back(i);
            }
        }
        return ans;
    }
private:
    vector<bool>used{vector<bool>(INT_MAX, false)};
    int upper = -1, lower = INT_MAX;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
//the fatest solution
class SummaryRanges {
    vector<vector<int>> vs;

   public:
    /** Initialize your data structure here. */
    SummaryRanges() {}

    void addNum(int val) {
        vector<int> tmp{val, val};
        
        auto iter = lower_bound(
            vs.begin(), vs.end(), tmp, [](const vector<int> &item, const vector<int> &v) {
                return item[0] < v[0] || (item[0] == v[0] && item[1] <= v[1]);
            });

        if (iter == vs.end()) {
            if (vs.empty() || vs.back()[1] + 1 < val) {
                vs.push_back(tmp);
            } else if (vs.back()[1] + 1 == val) {
                vs.back()[1] = val;
            }
            return;
        }

        if (iter == vs.begin()) {

            assert(vs[0][0] >= val);
            if (vs[0][0] == val) {
                return;
            }

            assert(vs[0][0] > val);
            if (vs[0][0] - 1 == val) {
                vs[0][0] -= 1;
            } else {
                vs.insert(vs.begin(), tmp);
            }

            return;
        }

        auto idx = iter - vs.begin();

        assert(vs[idx][0] >= val);

        if (vs[idx][0] == val) {
            return;
        }

        assert(vs[idx][0] > val);

        if (vs[idx - 1][1] >= val) {
            return;
        }

        if (vs[idx - 1][1] + 1 == val && val + 1 == vs[idx][0]) {
            vs[idx - 1][1] = vs[idx][1];
            vs.erase(iter);
            return;
        }

        if (vs[idx - 1][1] + 1 == val) {
            vs[idx - 1][1] = val;
            return;
        }

        if (vs[idx][0] == val + 1) {
            vs[idx][0] = val;
            return;
        }
        
        vs.insert(iter, tmp);
    }

    vector<vector<int>> &getIntervals() { return vs; }
};
