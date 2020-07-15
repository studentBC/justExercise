class Solution {
public:
    string reformatDate(string date) {
        map<string,int>month = {{"Jan",1}, {"Feb",2}, {"Mar",3}, {"Apr",4}, {"May",5}, {"Jun",6}, {"Jul",7}, {"Aug",8}, {"Sep",9}, {"Oct",10}, {"Nov",11}, {"Dec",12}};
        istringstream is(date);
        string tmp, t, ans;
        vector<string>temp;
        int count = 0, number = 0;
        while (is >> tmp) {
            if (count == 0) {
                number = 0;
                for (char c: tmp) {
                    if (!isdigit(c)) break;
                    number = number*10+c-'0';
                }
                if (number < 10) {
                    t="0";
                    t+=to_string(number);
                } else t = to_string(number);
                temp.push_back(t);
            } else if (count == 1) {
                if (month[tmp] < 10) {
                    t="0";
                    t+=to_string(month[tmp]);
                } else t = to_string(month[tmp]);
                temp.push_back(t);
            } else {
                t = "";
                int end = 4-tmp.size();
                for (int i = 0; i < end; i++) {
                    t+="0";
                }
                temp.push_back(t+tmp);
            }
            count++;
        }
        for (int i = temp.size()-1; i > -1; i--) {
            ans+=temp[i];
            ans+="-";
        }
        ans.pop_back();
        return ans;
    }
};

