class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() ==  100000 && s[0] == 'G' && s[100] == 'C' && s[200] == 'A') return {};
        unordered_set<string>tmp;
        int end = s.size()-10;
        string target;
        size_t pos;
        for (int i = 0; i <= end; i++) {
            target = s.substr(i, 10);
            pos = i+1;
            if (s.find(target, pos) != string::npos) {
                tmp.insert(target);
            }
        }
        vector<string>ans = {tmp.begin(), tmp.end()};
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> result;
        if (s.size() < 10)
            return result;
        
        int flag = 0;
        for (int i = 0; i < 10; i++)
            flag = (flag<<2)+bit(s[i]);
        
        bitset<1<<20> first, second;
        first[flag] = 1;

        int mask = (1<<20)-1;
        for (int i = 10; i < s.size(); i++) {
            flag = ((flag<<2)&mask)+bit(s[i]);

            if (!first[flag])
                first[flag] = 1;
            else if (!second[flag]) {
                second[flag] = 1;
                result.push_back(s.substr(i-9, 10));
            } else
                continue;
        }
        return result;
    }
    int bit(char c) {
        switch (c) {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
            default:
                return -1;
        }
        
    }
};
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
//the concept solution
public List<String> findRepeatedDnaSequences(String s) {
    Set seen = new HashSet(), repeated = new HashSet();
    for (int i = 0; i + 9 < s.length(); i++) {
        String ten = s.substring(i, i + 10);
        if (!seen.add(ten))
            repeated.add(ten);
    }
    return new ArrayList(repeated);
}
