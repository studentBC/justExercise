class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        if(S.size() == 0) return "";
        string temp="";
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] != '-')temp+=toupper(S[i]);
        }
        cout <<temp << endl;
        int left = temp.size()%K, index;
        string ans = "";
        for (index = 0; index < left; index++) {
            ans+=temp[index];
        }
        cout << index << endl;
        if (temp.size() > K) {
            if (index > 0) {
                ans+="-";
            }
        } else {
            return temp;
        }
        cout << index << endl;
        int count = 0;
        for (int i = index; i < temp.size(); i++) {
            if (count > 0 && count%K == 0) {
                ans+="-";
                ans+=temp[i];
            } else {
                ans+=temp[i];
            }
            count++;
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result = "";
        int group_size = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                char c = (S[i] >= 'a' && S[i] <= 'z') ? (S[i] - 'a' + 'A') : S[i];
                result += c;
                group_size++;
                if (group_size == K) {
                    result += '-';
                    group_size = 0;
                }
            }
        }
        if (*(result.end() - 1) == '-') result = result.substr(0, result.length() - 1);
        reverse(result.begin(), result.end());
        return result;
        
    }
};
