/*
Reference
POJ: http://poj.org/problem?id=1981
StackOverflow: https://stackoverflow.com/questions/3229459/algorithm-to-cover-maximal-number-of-points-with-one-circle-of-given-radius/3229582#3229582


Plan
Well, I doubt if this problem is appropriate for Leetcode or interview.

If you meet this prolem during interview,
you can ask the interviewer:
"Could you give me some APIs?"


Explanation
The basic idea is that,
imagine that we are shrink the final circle,
until there are at least 2 points on the circle.

We can enumerate all possible circles based on the given points.


Solution 1: O(N^4) brute force
Enumerate all combinations of 3 points,
find the circumcenter of these 3 points.

Use this circumcenter as the center of circle,
and count how many points inside.

If the final result >=3, we won't miss it during this search.
But if we still have res = 1
we still need to check each two pair distance,
to find out if res can be 2.

Time O(N^4)
Space O(1)


Solution 2:
Enumerate all combinations of 2 points,
find the circle going through them with radius = r.

Use this circumcenter as the center of circle,
and count how many points inside.

Also explained by Alexandre C:
Basic observations :

I assume the radius is one,
since it doesn't change anything.
given any two points,
there exists at most two unit circles on which they lie.
given a solution circle to your problem,
you can move it until it contains two points of your set
while keeping the same number of points of your set inside it.
The algorithm is then:

For each pair of points,
if their distance is < 2,
compute the two unit circles C1 and C2 that pass through them.
Compute the number of points of your set inside C1 and C2
Take the max.
Time O(N^3)
Space O(1)
*/
 //https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/discuss/639686/picsFor-those-of-you-who-don't-understand-why-any-two-points-should-be-on-the-border   
	int numPoints(vector<vector<int>>& A, int r) {
        int res = 1, n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = A[i][0], y1 = A[i][1];
                int x2 = A[j][0], y2 = A[j][1];
                double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                if (d > r * 2) continue;
                double x0 = (x1 + x2) / 2.0 + (y2 - y1) * sqrt(r * r - d * d / 4) / d;
                double y0 = (y1 + y2) / 2.0 - (x2 - x1) * sqrt(r * r - d * d / 4) / d;
                int cnt = 0;
                for (vector<int>& point : A) {
                    double x = point[0], y = point[1];
                    if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= r * r + 0.00001) {
                        cnt++;
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }

// the 16 ms solution
class Solution {
public:
    /*
        https://stackoverflow.com/questions/3229459/algorithm-to-cover-maximal-number-of-points-with-one-circle-of-given-radius/3229582#3229582

        https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/discuss/636345/Simple-Python-O(n3)-Solution-with-picture-%2B-O(n2logn)-explained-in-detail
        
        https://math.stackexchange.com/questions/1781438/finding-the-center-of-a-circle-given-two-points-and-a-radius-algebraically
        
        Using two points and radius to find the circle center.
        Then count the # of points within the circle.
        Iterate all point pairs
    */
    int numPoints(vector<vector<int>>& points, int r) {
        int result = 1, n = points.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                
                double d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
                if (d > 2*r) continue;
                
                // use two circle equation to deduce x0 and y0
                // (x1-x0)^2 + (y1-y0)^2 = r^2
                // (x2-x0)^2 + (y2-y0)^2 = r^2
                // d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))
                double x0 = (x1+x2)/2.0 + (y2-y1)/d * sqrt(r*r - d*d/4);  // <=== attention: floating number
                double y0 = (y1+y2)/2.0 - (x2-x1)/d * sqrt(r*r - d*d/4);

                int cnt = 0;
                for(int k = 0; k < n; k++) {
                    double x = points[k][0], y = points[k][1];
                    if ((x-x0)*(x-x0)+(y-y0)*(y-y0) <= r*r + 0.00001) {  // <=== attention: floating number
                        cnt++;
                    }
                }
                
                result = max(result, cnt);
            }
        }
        return result;
    }
};
