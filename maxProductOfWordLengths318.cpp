class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sum = 0, temp;
        vector<int>wm;
        for (int i = 0; i < words.size(); i++) {
            sum = 0;
            vector<bool>repeat(26,false);
            for (int j = 0; j < words[i].size(); j++) {
                temp=(words[i][j]-'a');
                if (!repeat[temp]) {
                    sum+=pow(2,temp);
                    repeat[temp] = true;
                }
            }  
            //cout << sum << " , ";
            wm.emplace_back(sum);
        }
        sum = 0;
        for (int i = 0; i < wm.size(); i++) {
            for (int j = i+1; j < wm.size(); j++) {
                temp = wm[i]&wm[j];
                if (temp == 0) {
                    //cout <<"found  " << i <<" , " << j << endl;
                    temp = words[i].size()*words[j].size();
                    if (temp > sum) sum = temp;
                }
            }   
        }
        return sum;
    }
};
//the fatest method
class Solution {
public:
    
    struct compare {
        bool operator()(const std::string& first, const std::string& second) {
            return first.size() < second.size();
        }
    };
    
    int maxProduct(vector<string>& words) {
        if(words.empty()) return 0;
        int maxProd = 0;
        compare c;
        // std::sort(words.begin(), words.end(), c);
        
        int wordsLen = words.size();
        std::vector<int> hash(wordsLen, 0);
        for(int i = 0; i < words.size(); ++i){
            for(int j = 0; j < words[i].length(); ++j){
                hash[i] = hash[i] | (1 << (words[i][j]-'a'));
            }
        }
        
        for(int i = words.size()-1; i > 0; --i){
            for(int j = i - 1; j >= 0; --j){
                if(!(hash[i] & hash[j])){
                    if(maxProd < words[i].length() * words[j].length()){
                        maxProd = words[i].length() * words[j].length();
                    }
                }
            }
        }
        return maxProd;
    }
};
