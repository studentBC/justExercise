/*
 A perfectly straight street is represented by a number line. The street has street lamp(s) on it and is represented by a 2D integer array lights. Each lights[i] = [positioni, rangei] indicates that there is a street lamp at position positioni that lights up the area from [positioni - rangei, positioni + rangei] (inclusive).

The brightness of a position p is defined as the number of street lamp that light up the position p.

Given lights, return the brightest position on the street. If there are multiple brightest positions, return the smallest one.

 

Example 1:


Input: lights = [[-3,2],[1,2],[3,3]]
Output: -1
Explanation:
The first street lamp lights up the area from [(-3) - 2, (-3) + 2] = [-5, -1].
The second street lamp lights up the area from [1 - 2, 1 + 2] = [-1, 3].
The third street lamp lights up the area from [3 - 3, 3 + 3] = [0, 6].

Position -1 has a brightness of 2, illuminated by the first and second street light.
Positions 0, 1, 2, and 3 have a brightness of 2, illuminated by the second and third street light.
Out of all these positions, -1 is the smallest, so return it.
Example 2:

Input: lights = [[1,0],[0,1]]
Output: 1
Explanation:
The first street lamp lights up the area from [1 - 0, 1 + 0] = [1, 1].
The second street lamp lights up the area from [0 - 1, 0 + 1] = [-1, 1].

Position 1 has a brightness of 2, illuminated by the first and second street light.
Return 1 because it is the brightest position on the street.
Example 3:

Input: lights = [[1,2]]
Output: -1
Explanation:
The first street lamp lights up the area from [1 - 2, 1 + 2] = [-1, 3].

Positions -1, 0, 1, 2, and 3 have a brightness of 1, illuminated by the first street light.
Out of all these positions, -1 is the smallest, so return it.
 

Constraints:

1 <= lights.length <= 105
lights[i].length == 2
-108 <= positioni <= 108
0 <= rangei <= 108
 */
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int>count;
        for (int i = lights.size()-1; i > -1; i--) {
            count[lights[i][0]-lights[i][1]]++;
            count[lights[i][0]+lights[i][1]+1]--;
        }
        int len = lights.size(), c = 0, pos = INT_MAX, sum = 0;
        for (auto& it : count) {
            sum+=it.second;
            //cout << it.first <<" : " << sum << endl;
            if (sum > c) {
                c = sum;
                pos = it.first;
            } else if (sum == c) {
                pos = min(pos, it.first);
            }
        }


        return pos;
    }
};

//228 ms solution
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        std::vector<int> startBoundaries;
        std::vector<int> endBoundaries;
        
        for (const auto& light : lights) {
            int startBoundary = light[0] - light[1];
            int endBoundary = light[0] + light[1];
            
            startBoundaries.push_back(startBoundary);
            endBoundaries.push_back(endBoundary);
        }
        
        std::sort(startBoundaries.begin(), startBoundaries.end());
        std::sort(endBoundaries.begin(), endBoundaries.end());

        int maxBrightestPos = INT_MIN;
        int currentBrightness = INT_MIN;
        int maxBrightness = INT_MIN;

        int startBoundaryIdx = 0;
        int endBoundaryIdx = 0;

        while (startBoundaryIdx < startBoundaries.size() || endBoundaryIdx < endBoundaries.size()) {
            int startBoundaryVal = 0;
            int endBoundaryVal = endBoundaries[endBoundaryIdx];
            
            if (startBoundaryIdx == startBoundaries.size()) {
                endBoundaryIdx++;
                currentBrightness--;
            } else {
                startBoundaryVal = startBoundaries[startBoundaryIdx];
                if (startBoundaryVal <= endBoundaryVal) {
                    currentBrightness++;
                    startBoundaryIdx++;
                } else {
                    currentBrightness--;
                    endBoundaryIdx++;
                }
            }
            
            if (currentBrightness > maxBrightness) {
                maxBrightness = currentBrightness;
                maxBrightestPos = startBoundaryVal;
            }
        }
        
        return maxBrightestPos;
    }
};
