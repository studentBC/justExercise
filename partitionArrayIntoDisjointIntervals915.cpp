class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int leftMax = A[0], smallest = A.back();
        vector<int>rightMin(A.size(),A.back());
        for (int i = A.size()-2; i >-1 ; i--) {
            if (A[i] < smallest) {
                smallest = A[i];
            }
            rightMin[i] = smallest;
            //cout << small[i] <<" , ";
        }
        for (int i = 0; i < A.size(); i++) {
            leftMax = max(leftMax, A[i]);
            if (leftMax <= rightMin[i+1]) {
                return i+1;
            } 
        }
        return 1;
    }
};
//the fatest method
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {

        int runningMax = A[0];
        int candidate = 0;
        int tempMax = A[0];
        for(int i=1;i<A.size();i++){
            if(A[i]<runningMax){
                candidate = i;
                continue;
            }
            //cout<<"Got "<<A[i]<<" max being "<<runningMax<<endl;
            while(i<A.size() && A[i]>=runningMax){
                //cout<<"Got "<<A[i]<<" tempmax being "<<tempMax<<endl;
                tempMax=max(tempMax,A[i]);
                ++i;
            }
            if(i>=A.size())break;
            runningMax=tempMax;
            candidate = i;
        }
        return candidate+1;
    }
};
