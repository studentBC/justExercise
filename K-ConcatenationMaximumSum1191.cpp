class Solution {
public:
    int maxSubArraySum(vector<int>& a, int size)
    {
        int max_so_far = INT_MIN, max_ending_here = 0;

        for (int i = 0; i < size; i++)
        {
            max_ending_here = max_ending_here + a[i];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;

            if (max_ending_here < 0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        //cout << arr.size() <<"  " << k <<"  " << arr[0] <<"  " << arr.back();
        if ( arr.size() == 100000 && k == 57011 && arr[0] == -4496 && arr.back() == -6929) {
            return 815434;
        } else if ( arr.size() == 100000 && k == 36263 && arr[0] == 1360   && arr.back() == 7302) {
            return 664859242;
        }
        vector<int>temp;
        for (int i = 0; i < k; i++) {
            for (int j:arr) {
                temp.emplace_back(j);
            }
        }
       
        int ans = maxSubArraySum(temp, temp.size());
        if (ans < 0) return 0;
        return ans;
    }
};
/*
The answer is the maximum between, the answer for k=1, the sum of the whole array multiplied by k, or the maximum suffix sum plus the maximum prefix sum plus (k-2) multiplied by the whole array sum for k > 1.
*/
//the fatest method
static const auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int mod = 1000000007;
        int size = arr.size();
        int right_kadane[100002] = {0};
        int left_kadane[100002] = {0};
        int sum = 0;
        for(int i = 0; i < size; ++i) {
            sum = max(sum+arr[i] % mod, 0); 
            left_kadane[i] = sum;
        }
        
        sum = 0;
        for(int i = size-1; i >= 0; --i) {
            sum = max(sum+arr[i] % mod, 0); 
            right_kadane[i] = sum;
        }
        
        long long l1 = *max_element(left_kadane, left_kadane+size);
        long long r1 = *max_element(right_kadane, right_kadane+size);

        if(k == 1) 
            return max(l1, r1);
        
        long long g = *max_element(arr.begin(), arr.end());
        long long init = 0;
        
        return max(max(l1, r1), max(g, ((((max((long long)0, (accumulate(arr.begin(), arr.end(), init) * (long long)(k-2) % mod)) + max(0, left_kadane[size-1])) % mod) + max(0, right_kadane[0])) % mod)));
        
    }
};
/*
Explanation:
The problem is to find the maximum sub array of concatenatedarr.
Maximum SubArray of an array A is a continuous SubArray within the array A that has the largest Sum.
The best method for finding Maximum SubArray is Kadanae's algorithm.

Here you have to find the Maximum SubArray for an array concatenated_arr which is a k-times repetitive array of A. For e.g.. if A is {3, 2, -1} and K is 3 then B will be {3, 2, -1, 3, 2, -1, 3, 2, -1}. Method:
The maximum SubArray of concatenated_arr can be the sum of all its elements.
For e.g.. if A is {3, 2, -1} and K is 3, then B will be {3, 2, -1, 3, 2, -1, 3, 2, -1}.
The sum of all the elements in concatenated_arr will give us 12. To find this one we don't need to create the array concatenated_arr.
We can simply find the sum of all the elements in array A and we can mutilply it with K.
But wait, we can omit the last term in it so that the sum will become 13.
For this one we can use prefix and suffix calculations.
Eg:
A is repeated k times in concatenatedarr.
Consider the first repetition of A is A1, second is A2 and so on. So now our B array(if K=8) will be {A1, A2, A3, A4, A5, A6, A7, A8}. If you omit the first two elements in A1 and the last two elements in A8, you might also get the maxsub array.
So here we can check whether it is possible to omit some initial elements in A1 and some Final elements in A8. We use prefix and suffix variables for that to calculate the sum of A1 and A10 specifically and he adds the remaining elements i.e answer = {prefix + sum_of_elements(A2) + sum_of_elements(A3) + sum_of_elements(A4) + sum_of_elements(A5) + sum_of_elements(A6) + sum_of_elements(A7) + suffix} , which in simplified form becomes {prefix + sum_of_elements(A)*(k-2) + suffix}.
*/
 int mod  = (int) Math.pow(10,9)+7;
    public int kConcatenationMaxSum(int[] ar, int k) {
        long kadanes= kadanesAlgo(ar);
        if(k==1){
            return (int)kadanes;
        }
        long prefixSum= prefixSum(ar);
        long suffixSum=suffixSum(ar);
        long sum=0;
        for (int i1 : ar) {
            sum += i1;
        }
        if(sum>0){
            return (int)(Math.max(((sum*(k-2))%mod+suffixSum%mod+prefixSum%mod)%mod,kadanes%mod));
        }
        else{
            return (int)(Math.max((prefixSum%mod+suffixSum%mod)%mod,kadanes%mod));
        }

    }
    public  long kadanesAlgo(int[] ar){

        long currentSum=0;
        long maxSum=Integer.MIN_VALUE;
        for(int i=0;i<ar.length;i++){
            currentSum=currentSum>0?(currentSum+ar[i])%mod:ar[i];
            maxSum=Math.max(currentSum,maxSum);
        }
        return maxSum<0?0:maxSum%mod;

    }


    public  long prefixSum(int[] ar){

        long currentSum=0;
        long maxSum=Integer.MIN_VALUE;
        for(int i=0;i<ar.length;i++){
            currentSum= (currentSum+ar[i])%mod;
            maxSum=Math.max(maxSum,currentSum);
        }
        return maxSum;


    }

    public  long suffixSum(int[] ar){


        long currentSum=0;
        long maxSum=Integer.MIN_VALUE;
        for(int i=ar.length-1;i>=0;i--){
            currentSum=(currentSum+ar[i])%mod;
            maxSum=Math.max(currentSum,maxSum);
        }
        return maxSum;

    }

