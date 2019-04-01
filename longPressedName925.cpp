class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char,int>>runtyp;
        vector<pair<char,int>>runam;
        vector<char>temp;
        char prev;
        int count = 0;
        name+="$"; typed+="$";
        for (int i = 0; i < typed.size(); i++) {
            if (temp.empty() || typed[i] == temp.back()) {
                temp.push_back(typed[i]);
            } else {
                prev = temp.back();
                count = 0;
                while (!temp.empty()) {
                    temp.pop_back();
                    count++;
                }
                runtyp.push_back (pair<char,int>(prev, count));
                temp.push_back (typed[i]);
            }
        }

        //for (int i = 0; i < runtyp.size(); i++) cout <<runtyp[i].first << " , " << runtyp[i].second << endl;
        temp.clear();
        for (int i = 0; i < name.size(); i++) {
            if (temp.empty() || name[i] == temp.back()) {
                temp.push_back(name[i]);
            } else {
                prev = temp.back();
                count = 0;
                while (!temp.empty()) {
                    temp.pop_back();
                    count++;
                }
                runam.push_back (pair<char,int>(prev, count));
                temp.push_back (name[i]);
            }
        }
        if (runam.size()!=runtyp.size())return false;
        for (int i = 0; i < runam.size(); i++) {
            //cout <<runam[i].first << " , " << runam[i].second << endl;
            if (runam[i].first!=runtyp[i].first || runam[i].second > runtyp[i].second) return false;
        }

        return true;
    }
};

