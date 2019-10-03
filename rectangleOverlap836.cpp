//basic concept 
//  https://www.geeksforgeeks.org/find-two-rectangles-overlap/
class Solution {
public:
    struct Point
    {
        int x, y;
    };
    // Returns true if two rectangles (l1, r1) and (l2, r2) overlap 
    bool doOverlap(Point l1, Point r1, Point l2, Point r2)
    {
        // If one rectangle is on left side of other 
        if (l1.x >= r2.x || l2.x >= r1.x) 
            return false; 
    
        // If one rectangle is above other 
        if (l1.y <= r2.y || l2.y <= r1.y)
            return false;
    
        return true;
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        Point p1 = {rec1[0], rec1[3]}, p2 = {rec1[2], rec1[1]}, p3 = {rec2[0], rec2[3]}, p4 = {rec2[2], rec2[1]};
        return doOverlap (p1, p2, p3, p4);
    }
};
//the fatest solution
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // We know there is overlap if one of the corners of one rectangle is contained by the other rectangle
        bool xOverlap = false;
        bool yOverlap = false;
        if (!sameSign(rec2[2]-rec1[0], rec2[0]-rec1[0]) || !sameSign(rec2[2]-rec1[2], rec2[0]-rec1[2]))
            xOverlap = true;
        if (!sameSign(rec2[3]-rec1[1], rec2[1]-rec1[1]) || !sameSign(rec2[3]-rec1[3], rec2[1]-rec1[3]))
            yOverlap = true;
        if (!sameSign(rec1[2]-rec2[0], rec1[0]-rec2[0]) || !sameSign(rec1[2]-rec2[2], rec1[0]-rec2[2]))
            xOverlap = true;
        if (!sameSign(rec1[3]-rec2[1], rec1[1]-rec2[1]) || !sameSign(rec1[3]-rec2[3], rec1[1]-rec2[3]))
            yOverlap = true;
        if (xOverlap && yOverlap){
            return true;
        }
        else
            return false;
    }
    bool sameSign(int a, int b){
        //returns true if two numbers are the same sign
        if ((double)a * b >= 0){
            return true;
        }
        else
            return false;
    }
};
