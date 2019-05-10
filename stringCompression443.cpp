class Solution {
public:
    int compress(vector<char>& chars) {
        chars.emplace_back('    ');
        char prev = chars[0];
        int count = 1;
        vector<char> alpha;
        vector<int> number;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i]!=prev) {
                number.emplace_back(count);
                alpha.emplace_back(prev);
                count = 1;
            } else {
                count++;
            }
            prev = chars[i];
        }
        chars.clear();
        for (int i = 0; i < number.size(); i++) {
            //cout << alpha[i] <<" : " << number[i] << endl;
            if (number[i] < 2) {
                chars.emplace_back(alpha[i]);
            } else {
                chars.emplace_back(alpha[i]);
                string temp = to_string(number[i]);
                for (int j = 0; j < temp.size(); j++) {
                    chars.emplace_back(temp[j]);
                }
            }
        }
        return chars.size();
    }
};
//the fatest method
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), cur = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && chars[j] == chars[i]) ++j;
            chars[cur++] = chars[i];
            if (j - i == 1) continue;
            for (char c : to_string(j - i)) chars[cur++] = c;
        }
        return cur;
    }
};
