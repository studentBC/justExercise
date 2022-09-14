class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        vector<string>candidate;
        for (int i = 0; i < searchWord.size(); i++) {
            if (i == 0) {
                for (int j = 0; j < products.size(); j++) {
                    if (products[j][0] == searchWord[0]) {
                        candidate.push_back(products[j]);
                    }
                }
            } else {
                vector<string>tmp;
                for (int j = 0; j < candidate.size(); j++) {
                    if (i < candidate[j].size()) {
                    //     tmp.push_back(candidate[j]);
                    // } else {
                        if (candidate[j][i] == searchWord[i]) {
                            tmp.push_back(candidate[j]);
                        }
                    }
                }
                candidate = tmp;
            }
            vector<string>tmp;
            for (int j = 0; j < 3 && j < candidate.size(); j++) {
                tmp.push_back(candidate[j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
