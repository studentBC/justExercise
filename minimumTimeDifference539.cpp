class Solution {
public:
	int getDiff(pair<int,int>t1, pair<int,int>t2) {
		int one = 0, two = 0;
		one = t1.first*60+t1.second;
		two = t2.first*60+t2.second;
		if (abs(t1.first - t2.first) <= 12) {
			return abs(one-two);
		} else {
			if (t1.first < t2.first) {
				return one+1440-two;
			} else {
				return two+1440-one;
			}
		}
	}
    int findMinDifference(vector<string>& timePoints) {
		vector<pair<int,int>>time;
		int hour = 0 , min = 0;
 		for (int i = 0; i < timePoints.size(); i++) {
			hour = 0 , min = 0;
			for (int j = 0; j < 2; j++) {
				hour+=((timePoints[i][j]-'0')*pow(10,1-j));
			}
			for (int j = 3; j < 5; j++) {
				min+=((timePoints[i][j]-'0')*pow(10,4-j));
			}
			cout << hour << " : " << min << endl;
			time.push_back(make_pair(hour,min));
		}
		int diff , ans = INT_MAX;
		for (int i = 0; i < time.size(); i++) {
			for (int j = i+1; j < time.size(); j++) {
				diff = getDiff(time[i],time[j]);
				if (ans > diff) ans = diff;
			}
		}
		return ans;
    }
};
//the fatest method 
class Solution {
public:
    int findMinDifference(const vector<string>& timePoints) {
        set<int> sorted;
        for(const string &s: timePoints) {
            const int v = (s[0]-'0')*600+(s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
            if (sorted.find(v) != sorted.cend())
                return 0;
            sorted.insert(v);
            sorted.insert(v-24*60);
            sorted.insert(v+24*60);
        }
        int ret = INT_MAX;
        auto it = sorted.cbegin();
        auto itNext = sorted.cbegin();
        ++itNext;
        for (; itNext != sorted.cend(); it = itNext++)
            ret = min(ret, *itNext - *it);
        return ret;
    }
};
