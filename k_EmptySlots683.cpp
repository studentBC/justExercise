/*
 * You have n bulbs in a row numbered from 1 to n. Initially, all the bulbs are turned off. We turn on exactly one bulb every day until all bulbs are on after n days.

You are given an array bulbs of length n where bulbs[i] = x means that on the (i+1)th day, we will turn on the bulb at position x where i is 0-indexed and x is 1-indexed.

Given an integer k, return the minimum day number such that there exists two turned on bulbs that have exactly k bulbs between them that are all turned off. If there isn't such day, return -1.
 */

/*
 * The idea is to use an array days[] to record each position's flower's blooming day. That means days[i] is the blooming day of the flower in position i+1. We just need to find a subarray days[left, left+1,..., left+k-1, right] which satisfies: for any i = left+1,..., left+k-1, we can have days[left] < days[i] && days[right] < days[i]. Then, the result is max(days[left], days[right]).
 */
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int len = bulbs.size(), left = 0, right = k+1, ans = INT_MAX;
        vector<int>day(len);
        for (int i = 0; i < len; i++) day[bulbs[i]-1] = i+1;
        for (int i = 0; right < len; i++) {
            if (day[i] < day[left] || day[i] <= day[right]) {
                if (i == right) ans = min(ans, max(day[left], day[right]));
                left = i, right = k+1+i;
            }
        }
        return (ans == INT_MAX)? -1 : ans;
    }
};


class Solution {
public: 
    int kEmptySlots(vector<int>& bulbs, int K) {
        vector<bool>light(bulbs.size(), false);
        int start;
        for (int i = 0; i < bulbs.size(); i++) {
            start = bulbs[i]-1;
            light[start] = true;
            //cout << "light " << start << endl;
            //cout <<"find right from " << bulbs[i] << endl;
            for (int j = bulbs[i]; j < bulbs.size(); j++) {
                if (light[j]) {
                    cout << j <<" is lit " << endl;
                    if (j-start-1 == K) return i+1;
                    break;
                }
            }
            //cout <<"find left from " << bulbs[i]-2 << endl;
            for (int j = bulbs[i]-2; j > -1; j--) {
                if (light[j]) {
                    if (start-j-1 == K) return i+1;
                    break;
                }
            }
        }
        return -1;
    }
};
//the fatest solution
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        if(!n || n <= k) return -1;
        
        vector<char> status(n, 0);
        for(int i = 0; i < n; ++i) {
            if(isvalid(bulbs[i]-1, n, k, status))
                return i+1;
        }
        return -1;
    }
    
    int isvalid(int pos, int n, int k, vector<char>& st) {
        st[pos] = true;
        //check left side
        if(pos - k - 1 >= 0 && st[pos - k - 1]) {
            bool valid = true;
            for(int i = pos - k; i < pos; ++i) {
                if(st[i]) {
                    valid = false;
                    break;
                }
            }
            if(valid) return true;
        }
        
        if(pos + k + 1 < n && st[pos + k + 1]) {
            for(int i = pos + 1; i < pos + k + 1; ++i) {
                if(st[i]) return false;
            }
            return true;
        }
        return false;
    }
};
