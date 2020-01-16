class Solution {
public:
    string similarRGB(string color) {
        string ans="#", next;
        if (color.size() == 4) {
            for (int i = 1; i < color.size(); i++) {
                ans+=color[i];
                ans+=color[i];
            }
            return ans;
        }
        vector<pair<string,int>>candidate = {{"0",0},{"1",17},{"2",34},{"3",51},{"4",68},{"5",85},{"6",102},{"7",119},{"8",136},{"9",153},{"e",238},{"f",255},{"a",170},{"b",187},{"c",204},{"d",221}};
        int diff, temp, small;
        for (int i = 1; i < color.size(); i+=2) {
            if (isdigit(color[i])) temp = 16*(color[i]-'0');
            else temp = 16*(toupper(color[i])-'A'+10);
            if (isdigit(color[i+1])) temp += (color[i+1]-'0');
            else temp += (toupper(color[i+1])-'A'+10);
            //cout << temp <<" ,  ";
            small = INT_MAX;
            for (auto& it: candidate) {
                diff = abs(it.second-temp);
                if (diff < small) {
                    small = diff;
                    next = it.first;
                }
            }
            ans+=next;
        }
        return ans;
    }
};

