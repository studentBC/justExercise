class Solution {
public:
    bool judge(vector<int>& nums) {
        int len = nums.size() -1;
        for (int i = 0; i < len; i++) {
            if (i%2 == 0) { 
                if (nums[i] >= nums[i+1])return false;
            } else {
                if (nums[i]<=nums[i+1])return false;
            }
        }
        return true;
    }

    void wiggleSort(vector<int>& nums) {
        vector<int>temp;
        temp.assign(nums.begin(), nums.end());
        sort(temp.begin(),temp.end());
        //for (int a = 0; a < temp.size(); a++) cout << nums[a] << " , " ;
        int start = nums.size()-1 , count = 0;
        if (nums.size()%2 == 0) {
            for (int j = start; j > -1; j-=2) {
                nums[j] = temp[start-count];
                count++;
            }
            //cout<<endl;
            //for (int a = 0; a < temp.size(); a++) cout << nums[a] << " , " ;
            count = 0;
            for (int j = 0; j < nums.size(); j+=2) {
                nums[j] = temp[count];
                count++;
            }
            //cout<<endl;
            //for (int a = 0; a < temp.size(); a++) cout << nums[a] << " , " ;
            if (!judge(nums)) {
                count = 0;
                for (int j = nums.size()-2; j > -1; j-=2) {
                    nums[j] = temp[count];
                    count++;
                }
                //cout<<endl;
                //for (int a = 0; a < temp.size(); a++) cout << nums[a] << " , " ;
                count = nums.size()-1;
                for (int j = 1; j < nums.size(); j+=2) {
                    nums[j] = temp[count];
                    count--;
                }
                //cout<<endl;
                //for (int a = 0; a < temp.size(); a++) cout << nums[a] << " , " ;

            }
        } else {
            start = nums.size()-2 , count = 1;
            for (int j = start; j > -1; j-=2) {
                nums[j] = temp[nums.size()-count];
                count++;
                start = j;
            }
            //cout << endl << "--------------- else ----------------" << endl;
            //for (int a = 0; a < temp.size(); a++) cout << nums[a] << " , " ;
            count = 0;
            for (int j = 0; j < nums.size(); j+=2) {
                nums[j] = temp[count];
                count++;
            }
            //cout << endl;
            //for (int a = 0; a < temp.size(); a++) cout << nums[a] << " , " ;

        }
        return ;
    }

};
//fatest method
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
       int i=nums.size()-1, m=i/2+1, j=0;
        // int i=nums., m=()nums.size()-1)/2, j=0;
        
        for(; i>=0; i--)
            nums[i] = sorted[i&1 ? m++ : j++];
        
        return;
    }
};
