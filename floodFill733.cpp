class Solution {
public:
    void go (int i, int j, vector<vector<int>>& image, int old, int newColor, vector<vector<bool>>& beento) {
        if (i > -1 && i < image.size() && j > -1 && j < image[i].size() && image[i][j] == old && !beento[i][j]) {
            image[i][j] = newColor;
            beento[i][j] = true;
            go (i+1,j,image,old,newColor, beento);
            go (i,j+1,image,old,newColor, beento);
            go (i-1,j,image,old,newColor, beento);
            go (i,j-1,image,old,newColor, beento);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>>beento(image.size(), vector<bool>(image[0].size(), false));
        go (sr,sc,image, image[sr][sc], newColor,beento);
        return image;
    }
};
//the fatest method
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int memo = image[sr][sc];
        helper(sr, sc, memo, image, newColor);
        return image;
    }
private:
    void helper(int sr, int sc, int memo, vector<vector<int>>&image, int newColor){
        //cout<<sr<<endl;
        //cout<<sc<<endl;
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc] == newColor|| image[sr][sc] != memo) return ;
        image[sr][sc] = newColor;
        helper(sr+1, sc, memo, image, newColor);
        helper(sr-1, sc, memo, image, newColor);
        helper(sr, sc+1, memo, image, newColor);
        helper(sr, sc-1, memo, image, newColor);
    }
};
