class Solution {
public:
    int find(vector<int>& uni, int target) {
        return uni[target] < 0 ? target : uni[target] = find(uni, uni[target]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int>uni(s.size(), -1);
        int p1, p2;
        for (auto& it: pairs) {
            p1 = find(uni, it[0]);
            p2 = find(uni, it[1]);
            if (p1 != p2) {
                if (uni[p1] > uni[p2]) swap(p1, p2);
                uni[p1]+=uni[p2];
                uni[p2] = p1;
            }
            //uni[p1] = p2;
        }
        //for (int i : uni) cout << i << " , ";
        //cout << endl;
        unordered_map<int, vector<int>>index;
        for (int i = 0; i < uni.size(); i++) {
            index[find(uni, i)].push_back(i);
        }
        for (auto& it : index) {
            vector<char>character;
            for (auto& i : it.second) {
                character.push_back(s[i]);
            }
            sort(character.begin(), character.end());
            for (int i = 0; i < it.second.size(); i++) {
                s[it.second[i]] = character[i];
            }
        }
        return s;
    }
};
