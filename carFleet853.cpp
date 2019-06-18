class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<long, long>>car;
        for (int i = 0; i < position.size(); ++i) {
            car.emplace_back(pair<long,  long>(position[i],speed[i]));
        }
        sort(car.begin(), car.end());
        bool reach;
        int count = 0, choose;
        long front;
        while (!car.empty()) {
            for (int i = 0; i < car.size(); ++i) {
                car[i].first+=car[i].second;
            }
            reach = false;
            vector<pair<long, long>>pos;
            for (int i = 0; i < car.size(); ) {
                front = INT_MAX;
                for (int j = i+1; j < car.size(); ++j) {
                    if (car[j].first < car[i].first) {
                        if (front > car[j].first) {
                            front = car[j].first; choose = j;
                        }
                    } else if (car[j].first == car[i].first && car[j].second < car[i].second) {
                            front = car[j].first; choose = j;
                    }
                }
                if (front != INT_MAX) car[i].first = front;
                if (car[i].first >= (long)target) {
                    reach = true;break;
                } else {
                    if (front != INT_MAX) {
                        for (int j = i; j <= choose; ++j) {
                            car[j].first = front;
                            pos.emplace_back(car[j]);
                        } 
                        i = choose+1;
                    } else {
                        pos.emplace_back(car[i]);i++;
                    }
                }
            }
            if (reach) count++;
            car = pos;
        }
        return count;
    }
};
//faster method
/*Sort cars by the start positions pos
Loop on each car from the end to the beginning
Calculate its time needed to arrive the target
cur records the current biggest time (the slowest)

If another car needs less or equal time than cur,
it can catch up this car fleet.

If another car needs more time,
it will be the new slowest car,
and becomes the new lead of a car fleet.*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>car;
        for (int i = 0; i < position.size(); ++i) {
            car.emplace_back(pair<int, double>(position[i],((double)(target-position[i])/(double)speed[i])));
        }
        sort(car.begin(), car.end());
        double time = 0;int ans = 0;
        for (int i = car.size()-1; i > -1; i--) {
            if (car[i].second > time) {
                time = car[i].second;ans++;
            }
        }
        return ans;
    }
};
