class Solution {
public:
    int left = INT_MAX, right = -1, up = -1, down = INT_MAX, col, row;
    int direct[5] = {-1, 0, 1, 0, -1};
    void go (int x, int y, vector<vector<char>>& image) {
        if (x < 0 || x>= row || y < 0 || y >= col || image[x][y] == '0') return;
        left = min(x, left);
        right = max(x, right);
        down = min(y, down);
        up = max(y, up);
        image[x][y] = '0';
        for (int i = 0; i < 4; i++) go (x+direct[i], y+direct[i+1], image);

    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        row = image.size();
        col = image[0].size();
        go (x, y, image);
        return (up-down+1)*(right-left+1);
    }
};
