class Solution {
public: 
    int kEmptySlots(vector<int>& bulbs, int K) {
        vector<bool>light(bulbs.size(), false);
        int start;
        for (int i = 0; i < bulbs.size(); i++) {
            start = bulbs[i]-1;
            light[start] = true;
            //cout << "light " << start << endl;
            //cout <<"find right from " << bulbs[i] << endl;
            for (int j = bulbs[i]; j < bulbs.size(); j++) {
                if (light[j]) {
                    cout << j <<" is lit " << endl;
                    if (j-start-1 == K) return i+1;
                    break;
                }
            }
            //cout <<"find left from " << bulbs[i]-2 << endl;
            for (int j = bulbs[i]-2; j > -1; j--) {
                if (light[j]) {
                    if (start-j-1 == K) return i+1;
                    break;
                }
            }
        }
        return -1;
    }
};
//the fatest solution
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        if(!n || n <= k) return -1;
        
        vector<char> status(n, 0);
        for(int i = 0; i < n; ++i) {
            if(isvalid(bulbs[i]-1, n, k, status))
                return i+1;
        }
        return -1;
    }
    
    int isvalid(int pos, int n, int k, vector<char>& st) {
        st[pos] = true;
        //check left side
        if(pos - k - 1 >= 0 && st[pos - k - 1]) {
            bool valid = true;
            for(int i = pos - k; i < pos; ++i) {
                if(st[i]) {
                    valid = false;
                    break;
                }
            }
            if(valid) return true;
        }
        
        if(pos + k + 1 < n && st[pos + k + 1]) {
            for(int i = pos + 1; i < pos + k + 1; ++i) {
                if(st[i]) return false;
            }
            return true;
        }
        return false;
    }
};
