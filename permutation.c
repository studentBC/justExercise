 /**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int factorial(int n) {
    if (n == 0)
        return 1;
    return factorial(n - 1) * n;
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int **pnums;
    *returnSize = factorial(numsSize);
    pnums = malloc(*returnSize * sizeof(int*));
    if (numsSize == 0 || numsSize == 1) {
        pnums[0] = malloc(numsSize * sizeof(int));
        if (numsSize == 1)
            pnums[0][0] = nums[0];
        return pnums;
    }
    for (int i = 0; i < numsSize; i++) {
        int **snums, subSize, *tnums = malloc((numsSize - 1) * sizeof(int));
        for (int j = 0, m = 0; j < numsSize; j++)
            if (j != i)
                tnums[m++] = nums[j];
        snums = permute(tnums, numsSize - 1, &subSize);
        free(tnums);
        for (int j = 0; j < subSize; j++) {
            pnums[i * subSize + j] = malloc(numsSize * sizeof(int));   
            pnums[i * subSize + j][0] = nums[i];
            for (int k = 0; k < numsSize - 1; k++)
                pnums[i * subSize + j][k + 1] = snums[j][k];
            free(snums[j]);
        }
        free(snums);
    }
    return pnums;
}
//cpp solution
class Solution {
public:
    vector<vector<int>>ans;
    int len;
    void go (int start, vector<int> nums) {
        if (start == len) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < len; i++) {
            swap(nums[start], nums[i]);
            go (start+1, nums);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        go (0, nums);
        return ans;
    }
};
