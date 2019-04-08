class Solution {
public: 
    int videoStitching(vector<vector<int>>& clips, int T) {
        int start = 0, ans = 0, length, choose;
        vector<bool>chosen(clips.size(),false);
        while (start<T) {
            length = 0;choose = -1;
            for (int i = 0; i < clips.size(); i++) {
                if (!chosen[i] && clips[i][0]<= start && start < clips[i][1] && length < clips[i][1] - start+1) {
                    length = clips[i][1] - start+1;
                    choose = i;
                }
            }
            if (choose > -1) { 
                //cout << choose << " , ";
                start = clips[choose][1];
                chosen[choose] = true;
                ans++;
            } else {
                return -1;
            }
        }
        return ans;
    }
};

