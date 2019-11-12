class Solution {
public:
    vector<int> constructRectangle(int area) {
        int length = sqrt(area), l, w;
        if (length*length == area) {
            return {length, length};
        } else {
            for (int i = length; i <= area; i++) {
                w = area/i;
                //cout << i <<" , " << w << endl;
                if (area%i == 0 && i >= w) {
                    l = i;
                    return {l,w};
                }
            }
        }
        return {area, 1};
    }
};
//the fatest solution
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int mid = int(sqrt(double(area)));
        cout << mid << endl;
        for (int W = mid; W >= 1; W--) {
            if (area % W == 0)
                return vector<int>{area/W, W};
        }
        return vector<int> {0, 0};
    }
};
