class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>>order(B.size(), vector<int>(A.size(),-1));
        vector<vector<int>>length(B.size(), vector<int>(A.size(),1));
        int max = 0;
        bool same = true;
        if (A.size() != B.size()) same = false;
        for (int i = 0; i < B.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                if (B[i] == A[j]) {
                    order[i][j] = i;
                    if (i>0 && j > 0 && order[i-1][j-1] == i-1) {
                        length[i][j] = length[i-1][j-1]+1;
                        if (max < length[i][j]) max = length[i][j];
                    } else if (max < length[i][j]) {
                        max = length[i][j];
                    }
                    //cout << length[i][j] << " , ";
                }
            }
            if (A[i] != B[i]) same = false;
            //cout << endl;
        }

        return max;
    }
};
//the fatest method
class Solution {
public:
    
    int findLength(vector<int>& A, vector<int>& B){
        
      int m = 1e9 + 9; // TODO        
      int p = 101;  
       
      //compute hashes of prefixes of A and B 
      int n=max(A.size(),B.size());
      vector<long long> pow(n); 
      pow[0]=1;
      for(int i=1;i<n;i++) 
        pow[i] = (p*pow[i-1])%m; 
      vector<long long> hashes_a = ComputePrefixHashes(A,pow,m);
      vector<long long> hashes_b = ComputePrefixHashes(B,pow,m);  
      
      // binary search on possible lengths 
      int len_min=0;
      int len_max=min(A.size(),B.size());  
      while (len_max>len_min){
        int t=len_min+len_max;   
        int len=(t%2==0)?t/2:(t/2+1);
        if ( CheckCommonSubarray(A,B,len,hashes_a,hashes_b,pow,m) )
          len_min = len;
        else
          len_max = len-1; 
        //cout << len << endl;    
      }  
      return len_min;      
    }
    
    vector<long long> ComputePrefixHashes(const vector<int>& A, const vector<long long>& pow, int m)
    {
      int n=A.size();   
      vector<long long> hashes(n);
      hashes[0]=(A[0]+1)%m;  
      for(int i=1;i<n;i++)  
        hashes[i] = (hashes[i-1]+(A[i]+1)*pow[i])%m;  
      return hashes;   
    }
    
    bool CheckCommonSubarray(vector<int>& A,
                             vector<int>& B,
                             int len,
                             vector<long long>& hashes_a,
                             vector<long long>& hashes_b,
                             vector<long long>& pow,
                             int m){
       
      if (len==0) return true;   

      unordered_map<long long,bool> h;
      int n=max(A.size(),B.size());                 
      // hash all substrings of A  
      for (int i=0;i+len-1<A.size();i++)
        if (i>0)  
          h[(pow[n-1-i]*((hashes_a[i+len-1]+m-hashes_a[i-1])%m))%m]=true;
        else 
          h[(pow[n-1-i]*(hashes_a[i+len-1]))%m]=true;
        
      int i=0;
      bool found=false;  
      while (i+len-1<B.size() && !found)
      {
        int hb;
        if (i>0)
          hb=(pow[n-1-i]*((hashes_b[i+len-1]+m-hashes_b[i-1])%m))%m;
        else   
          hb=(pow[n-1-i]*(hashes_b[i+len-1]))%m;  
        if (h.find(hb)!=h.end())
          found=true;
        i++;  
      }
      
      return found;  
        
    }   
};
