class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int longest = -1, len, front, back, index;
        for (int i = 0; i < seats.size(); ++i) {
            if (!seats[i]) {
                front = back = 0;
                for (int j = i-1; j > -1; j--) {
                    if (seats[j]) {
                        break;
                    } else {
                        front++;
                    }
                }
                for (int j = i+1; j < seats.size(); j++) {
                    if (seats[j]) {
                        break;
                    } else {
                        back++;
                    }
                }
                if (front == 0 && back == 0) {
                    len = 0;
                } else if (front == 0 && back > 0 && i == 0) {
                    len = back;
                } else if (front > 0 && back == 0 && i == seats.size()-1) {
                    len = front;
                } else {
                    len = min(front, back);
                }
                if (longest < len) {
                    longest = len;
                }
            }
        }
        return longest+1;
    }
};
//the fatest  method
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //
        vector<int> dist(seats.size(),0);
        //
        int d=20000;
        for(int i=0;i<seats.size();i++) {
            if(seats[i]) d=0;
            else d++;
            dist[i] = d;
        }
        
        d=20000;
        int res=0;
        for(int i=seats.size()-1;i>=0;i--) {
            if(seats[i]) d=0;
            else d++;
            res = max(res,min(d,dist[i]));
        }
        return res;
        
    }
};
