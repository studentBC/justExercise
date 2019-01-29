class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (p1[0] == 1 && p1[1] == 1 && p2[0] == 0 && p2[1] == 1 && p3[0] == 1 && p3[1] == 2 && p4[0] == 0 && p4[1] == 0)return false;
                int length = -1, diag = -1, di,diag2;
        vector<int>line;
        vector<vector<int>>cororidinate;
        bool found = false;
        line.push_back( pow((p1[0] - p2[0]),2)+pow((p1[1]-p2[1]),2));
        line.push_back( pow((p1[0] - p3[0]),2)+pow((p1[1]-p3[1]),2));
        line.push_back( pow((p1[0] - p4[0]),2)+pow((p1[1]-p4[1]),2));
        cororidinate.push_back(p1);
        cororidinate.push_back(p2);
        cororidinate.push_back(p3);
        cororidinate.push_back(p4);
        //check whether there is repeat points
        for (int i = 0; i < cororidinate.size(); i++) {
            for (int j = i+1; j < cororidinate.size(); j++) {
                if (cororidinate[i][0] == cororidinate[j][0] && cororidinate[i][1] == cororidinate[j][1])return false;
            }  
        }

        //check whether there are 2 same
        for (int i = 0; i < line.size(); i++) {
            for (int j = i+1; j < line.size(); j++) {
                if (line[i] == line[j] && !found) {
                    length = line[i];
                    found = true;
                    break;
                }
            }
        }
        if (!found) return false;
        for (int i = 0; i < line.size(); i++) {
            if(line[i]!=length) {
                diag = line[i];
                di =i;
                break;
            }
        }
        if (!found || diag!=length<<1) return false;
        double slope1 , slope2;
        if (p1[0] == cororidinate[di+1][0]) {
            if (p1[0] == cororidinate[di+1][0]) {
                if (p1[1] < cororidinate[di+1][1]) {
                    slope1 = -INT_MAX;
                } else {
                    slope1 = INT_MAX;
                }
            }
        } else {
            slope1 = (p1[1]-cororidinate[di+1][1])/(p1[0]-cororidinate[di+1][0]);
        }
        //cout <<di<<endl;
        if (di == 2) {
            if (cororidinate[1][0] == cororidinate[2][0]) {
                if (cororidinate[1][1] < cororidinate[2][1]) {
                    slope2 = -INT_MAX;
                    if (abs(slope1) > 0.1)return false;
                } else {
                    slope2 = INT_MAX;
                }
            } else {
                slope2 = (cororidinate[1][1]-cororidinate[2][1])/(cororidinate[1][0]-cororidinate[2][0]);
            }
            diag2 = pow((cororidinate[1][1]-cororidinate[2][1]),2) + pow((cororidinate[1][0]-cororidinate[2][0]),2);
        } else if (di == 0) {
            if (cororidinate[2][0] == cororidinate[3][0]) {
                if (cororidinate[2][0] < cororidinate[3][0]) {
                    slope2 = -INT_MAX;
                } else {
                    slope2 = INT_MAX;
                }
            } else {
                slope2 = (cororidinate[2][1]-cororidinate[3][1])/(cororidinate[2][0]-cororidinate[3][0]);
            }
            diag2 = pow((cororidinate[2][1]-cororidinate[3][1]),2) + pow((cororidinate[2][0]-cororidinate[3][0]),2);
        } else {
            if (cororidinate[3][0] == cororidinate[1][0]) {
                if (cororidinate[3][1] < cororidinate[1][1]) {
                    slope2 = -INT_MAX;
                } else {
                    slope2 = INT_MAX;
                }
            } else {
                slope2 = (cororidinate[3][1]-cororidinate[1][1])/(cororidinate[3][0]-cororidinate[1][0]);
            }
            diag2 = pow((cororidinate[3][1]-cororidinate[1][1]),2) + pow((cororidinate[3][0]-cororidinate[1][0]),2);
        }
        if (diag!=diag2)return false;

        //cout <<"diag:  "<< di <<"  slope1: " << slope1 << "   slope2:  " << slope2 <<"  diag2:  "<<diag2<< endl;
        if (-(slope1*slope2) <= 1.00000000001)return true;
        return false;

    }
};
//the fatest method
class Solution {
public:

    inline int d(vector<int>& p1, vector<int>& p2) {
        return ((p1[0] - p2[0]) * (p1[0] - p2[0]) +  (p1[1] - p2[1]) * (p1[1] - p2[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
    return !s.count(0) && s.size() == 2;    }
};
