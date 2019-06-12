class ExamRoom {
public:
    ExamRoom(int N) {
        pos.clear(); 
        occupy = (bool*)calloc(N,sizeof(bool));
        len = N;
    }
    int seat() {
        if (pos.size() == 0) {
            pos.emplace_back(0);
            occupy[0] = true;
            return 0;
        } else if (pos.size() == 1) {
            if (pos.back() > len-pos.back()-1) {
                pos.insert(pos.begin(),0);
                occupy[0] = true;
                return 0;
            } else {
                pos.emplace_back(len-1);
                occupy[len-1] = true;
                return len-1;
            }
        } else {
            int longest = -1, end = pos.size()-1, index, chosen;
            for (int i = 0; i < pos[0]; ++i) {
                if (!occupy[i] && (pos[0]-i) > longest) {
                    longest = pos[0]-i;
                    chosen = i;break;
                }
            }
            for (int i = 1; i < pos.size(); i++) {
                index = (pos[i-1] + pos[i])/2;
                if (!occupy[index] && (index-pos[i-1]) > longest) {
                    longest = index-pos[i-1];
                    chosen = index;
                }
            }
            for (int i = len-1; i > pos.back(); --i) {
                if (!occupy[i] && (i-pos.back()) > longest) {
                    longest = i-pos.back();
                    chosen = i;break;
                }
            }
            if (longest == 1) {
                if (chosen > 0 && !occupy[chosen-1]) {
                    chosen--;
                }
            }
            for (int i = 0; i < pos.size(); ++i) {
                if (i == 0 && chosen < pos[0]) {
                    pos.insert(pos.begin(), chosen);
                    break;
                } else if (i == pos.size()-1 && chosen > pos[i]) {
                    pos.emplace_back(chosen);
                    break;
                } else if (i > 0 && chosen > pos[i-1] && chosen < pos[i]) {
                    pos.insert(pos.begin()+i,chosen);
                    break;
                }
            }
            occupy[chosen] = true;
            return chosen;
        }
    }

    void leave(int p) {
        for (int i = 0; i < pos.size(); ++i) {
            if (pos[i] == p) {
                pos.erase(pos.begin()+i);
                occupy[p] = false;
                return;
            }
        }
   }
private:
    vector<int>pos;
    bool* occupy;
    int len;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

//the fatest method
class ExamRoom {
public:
    struct cmp {
        bool operator()(const pair<int, int> &p1,
                       const pair<int, int> &p2) const {
            int d1 = (p1.second - p1.first) / 2;
            int d2 = (p2.second - p2.first) / 2;
            if (d1 != d2) {
                return (d1 > d2);
            }
            return (p1.first < p2.first);
        }
    };
    set<pair<int, int>, cmp> seg;
    set<int> st;
    int n;
    ExamRoom(int N) {
        n = N;
    }
    int seat() {
        int ans;
        if (st.empty()) {
            ans = 0;
        } else if (st.size() == 1) {
            int x = *st.begin();
            if (x >= n-1 - x) {
                ans = 0;
                seg.insert({ans, *st.begin()});
            } else {
                ans = n-1;
                seg.insert({*st.begin(), ans});
            }
        } else {
            int a = seg.begin()->first;
            int b = seg.begin()->second;
            int d1 = (b-a) / 2;
            int d2 = *st.begin();
            int d3 = n-1 - *st.rbegin();
            if (d2 >= d1 && d2 >= d3) {
                ans = 0;
                seg.insert({0, *st.begin()});
            } else if (d1 >= d2 && d1 >= d3) {
                ans = (a+b)/2;
                seg.erase({a, b});
                seg.insert({a, ans});
                seg.insert({ans, b});
            } else {
                ans = n-1;
                seg.insert({*st.rbegin(), ans});
            }
        }
        st.insert(ans);
        return (ans);
    }
    
    void leave(int p) {
        set<int>::iterator itr = st.find(p);
        int a, b;
        if (itr == st.begin()) {
            a = 0;
        } else {
            a = *prev(itr);
        }
        if (next(itr) == st.end()) {
            b = n-1;
        } else {
            b = *next(itr);
        }
        seg.erase({a, p});
        seg.erase({p, b});
        seg.insert({a, b});
        st.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
