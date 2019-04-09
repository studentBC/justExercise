class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
 		vector<int>ans;
		int sa = 0, sb = 0, ave, temp;
		for (int i = 0; i < A.size(); i++) sa+=A[i];
		for (int i = 0; i < B.size(); i++) sb+=B[i];
		ave = sa + sb;
		ave = ave >> 1;
		sa =ave - sa;
		for (int i = 0; i < A.size(); i++) {
			temp = A[i]+sa;
			cout << "try to find " << temp << endl;
			if ( temp > 0 && find(B.begin(), B.end(), temp)!=B.end()) {
				ans.push_back(A[i]);
				ans.push_back(temp);
				return ans;
			}
		}

		return ans;
    }
};
//the fatest method
class Solution {
public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
      int Acount[100005] = {0};
      int Bcount[100005] = {0};
      int Asum = 0, Bsum = 0;
      int Amin=100004, Amax=0, Bmin=100004, Bmax=0;
      vector<int> v;        
      for(auto &Ai:A){
          Asum += Ai;Acount[Ai]++;
          Amin = min(Amin,Ai);
          Amax = max(Amax,Ai);
      }
      for(auto &Bi:B){
          Bsum += Bi;Bcount[Bi]++;
          Bmin = min(Bmin,Bi);
          Bmax = max(Bmax,Bi);
      }

      int size = (Asum - Bsum)/2;

      int Ainx = Amin, Binx = Bmin;
      while(Ainx <= Amax){
          if(Acount[Ainx] > 0 && Ainx-size >= Bmin && Ainx-size <= Bmax && Bcount[Ainx-size] > 0){
              v.push_back(Ainx);
              v.push_back(Ainx-size);
              return v;
          }
          Ainx++;
      }

      return v; 

  }
};

