/*
The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.

For example, "#15c" is shorthand for the color "#1155cc".
The similarity between the two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)2 - (CD - WX)2 - (EF - YZ)2.

Given a string color that follows the format "#ABCDEF", return a string represents the color that is most similar to the given color and has a shorthand (i.e., it can be represented as some "#XYZ").

Any answer which has the same highest similarity as the best answer will be accepted.

 

Example 1:

Input: color = "#09f166"
Output: "#11ee66"
Explanation: 
The similarity is -(0x09 - 0x11)2 -(0xf1 - 0xee)2 - (0x66 - 0x66)2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
Example 2:

Input: color = "#4e3fe1"
Output: "#5544dd"
 

Constraints:

color.length == 7
color[0] == '#'
color[i] is either digit or character in the range ['a', 'f'] for i > 0.
*/

class Solution {
public:
    unordered_map<char, int>mp{
        {'a', 10},
        {'b', 11},
        {'c', 12},
        {'d', 13},
        {'e', 14},
        {'f', 15},
    };
    string get(char a, char b) {
        int s = 0, big = INT_MIN, tmp, index;
        if (isdigit(a)) s+=(a-'0')*16;
        else s+=mp[a]*16;
        if (isdigit(b)) s+=(b-'0');
        else s+=mp[b];
        //cout <<a<<b<<" : "<< s<< endl;
        for (int i = 0; i < 16; i++) {
            tmp = i*16+i;
            tmp = -pow(s-tmp, 2);
            if (big < tmp) {
                big = tmp;
                index = i;
            }
        }
            if (index == 0) return "00";
            else if (index == 1) return "11";
            else if (index == 2) return "22";
            else if (index == 3) return "33";
            else if (index == 4) return "44";
            else if (index == 5) return "55";
            else if (index == 6)  return "66";
            else if (index == 7) return "77";
            else if (index == 8) return "88";
            else if (index == 9) return "99";
            else if (index == 10) return "aa";
            else if (index == 11) return "bb";
            else if (index == 12) return "cc";
            else if (index == 13) return "dd";
            else if (index == 14) return "ee";
            else  return "ff";
    }
    string similarRGB(string color) {
        string ans = "#";
        for (int i = 1; i < color.size(); i+=2) {
            ans+=get(color[i], color[i+1]);
        }
        return ans;
    }
};


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

