class TweetCounts {
public:
    TweetCounts() {
        tweet.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        tweet[tweetName].push_back(time);
        sort(tweet[tweetName].begin(), tweet[tweetName].end());
        return;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        //cout << freq <<" , " << tweetName <<" , " << startTime <<" , " << endTime << endl;
        int interval, end, count = 0, et;
        vector<int>ans;
        if (freq == "minute") interval = 60;
        else if (freq == "hour") interval = 3600;
        else {
            interval = 86400;
        }
        if (tweet.find(tweetName) == tweet.end()) return ans;
        while (startTime <= endTime) {
            end = startTime+interval-1;
            count = 0;
            for (int i : tweet[tweetName]) {
				et = min(end,endTime);
                if (i >= startTime && i <= et) count++;
                else if (i > end) break;
            }
            ans.push_back(count);
            startTime+=interval;
        }
        return ans;
    }
    unordered_map<string,vector<int>>tweet;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
//the fatest solution


#pragma GCC optimize("Ofast")

#ifdef LeetCode
#include "LeetCodeHeader.h"
#endif

static int my_speed_up = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

using ll = long long;
using ull = unsigned long long;

using v_i = vector<int>;
using vv_i = vector<vector<int>>;
using vvv_i = vector<vector<vector<int>>>;

#define for_b(i, b) for (int i = 0; i < (b); ++i)
#define for_ab(i, a, b) for (int i = a; i < (b); ++i)

#define co << ", " <<
#define what_is(x) cout << #x << " = " << x << endl;

#define show_1d(___x) for (auto& ___num : ___x) cout << ___num << ", "; cout << endl;
#define show_2d(___x) for (auto& ___row : ___x) { for (auto ___num : ___row) cout << ___num << ", "; cout << endl; } cout << endl;
#define show_3d(___x) for (auto& ___row : ___x) { for (auto& ___row2 : ___row) { for (auto ___num : ___row2) cout << ___num << ", "; cout << endl; }cout << endl; }cout << endl;


class TweetCounts
{
private:
    unordered_map<string, v_i>tb;
public:
    TweetCounts()
    {

    }

    void recordTweet(string name, int time)
    {
        if (auto it = tb.find(name); it != tb.end())
        {
            if (it->second.back() <= time)
                it->second.push_back(time);
            else
            {
                int idx = my_binary_search_r(it->second, time);
                it->second.insert(it->second.begin() + idx, time);
            }
        }
        else tb[name].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string name, int st, int et)
    {
        int freq_int = 0;
        if (freq == "minute")
            freq_int = 60;
        else if (freq == "hour")
            freq_int = 3600;
        else if (freq == "day")
            freq_int = 86400;

        auto it = tb.find(name);
        v_i res;
        for (auto cur_et = st + freq_int; st <= et; cur_et += freq_int)
        {
            if (it == tb.end())
                res.push_back(0);
            else
                res.push_back(get_counts(it->second, st, min(cur_et - 1, et)));
            st = cur_et;
        }
        return res;
    }

    int get_counts(const vector<int>& sub_tb, int st, int et)
    {
        int si = my_binary_search_l(sub_tb, st);
        int ei = my_binary_search_r(sub_tb, et);
        if (ei < sub_tb.size() && sub_tb[ei] == et) ++ei;

        return ei - si;
    }

    int my_binary_search_l(const vector<int>& vec, int tar)
    {
        int a = 0;
        int b = static_cast<int>(vec.size()) - 1;

        while (a < b)
        {
            int mid = (a + b) / 2;
            if (tar > vec[mid])
                a = mid+1;
            else
                b = mid;
        }
        if (tar > vec[a])
            return a + 1;

        return a;
    }

    int my_binary_search_r(const vector<int>& vec, int tar)
    {
        int a = 0;
        int b = static_cast<int>(vec.size()) - 1;

        while (a < b)
        {
            int mid = (a + b) / 2;
            if (tar >= vec[mid])
                a = mid+1;
            else
                b = mid;
        }
        if (tar > vec[a])
            return a + 1;

        return a;
    }

};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */


