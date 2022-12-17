class Solution {
public:
    int s1[5] = {1,2,1,-2,1};
    int s2[5] =  {-2,-1,2,-1,-2};
    int minKnightMoves(int x, int y) {
        int ans = -1, xx, yy, left = min(0, x)-2, right = max(0, x)+2, up = max(0, y)+2, down = min(0, y)-2;
        queue<tuple<int, int, int>>pos;
        set<pair<int, int> >beenTo;
        pos.push({0,0,0});
        while (!pos.empty()) {
            auto next = pos.front();
            if (get<0>(next) == x && y == get<1>(next)) return get<2>(next);
            //cout << get<0>(next) << ", " << get<1>(next) << " ";
            pos.pop();
            if (beenTo.count({get<0>(next), get<1>(next)})) continue;
            beenTo.insert({get<0>(next), get<1>(next)});
            for (int i = 0; i < 4; i++) {
                xx = get<0>(next)+s1[i];
                yy = get<1>(next)+s1[i+1];
                if (xx > right || xx < left || yy > up || yy < down || beenTo.count({xx, yy})) continue;
                pos.push({xx, yy, get<2>(next)+1});
            }
            for (int i = 0; i < 4; i++) {
                xx = get<0>(next)+s2[i];
                yy = get<1>(next)+s2[i+1];
                if (xx > right || xx < left || yy > up || yy < down || beenTo.count({xx, yy})) continue;
                pos.push({xx, yy, get<2>(next)+1});
            }
        }
        return -1;
    }
};
