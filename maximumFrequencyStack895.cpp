class FreqStack {
public:
    FreqStack() {
     
    }

    void push(int x) {
        data.emplace_back(x);
        if (freq.find(x) == freq.end()) {
            freq[x] = 1;
        } else {
            freq[x]++;
        }
    }

    int pop() {
        int choose, big = -1, index;
        for (auto& it: freq) {
            if (it.second > big) {
                big = it.second;
            }
        }
        for (int i = data.size()-1; i > -1; i--) {
            if (freq[data[i]] == big) {
                choose = data[i];
                index = i;
                break;
            }
        }
        data.erase(data.begin()+index);
        if(freq[choose] == 1) {
            freq.erase(choose);
        } else {
            freq[choose]--;
        }
        return choose;
    }
private:
    vector<int>data;
    unordered_map<int,int>freq;
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

//164ms solution
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
static auto _ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
using namespace std;

class FreqStack
{
private:
    unordered_map<int, int> imap;
    vector<stack<int>> sav;
    int maxFreq = 0;

public:
    FreqStack()
    {
    }

    void push(int x)
    {
        int sz = imap[x]++;
        if (sav.size() < sz + 1)
            sav.push_back({});
        if (sz > maxFreq)
            maxFreq = sz;
        sav[sz].push(x);
    }

    int pop()
    {
        int ret = sav[maxFreq].top();
        sav[maxFreq].pop();
        if (sav[maxFreq].empty())
            maxFreq--;
        imap[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
