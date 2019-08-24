class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (Y > X) {
            int count = 0;
            if (Y%2 == 0) {
                while (Y > X) {
                    if (Y%2 == 0) {
                        Y >>=1;
                    } else {
                        Y++;
                    }
                    count++;
                }
                cout<<Y <<"  "<<count;
                count+=(X-Y);
                return count;
            } else {
                Y++;
                count++;
                while (Y > X) {
                    if (Y%2 == 0) {
                        Y >>=1;
                    } else {
                        Y++;
                    }
                    count++;
                }
                count+=(X-Y);
                return count;
            }
        } else if (Y == X) {
            return 0;
        } else {
            return X-Y;
        }
    }
};
