//follow the concept as 2's complement 16 's complement is use loop for every byte and use F - target byte then +1 
//https://electronics.stackexchange.com/users/9833/jorge-zapata
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        bool negative = false;
        long nums = num;
        if (nums < 0) {
            negative = true;
            nums = -nums;
        }
        vector<int>bits;
        while (nums > 0) {
            bits.emplace_back(nums%16);
            nums = nums >> 4;
        }
        string ans = "";
        //2's complement flip 0-> , 1->0 and add 1
        if (negative) {
            for (int i = 0; i < bits.size(); i++) {
                bits[i] = 15-bits[i];
            }
            int index = 0; 
            while (index < bits.size() && bits[index]+1 > 15) {
                bits[index] = 0;
                index++;
            }
            if (index >= bits.size()) {
                bits.emplace_back(1);
            } else {
                bits[index]++;
            }
        }
        int left = 8-bits.size();
        while (!bits.empty()) {
            if (bits.back() < 10) {
                ans+=to_string(bits.back());
            } else {
                if (bits.back() == 10) {
                    ans+="a";
                } else if (bits.back() == 11) {
                    ans+="b";
                } else if (bits.back() == 12) {
                    ans+="c";
                } else if (bits.back() == 13) {
                    ans+="d";
                } else if (bits.back() == 14) {
                    ans+="e";
                } else if (bits.back() == 15) {
                    ans+="f";
                }
            }
            bits.pop_back();
        }
        if (negative) {
            string temp = "";
            for (int i = 0; i < left; i++) {
                temp+="f";
            }
            return temp+ans;
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    string toHex(int num) {
        string s;
        unsigned un = (unsigned int)(num);
        if (un == 0) {
            s = "0";
        } 
        while(un) {
            int res = un%16;
            char c;
            un = un/16;
            if (res < 10) {
                c = '0'+res;
            } else {
                c = 'a'+res-10;
            }
            s.insert(s.begin(), c);
        }
        return s;
    }
};
