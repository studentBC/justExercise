class Solution {
public:
    int check (vector<int>& piles, int mid) {
        int count = 0;
        for (int i = 0; i < piles.size(); i++) {
            count+=(piles[i]/mid);
            if (piles[i]%mid > 0) count++;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        long sum = 0;
        int ave = 0, up = -1, mid, temp, hit=INT_MAX, lower = INT_MAX;
        for (int i = 0; i < piles.size(); i++) {
            sum+=piles[i];
            if (up < piles[i]) up = piles[i];
        }
        ave = sum/H;
        if (ave == 0) return 1;
        //cout << "lower bound: " << ave <<"  uppder bound " << up << endl;
        while (up>=ave) {
            mid = ave+(up-ave)/2;
            temp = check(piles,mid);
            //cout <<"speed is " << mid << " H = "<< temp << endl;
            if (temp == H && hit > mid) {
                up = mid-1;
                hit = mid;
            } else if (temp < H) {
                if (lower > mid) lower = mid;
                up = mid-1;
            } else {
                ave = mid+1;
            }
        }
        //cout <<"up: " << up << " hit " << hit << " lower " << lower  << endl;
        if (lower==INT_MIN && hit==INT_MAX) {
            return up;
        } else if (hit == INT_MAX) {
            return lower;
        } else {
            return hit;
        }
    }
};

//the fatest method
class Solution {
    bool mes_(vector<int>& piles, int& K, int& H) {
        int h = 0;
        for(auto& p : piles) {
            h += p/K + (p%K!=0);
        }
        return h<=H;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // first compute a lower bound of K
        double sum = accumulate(piles.begin(), piles.end(), 0.0);
        int max = *max_element(piles.begin(), piles.end());
        
        int lowK = ceil(sum/H);
        int upK  = max;
        
        // should consider binary search
        /*while(lowK<upK) {
            int midK = (lowK+upK)/2;
            if (mes_(piles, midK, H)) {
                upK = midK;
            } else {
                lowK = midK+1;
            }
        }*/
        // should consider binary search
        for(int i=lowK; i<=upK; i++) {
            int h = 0;
            for(auto& p : piles) {
                h += p/i + (p%i!=0);
            }
            if (h<=H) return i;
        }
        
        return -1;
        
        return lowK;
    }
};
