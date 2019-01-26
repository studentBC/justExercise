class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size()<2)return false;
        map<int,int>group;
        std::map<int,int>::iterator it;
        for (int i = 0; i < deck.size(); i++) {
            it = group.find(deck[i]);
            if (it==group.end()) {
                group.insert(pair(deck[i],1));
            } else {
                it->second++;
            }
        }
        int min = INT_MAX;
        for (it = group.begin();it!=group.end();it++) {
            if (min > it->second) {
                min = it->second;
            }
        }
        bool ans = true;
        for (int i = 2; i <= min; i++) {
            if (min%i == 0) {
                ans = true;
                for (it = group.begin();it!=group.end();it++) {
                    if (it->second%i!=0) {
                        ans = false;
                        break;
                    }
                }
                if (ans)return ans;
            }
        }
        
        return false;
    }
};
//the fatest method
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<uint16_t> bag(10001, 0);
        for(auto n: deck) {
            bag[n]++;
        }
        
        uint16_t gcd, i = 0;
        while(bag[i] == 0) i++;
        gcd = bag[i];

        for(int i = 1; i < 10001; i++) {
            gcd = bag[i] == 0 ? gcd : __gcd(bag[i], gcd);
        }
        
        return gcd > 1;
    }
};

