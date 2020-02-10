class Solution {
public:
    double angleClock(int hour, int minutes) {
 		double ha = hour*30;
		double ma = minutes*6, diff, counter;
		diff = ma/12+ha-ma;
		if (diff < 0) diff = -diff;
		counter = 360-diff;
		return min(counter, diff);
    }
};
