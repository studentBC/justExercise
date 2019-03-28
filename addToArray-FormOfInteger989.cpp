class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int>temp;
        vector<int>ans;
        while (K > 0) {
            temp.push_back(K%10);
            K/=10;
        }
        reverse (temp.begin(),temp.end());
        int carry = 0;
        int sum = 0;
        while(!temp.empty() || !A.empty()) {
             int num1 = 0;
             int num2 = 0;
             sum = 0;
             if(!temp.empty())
             {
                 num1 = temp.back();
                 temp.pop_back();
             }

             if(!A.empty())
             {
                 num2 = A.back();
                 A.pop_back();
             }

             sum = num1 + num2 + carry;
             if(sum >= 10) {
                 carry = 1;
                 sum = sum%10;
             } else {
                 carry = 0;
             }

             ans.push_back(sum);
         }
         if(carry != 0)
         {
             ans.push_back(carry);
         }
        reverse (ans.begin(),ans.end());
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int count = A.size()-1;
        //cout<<count<<endl;        
        int add = 0;
        int tempK=K;
        
        int Kdigit = 1;
        while(Kdigit!=0){//calculate digit of interger K
            if(K/10!=0){
                K=K/10;
                Kdigit++;
                continue;
            }
            break;
        }
        
        int digit_number = Kdigit >= A.size() ? Kdigit : A.size();//decide which number with more digit 
        digit_number--;
        // cout<<Kdigit<<","<<A.size()<<","<<digit_number<<endl;
                
        if(A.size()<=digit_number+1)//make array A fit with integer digit
            for(int i=A.size(); i<=Kdigit-1; i++ ){
                A.push_back(0);
                cout<<"i="<<i<<",asize="<<A.size()<<endl;
                for(int j=A.size()-1; j>=1; j--)
                    A[j] = A[j-1];
                A[0]=0;
            }
        //make K become array
        K = tempK;
        vector<int> Aplus(digit_number+1,0);
        int digit = 1;
        for(int i=digit_number; i>=0; i--){
            if(i<=digit_number-5)break;
            Aplus[i] = (K % (digit*10))/digit;
            K = K - Aplus[i];
            digit*=10;
        }
        
        //adding
        for(int i=digit_number; i>=0; i--){
            A[i] = Aplus[i]+A[i];
            if(A[i]>=10 && i!=0){                
                int temp_A = A[i];
                A[i] = A[i]%10;
                A[i-1] = A[i-1] + temp_A/10;
            }
            else if(A[i]>=10 && i==0){
                A.insert(A.begin(),A[i]/10);
               
               
                A[i+1]%=10;
                break;
            }
        }
    
        return A;
    }
};
