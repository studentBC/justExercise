class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        vector<int>len;
        int left = maxWidth, length = words.size(), width, space, i = 0, sum, end;
        for (string& s: words) len.push_back(s.size());
        while (i < length) {
            width = maxWidth;
            vector<int> tmp;
            for (int j = i; j < length && width >= len[j]; j++) {
                tmp.push_back(j);
                width-=len[j];
                width--;
            }
            i = tmp.back()+1;
            sum = 0;
            for (int a: tmp) sum+=len[a];
            
            string temp, sp;
            if (i == length) {
                end = tmp.size()-1;
                space = maxWidth-sum-(tmp.size()-1);
                for (int j = 0; j < end; j++) {
                    temp+=words[tmp[j]];
                    temp.push_back(' ');
                }
                temp+=words[tmp[end]];
                for (int j = 0; j < space; j++) temp.push_back(' ');
            } else {
                if (tmp.size() == 1) {
                    space = maxWidth-sum;
                    temp+=words[tmp[0]];
                    for (int a = 0; a < space; a++) temp.push_back(' ');
                    ans.push_back(temp);
                    continue;
                }
                //cout << tmp.size() << endl;
                space = (maxWidth-sum)/(tmp.size()-1);
                for (int a = 0; a < space; a++) sp.push_back(' ');
                int redundant = (maxWidth-sum)%(tmp.size()-1);
                if (redundant) {
                    sp.push_back(' ');
                    //cout << sp.size() << endl;
                    end = tmp.size();
                    int j = 0;
                    for (j = 0; j < end && j < redundant; j++) {
                        temp+=words[tmp[j]];
                        temp+=sp;
                    }
                    sp.pop_back();
                    for ( ; j < end-1; j++) {
                        temp+=words[tmp[j]];
                        temp+=sp;
                    }
                    temp+=words[tmp.back()];
                } else {
                    for (int j = 0; j < tmp.size()-1; j++) {
                        temp+=words[tmp[j]];
                        temp+=sp;
                    }
                    temp+=words[tmp.back()];
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans, line;
        int index = 0, left = maxWidth, end = words.size()-1;
        string temp;
        while (index < words.size()) {
            if (left > words[index].size()) {
                line.emplace_back(words[index]);
                left-=words[index].size();
                left--;
                index++;
            } else if (left == words[index].size()) {
                temp = "";
                for (string s: line) {
                    temp+=s;
                    temp+=" ";
                }
                temp+=words[index];
                left = maxWidth;
                line.clear();
                index++;
                ans.emplace_back(temp);
            } else {
                vector<int>space(line.size()-1, 1);
                temp = "";
                left++;
                if (index > end || space.size() == 0) {
                    for (int i = 0; i < space.size(); i++) {
                        temp+=line[i];
                        temp+=" ";
                    }
                    temp+=line.back();
                    for (int i = 0; i < left; i++) temp+=" ";
                    //cout << temp << endl;
                } else {
                    //cout << left << endl;
                    while (left) {
                        for (int i = 0; i < space.size() && left; i++, left--) {
                            space[i]++;
                        }
                    }
                    for (int i = 0; i < space.size(); i++) {
                        temp+=line[i];
                        for (int j = 0; j < space[i]; j++) temp+=" ";
                    }
                    temp+=line.back();
                }
                //cout <<  temp << endl;
                ans.emplace_back(temp);
                line.clear();
                left = maxWidth;
            }
        }
        if (line.size()) {
            left++;
            vector<int>space(line.size()-1, 1);
            temp = "";
            for (int i = 0; i < space.size(); i++) {
                temp+=line[i];
                temp+=" ";
            }
            temp+=line.back();
            for (int i = 0; i < left; i++) temp+=" ";
            ans.emplace_back(temp);
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(words.empty()) return {};
        vector<string> answer;
        int left = 0;
        int right = 1;
        int cur_length = words[0].size();
        while(right<words.size()){
            if(cur_length+words[right].size()+1<=maxWidth) {
                cur_length += words[right].size()+1;
                right++;
            }
            else {
                int space = maxWidth - (cur_length - (right-left-1));
                if(right==left+1){
                    //only one word
                    answer.push_back(words[left]+string(space,' '));
                    left++;
                    right++;
                    cur_length = words[left].size();
                } else {
                    int n = right-left-1;
                    int tmp = space / n;
                    string s = words[left++];
                    for(int i=0;i<space%n;++i) s += string(tmp+1,' ') + words[left++];
                    for(int i=space%n;i<n;++i) s += string(tmp, ' ') + words[left++];
                    answer.push_back(s);
                    right = left + 1;
                    cur_length = words[left].size();
                }
            }
        }
        // the last line
        string s = words[left++];
        while(left<right){
            s += " " + words[left++];
        }
        s += string(maxWidth-s.size(), ' ');
        answer.push_back(s);
        return answer;
    }
};
