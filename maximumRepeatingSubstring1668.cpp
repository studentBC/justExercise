class Solution {
public:
    int maxRepeating(string sequence, string word) {
        std::size_t pos = 0, big = sequence.size()/word.size();
        int ans = 0;
        
        for (int i = big; i > 0; i--) {
            string tmp;
            for (int j = 0; j < i; j++) {
                tmp+=word;
            }
            pos = sequence.find(tmp);
            //cout << prev << " : " << pos << endl;
            
            if (pos!=string::npos) {
                return i;
            }
        }
        return 0;
    }
};
