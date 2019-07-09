class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int>del;
        int pos = -1;
        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[0] > intervals[i][1]) {
                continue;
            } else if (intervals[i][0] > newInterval[1]) {
                if(pos < 0)pos = i;
            }else {
                del.emplace_back(i);
                //cout <<i <<" , ";
                if (intervals[i][0] < newInterval[0]) {
                    newInterval[0] = intervals[i][0];
                }
                if (intervals[i][1] > newInterval[1]) {
                    newInterval[1] = intervals[i][1];
                }
                //cout << endl << newInterval[0] <<" , "<<newInterval[1] <<endl;
            }
        }
        //cout << endl << newInterval[0] <<" , "<<newInterval[1] <<endl;
        vector<vector<int>>ans (intervals.begin(), intervals.end());
        //cout << pos ;
        //cout << del[0] << endl;
        if (del.size() == 0) {
            if(pos > -1) {
                ans.insert(ans.begin()+pos, newInterval);
            } else {
                ans.insert(ans.end(), newInterval);
            }
        } else {
            ans.insert(ans.begin()+del[0], newInterval);
            ans.erase(ans.begin()+del[0]+1, ans.begin()+del.back()+2);
        }
        return ans;
    }
};
//8ms solution
class Solution {
public:
    Solution(){
        ios::sync_with_stdio(false);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int lens = intervals.size();
        if(lens == 0) return {newInterval};
            
        vector<vector<int>> res;
        int i = 0;
        while(i < lens && intervals[i][1] < newInterval[0]) i++;  
        int j = lens - 1;
        while(j >=0 && newInterval[1] < intervals[j][0]) j--;
        
        for(int k=0; k<i;k++) res.push_back(intervals[k]);
        vector<int> merge;
        if(i<=j){
            merge.push_back(min(newInterval[0], intervals[i][0]));
            merge.push_back(max(newInterval[1], intervals[j][1]));
            res.push_back(merge);
        }
        else
           res.push_back(newInterval);
        
        while(++j<lens){
            res.push_back(intervals[j]);
        }
        
        return res;
    }
};
