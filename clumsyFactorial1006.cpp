class Solution {
public:
    int clumsy(int N) {
        if(N == 0) return 0;
        vector<int>nums;
        vector<int>op;
        int count = 0, first, second;
        bool pickup = false;
        for (int i = N; i > 0; i--) {
            nums.push_back(i);
            if (pickup) {
                second = nums.back();
                nums.pop_back();
                first = nums.back();
                nums.pop_back();
                if (op.back()%4 == 0) {
                    //cout<<"push_back  "<< first<<" * " << second << endl;
                    nums.push_back(first*second);
                } else {
                    //cout<<"push_back  "<< first<<" / " << second << endl;
                    nums.push_back(first/second);
                }
                op.pop_back();
            }
            if (count%4<2) {
                pickup = true;
            } else {
                pickup = false;
            }
            
            if (i > 1)op.push_back(count);
            //cout<<"nums:  " << nums.back() << " op: " << op.back() << endl;
            count++;
        }
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (op[j]%4 == 2) {
                nums[0] = nums[0]+nums[i];
            } else {
                nums[0] = nums[0]-nums[i];
            }  
            j++;
        }

        return nums[0];
    }
};
//the fatest method
class Solution {
public:
    int clumsy(int N) {
        int flag=1, ret=0, val=0;
        for (int i=N; i>0; i-=4) {
            int k=i;
            val=k;
            k--;
            if (k<=1) break;
            val*=k;
            k--;
            if (k<=1) break;
            val/=k;
            k--;
            ret+=val*flag+k;
            flag=-1;
            val=0;
        }
        ret+=val*flag;
        return ret;
    }
};
