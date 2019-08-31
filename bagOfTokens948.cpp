class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort (tokens.begin(), tokens.end());
        int left = 0, right = tokens.size()-1, power = P, point = 0, ans = 0, sum = 0, temp;
        while (left <= right) {
            if (power >= tokens[left]) {
                power-=tokens[left];
                point++;left++;
                temp = power;sum = point;
                for (int i = left; i <= right; i++) {
                    if (temp>=tokens[i]) {
                        temp-=tokens[i];
                        sum++;
                    } else {
                        break;
                    }
                }
                ans = max(ans, sum);
            } else {
                left++;
            }
            
            if (point) {
                power+=tokens[right];
                point--;right--;
                sum = point;temp = power;
                //cout << left <<" , " << right << " : " << temp << endl;
                for (int i = left; i <= right; i++) {
                    if (temp>=tokens[i]) {
                        temp-=tokens[i];
                        sum++;
                    } else {
                        break;
                    }
                }
                ans = max(ans, sum);
            } else {
                right--;
            }
            
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        
        sort(tokens.begin(),tokens.end());
        
        int n = tokens.size();
        int l = 0;
        int r = n-1;
        int pts = 0;
        int mx = 0;
        
        while (l <= r) {
            if (P >= tokens[l]) {
                pts += 1;
                mx = max(mx,pts);
                P -= tokens[l];
                l += 1;
            } else {
                if (pts > 0) {
                    pts -= 1;
                    mx = max(mx,pts);
                    P += tokens[r];
                    r -= 1;
                } else {
                    break;
                }
            }
        }
        
        return mx;
    }
};
