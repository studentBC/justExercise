class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int end = A.size()-1, max , min, count = 1, step, ans = 0;
        vector<int>even(end, INT_MIN);
        vector<int>odd(end, INT_MIN);
		vector<int>success;
        for (int i = 0; i < end; i++) {
            max = INT_MIN;min = INT_MAX;
            for (int j = i+1; j <= end; j++) {
                if (A[j] >= A[i]) {
                    if (A[j] < min) {
                        min = A[j]; 
                        odd[i] = j;
                    }
                }
                if (A[j] <= A[i]) {
                    if (A[j] > max) {
                        max = A[j]; 
                        even[i] = j;
                    }
                }
            }
        }
    /*    
        for (int i = 0; i < end; i++) {
            cout << odd[i] <<" , ";
        }
        cout << endl;
        for (int i = 0; i < end; i++) {
            cout << even[i] <<" , ";
        }
*/
        for (int i = 0; i < end; i++) {
            step = i;
            count = 1;
            //cout << endl << " go from " << i << endl;
            while (1) {
                if (step == end) {
                    ans++;
					success.push_back(i);
                    break;
                } else if (step == INT_MIN) {
                    break;
                }
				if (success.size() > 0 && step <= success.back() && count%2 == 1) {
					for (int j = 0; j < success.size(); j++) {
						if (success[j] == step) {
                    		ans++;
							success.push_back(i);
                    		break;
						}
					}
					break;
				}
                //cout << step << " , ";
                if (count%2 == 1) {
                    step = odd[step];
                } else { 
                    step = even[step];
                }
                count++;
            }
        }
        return ans+1;
    }
};
//the fatest method
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int len = (int)A.size();
        
        vector<pt> pts;
        pts.reserve(len);
        for(int i = 0; i < len; ++i) {
            pts.push_back(pt(A[i], i));
        }
        cmp cp;
        sort(pts.begin(), pts.end(), cp);
        
        stack<int> stk;
        vector<int> dpOdJmp(len, 0);
        for(int j = len - 1; j >= 0; --j) {
            int id = pts[j].i;
            while(!stk.empty() && stk.top() < id){
                stk.pop();
            }
            dpOdJmp[id] = (stk.empty() ? -1 : stk.top());
            stk.push(id);
        }
        
        cmp2 cp2;
        sort(pts.begin(), pts.end(), cp2);
        stk = stack<int>();
        vector<int> dpEvJmp(len, 0);
        for(int j = len - 1; j >= 0; --j) {
            int id = pts[j].i;
            while(!stk.empty() && stk.top() < id){
                stk.pop();
            }
            dpEvJmp[id] = (stk.empty() ? -1 : stk.top());
            stk.push(id);
        }
        
        vector<bool> dpOdIsG(len, false), dpEvIsG(len, false);
        dpOdIsG[len - 1] = dpEvIsG[len - 1] = true;
        for(int i = len - 2; i >= 0; --i) {
            if(dpOdJmp[i] == -1)
                dpOdIsG[i] = false;
            else
                dpOdIsG[i] = dpEvIsG[dpOdJmp[i]];
            
            if(dpEvJmp[i] == -1)
                dpEvIsG[i] = false;
            else
                dpEvIsG[i] = dpOdIsG[dpEvJmp[i]];
        }
        
        int ret = 0;
        for(auto b : dpOdIsG)
            if(b) ++ret;
        
        return ret;
    }
};
