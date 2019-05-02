class Solution {
public:
    vector<int> partitionLabels(string S) {
        int start = 0, end = S.size(), count = 0;
        unordered_set<char>found;
        vector<int>ans;
        while (start < S.size()) {
            for (int i = S.size()-1; i >= start; i--) {
                if (S[i] == S[start]) {
                    end = i;
                    break;
                }
            }
            found.insert(S[start]);
            count = 0; 
            for (int i = start; i <= end; i++) {
                count++;
                if (found.find(S[i]) == found.end()) {
                    found.insert(S[i]);
                    for (int j = S.size()-1; j > i; j--) {
                        if (S[i] == S[j]) {
                            if (end < j) {
                                end = j;
                            } 
                            break;
                        }
                    }
                }
            }
            ans.emplace_back(count);
            //cout << start << " , " << end << endl;
            start = end+1;
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(S.size() == 1) return {1};
        
        // Acquire max positions of each letter   
        vector<int> max_pos(26, 0);
        for(int i = 0; i < S.size(); i++)
            max_pos[S.at(i) - 'a'] = i;
        
        // Determine counts of each segment
        int cur_min     = 0;
        int cur_count   = 1;
        vector<int> results;
        
        for(int j = 0; j < S.size(); j++)
        {
            cur_min = max(cur_min,  max_pos[S.at(j) - 'a']);

            if(j == cur_min)
            {
                results.push_back(cur_count);
                cur_count = 1;
            }
            else
                cur_count += 1;
        }

        return results;
    }
};
