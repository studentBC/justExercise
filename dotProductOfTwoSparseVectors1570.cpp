/*
Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?

 

Example 1:

Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
Output: 8
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
Example 2:

Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
Output: 0
Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
Example 3:

Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
Output: 6
 

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 100
*/
class SparseVector {
public:
    unordered_map<int,int>number;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) number[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        long long sum = 0;
        for (auto& it : vec.number) {
            if (number[it.first]) {
                sum+=(it.second*number[it.first]);
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
//116 ms solution
#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class SparseVector {
 public:
    vector<int> v;     
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++)
             if (nums[i]) {
                 this->v.push_back(i);
                 this->v.push_back(nums[i]);
             } 
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int DP =  0;
        int i1 = 0;
        int i2 = 0;
        while( i1 < this->v.size() && i2 < vec.v.size() )
        {
            int pos1 = this->v[i1];
            int pos2 = vec.v[i2];
            if (pos1==pos2) {
                DP += this->v[i1+1]*vec.v[i2+1];
                i1 += 2;
                i2 += 2;
            }          
            else if (pos1<pos2) i1 += 2; 
                else i2 += 2;
        }
        return DP;
    }
};
