class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int own[3] = {0};//5 , 10, 20
        //int change;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                own[0]++;
            } else if (bills[i] == 10) {
                own[1]++;
                if (own[0] == 0) {
                    return false;
                } else {
                    own[0]--;
                }
            } else {
                own[2]++;
                //change = 15;
                if (own[0] == 0) {
                    return false;
                } else {
                    if (own[1] > 0 && own[0] > 0) {
                        own[1]--;
                        own[0]--;
                    } else if (own[1] == 0 && own[0] > 2) {
                        own[0]-=3;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
//the fatest method
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change = 0;
        int numFives = 0;
        int numTens = 0;
        for(int pay:bills) {
            if(pay == 5) {
                change += 5;
                ++numFives;
            } else if(pay == 10) {
                if(change < 5 || numFives == 0) return false;
                change += 5;
                --numFives;
                ++numTens;
            } else if(pay == 20) {
                if(change < 15 || numFives == 0) return false;
                change -= 15;   //20 bill not usable for change
                if(numTens > 0) {
                    --numTens;
                    --numFives;
                } else {
                    numFives -= 3;
                }
            }
        }
        return true;
    }
};
