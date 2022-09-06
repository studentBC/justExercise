class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<bitset<20000>>up(7), down(7);
        int len = tops.size(), ans = INT_MAX, turn, uc, dc;
        for (int i = 0; i < len; i++) {
            up[tops[i]][i] = 1;
            down[bottoms[i]][i] = 1;
        }
        for (int i = 1; i <= 6; i++) {
            bitset<20000>result = up[i] | down[i];
            //cout << result.count() << endl;
            if (result.count() >= len) {
                //cout <<"enter " << endl;
                uc = (result^up[i]).count();
                dc = (result^down[i]).count();
                ans = min(ans, min(uc, dc));
                
            }
        }
        return ans == INT_MAX?-1: ans;
    }
};
//106 ms solutionclass Solution {
  public:
  /*
  Return min number of rotations 
  if one could make all elements in A or B equal to x.
  Else return -1.
  */
  int check(int x, vector<int>& A, vector<int>& B, int n) {
    // how many rotations should be done
    // to have all elements in A equal to x
    // and to have all elements in B equal to x
    int rotations_a = 0, rotations_b = 0;
    for (int i = 0; i < n; i++) {
      // rotations coudn't be done
      if (A[i] != x && B[i] != x) return -1;
      // A[i] != x and B[i] == x
      else if (A[i] != x) rotations_a++;
      // A[i] == x and B[i] != x    
      else if (B[i] != x) rotations_b++;
    }
    // min number of rotations to have all
    // elements equal to x in A or B
    return min(rotations_a, rotations_b);
  }

  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int rotations = check(A[0], B, A, n);
    // If one could make all elements in A or B equal to A[0]
    if (rotations != -1 || A[0] == B[0]) return rotations;
    // If one could make all elements in A or B equal to B[0]
    else return check(B[0], B, A, n);
  }
};
