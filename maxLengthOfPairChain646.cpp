class Solution {
public:
    static bool ps (pair<int,int>a , pair<int,int>b) {
        int da = a.second - a.first , db = b.second - b.first;
        if (a.second == b.second) {
            return da < db;
        } else {
            return a.second < b.second;
        }
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>>temp;
        for (int i = 0; i < pairs.size(); i++) {
            temp.push_back(make_pair(pairs[i][0],pairs[i][1]));
        }
        sort (temp.begin(), temp.end(), ps);
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i].first << " , " << temp[i].second << endl;
        }

        int end = temp[0].second , index = 1 , count = 1;
        bool found = false;
        while (true) {
            found = false;
            for (int i = 1; i < temp.size(); i++) {
                if (temp[i].first > end) {
                    end = temp[i].second;
                    count++;
                    found = true;
                    break;
                }
            }
            if (!found)return count;
        }
        return  count;
    }
};
