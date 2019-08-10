/*
Given a picture consisting of black and white pixels, find the number of black lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

Example:

Input: 
[['W', 'W', 'B'],
 ['W', 'B', 'W'],
 ['B', 'W', 'W']]

Output: 3
Explanation: All the three 'B's are black lonely pixels.
Note:

The range of width and height of the input 2D array is [1,500].
*/
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        bool match = false;int ans = 0, count;
        vector<int> row(picture.size(),0);
        vector<int> col(picture[0].size(), 0);
        for (int i = 0; i < picture.size(); i++) {
            count = 0;
            for (int j = 0; j < picture[i].size(); j++) {
                if (picture[i][j] == 'B') {
                    count++;
                }
            }
            row[i] = count;
        }
        for (int i = 0; i < picture[0].size(); i++) {
            count = 0;
            for (int j = 0; j < picture.size(); j++) {
                if (picture[j][i] == 'B') {
                    count++;
                }
            }
            col[i] = count;
        }
        for (int i = 0; i < picture.size(); i++) {
            for (int j = 0; j < picture[i].size(); j++) {
                if (picture[i][j] == 'B') {
                    if (row[i] == 1 && col [j] == 1) ans++;
                    //if (match) ans++;
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.empty() || picture[0].empty())
            return 0;
        int firstrow = 0;
        size_t rsize = picture.size(), csize = picture[0].size();
        for(size_t row = 0; row < rsize; ++row) {
            for(size_t col = 0; col < csize; ++col) {
                if(picture[row][col] == 'B') {
                    if(picture[0][col] < 'Y' && picture[0][col] != 'V') ++picture[0][col];
                    if(row == 0) ++firstrow;
                    else if(picture[row][0] < 'Y' && picture[row][0] != 'V') ++picture[row][0];
                }
            }
        }
        int result = 0;
        for(size_t row = 0; row < rsize; ++row) {
            for(size_t col = 0; col < csize; ++col) {
                if(picture[row][col] < 'W' && (picture[0][col] == 'C' || picture[0][col] == 'X')) {
                    if(row == 0) result += (firstrow == 1)? 1 : 0; 
                    else if(picture[row][0] == 'C' || picture[row][0] == 'X')
                        ++result;
                }
            }
        }
        return result;
    }
};
