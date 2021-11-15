//the bug I missed in the contest
//https://leetcode.com/problems/walking-robot-simulation-ii/discuss/1575896/Hidden-Test-Case-REVEALED!
class Robot {
public:
    int i = 0, j = 0, x , y , direct = 0, total;
    vector<string> dd = {"East", "North", "West", "South"};
    Robot(int width, int height) {
        x = width-1;
        y = height-1;
        direct = 0;
        total = (x+y)*2;
        //if (total == 0) total = 1;
    }
    
    void move(int num) {
        int prev = num;
        num%=total;   
        
        while (num) {
            if (direct == 0) {
                if (i+num > x) {
                    num-=(x-i);
                    i = x;
                    direct++;
                } else {
                    i+=num;
                    num = 0;
                }
            } else if (direct == 1) {
                if (j+num > y) {
                    num-=(y-j);
                    j = y;
                    direct++;
                } else {
                    j+=num;
                    num = 0;
                }
            } else if (direct == 2) {
                if (i-num < 0) {
                    num-=(i);
                    i = 0;
                    direct++;
                } else {
                    i-=num;
                    num = 0;
                }
            } else if (direct == 3) {
                if (j-num < 0) {
                    num-=(j);
                    j = 0;
                    direct = 0;
                } else {
                    j-=num;
                    num = 0;
                }
            }
        }
        //cout << i <<" , " << j << endl;
        if (i == 0 && j == 0 && prev%total == 0 && prev) direct = 3;
    }
    
    vector<int> getPos() {
        return {i, j};
    }
    
    string getDir() {
        //if (i == 0 && j == 0) return "South";
        return dd[direct]; 
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
