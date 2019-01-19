class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if(wall.size() == 1 && wall[0].size() == 1) {
            return 1;
        } 
        map<int,int>length;
        int sum = 0 , max = -1, ml , maxindex;
        map<int, int>::iterator itr;
        for (int i = 0; i < wall.size(); i++) {
            sum = 0;
            for (int j = 0; j < wall[i].size(); j++) {
                sum+=wall[i][j];
                wall[i][j] = sum;
                itr = length.find(sum);
                if (itr!=length.end()) {
                    itr->second = itr->second +1;
                } else {
                    length.insert(pair<int,int>(sum,1));
                }
            }
            ml = sum;
        }
        for (itr = length.begin(); itr!=length.end(); itr++) {
            if (itr->first!= ml && max < itr->second ) {
                max = itr->second;
                maxindex = itr->first;
            }
        }
        //cout <<"max: " << maxindex << "  ml: "<<ml << endl;
        int ans = wall.size();
        //cout << ans << endl;
        for (int i = 0; i < wall.size(); i++) {
            for (int j = 0; j < wall[i].size(); j++) {
                if (wall[i][j] == maxindex) {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};
//the fatest method
auto __ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if(wall.size() == 0 || wall[0].size() == 0)
            return 0;
        int sum  =0;
        for(int i = 0;i<wall[0].size();i++)
        {
            sum+=wall[0][i];
        }
        unordered_map<int,int> vote;
        for(int i =0;i<wall.size();i++)
        {
            int go = 0;
            for(int j = 0;j<wall[i].size();j++)
            {
                go+=wall[i][j];
                vote[go]++;
            }
        }
        int max = INT_MIN;
        vote.erase(sum);
        for(auto val:vote)
        {
            max = max>val.second?max:val.second;
        }
        if(max == INT_MIN)
            return wall.size();
        return wall.size()-max;
    }
};
