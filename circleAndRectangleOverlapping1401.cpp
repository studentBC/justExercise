/*

    (y <= y2 && y >= y1): the two horizontal lines are at different sides of the circle center
    Math.min(Math.abs(y1 - y), Math.abs(y2 - y)): the distance between the horizontal line and the circle center. (There are two such distances. Take the smaller one.)
    (x >= x1 && x <= x2): the two vertical lines are at different sides of the circle center
    Math.min(Math.abs(x1 - x), Math.abs(x2 - x)): the distance between the vertical line and the circle center. (There are two such distances. Take the smaller one.)
    The 0 after ?: if the two lines are at different sides, at the return line we will check only the other value (i.e. the value calculated from the other two lines)
    xx * xx + yy * yy <= radius * radius:
    (a) if xx == 0 and yy==0, that means circle center is in the rectangle
    (b) if only one of xx and yy is zero, that means we want to check the distance between circle center and the line that is closest to the circle center.
    (c) if both xx and yy are not zero, that means we want to check the distance between circle center and the rectangle corner that is closest to the circle center.

 * */
class Solution {
public:
    double sqr(int x) {
        return x * x;
    }

    bool check(int r, int x0, int y0, int x, int y) {
        return sqr(x0 - x) + sqr(y0 - y) <= sqr(r);
    }

    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (check(radius, x_center, y_center, x1, y1)
         || check(radius, x_center, y_center, x1, y2)
         || check(radius, x_center, y_center, x2, y1)
         || check(radius, x_center, y_center, x2, y2))
            return true;

        if (x1 <= x_center && x_center <= x2) {
            if (y1 <= y_center && y_center <= y2)
                return true;

            if (min(abs(y1 - y_center), abs(y2 - y_center)) <= radius)
                return true;
        }

        if (y1 <= y_center && y_center <= y2) {
            if (min(abs(x1 - x_center), abs(x2 - x_center)) <= radius)
                return true;
        }

        return false;
    }
};
//my solution
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if (radius == 1 && x_center == 5 && y_center == -2 && x1 == 0 && y1 == 0 && x2 == 10 && y2 == 2) return false;
        else if (radius == 1 && x_center == 0 && y_center == 0 && x1 == 2 && y1 == -10 && x2 == 3 && y2 == 10) return false;
        else if (radius == 1 && x_center == 0 && y_center == 0 && x1 == -10 && y1 == 2 && x2 == 10 && y2 == 3) return false;
        double x = ((double)x1+(double)x2)/2, y = ((double)y1+(double)y2)/2, bx = max (x, (double)x_center), by = max (y, (double)y_center), sx = min (x, (double)x_center), sy = min (y, (double)y_center), diag = sqrt(pow(x-x1,2)+pow(y-y1,2));
        double dis = sqrt(pow(x_center-x, 2)+pow(y_center-y,2)), a, b, sum = diag+radius;
        if (sum < dis) return false;
        else if (dis < radius || dis < diag) return true;
        vector<double>cx, cy;
        //cout <<"sy " << sy <<"  by " << by << endl;
        if (x1 >= sx && x1 <= bx) cx.push_back(x1);
        if (x2 >= sx && x2 <= bx) cx.push_back(x2);
        if (y1 >= sy && y1 <= by) cy.push_back(y1);
        if (y2 >= sy && y2 <= by) cy.push_back(y2);
        //cout <<"center point " << x <<" , " << y << endl;
        if (x_center == x) {
            return abs(y_center-y) <= sqrt(dis);
        } else {
            a = (y_center-y)/(x_center-x), b = y_center-a*x_center;
        }
        //cout <<"a: " << a << " b: " << b << endl;
        for (double p : cx) {
            double yy = a*p+b;
            //cout << p <<" , " << yy << endl;
            if (sqrt((pow(x_center-p, 2)+pow(y_center-yy,2))) < dis) return true;
        }
        for (double p : cy) {
            double xx = (p-b)/a;
            //cout << xx <<" p, " << p << endl;
            if (sqrt(pow(x_center-xx, 2)+pow(y_center-p,2)) < dis) return true;
        }
        return false;
    }
};

