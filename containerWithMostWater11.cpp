class Solution {
public:
    int maxArea(vector<int>& height) {
        int high = -1, ans = 0, end = height.size()-1, prev;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > high) {
                high = height[i];
                prev = -1;
                for (int j = end, len = j-i; j > i; j--, len--) {
                    if (height[j] > prev) {
                        ans = max(ans, min(height[j], height[i])*len);
                        prev = height[j];
                    }
                    //width = min(high, height[j]);
                }
            }
        }
        return ans;
    }
};
//28 ms solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_size=0;
        vector<int>::iterator it1=height.begin();
        vector<int>::iterator it2=it1+(height.size()-1);
        while(it1<it2){
            int size;
            if(*it1<*it2){
                size=(it2-it1)*(*it1);
                max_size=max_size>size?max_size:size;
                it1++;
            }else{
                size=(it2-it1)*(*it2);
                max_size=max_size>size?max_size:size;
                it2--;
            }
        }
        return max_size;
    }
};
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
