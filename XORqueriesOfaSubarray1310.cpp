/*
What is the result of x ^ y ^ x ? it still be x
Compute the prefix sum for XOR.
Process the queries with the prefix sum values.

Explanation

In-place calculate the prefix XOR of input A.

For each query [i, j],
if i == 0, query result = A[j]
if i != 0, query result = A[i - 1] ^ A[j]
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        for(int i=1;i<arr.size();i++)
        {
            arr[i]=arr[i-1]^arr[i];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            if(queries[i][0]-1>=0)
            ans.push_back(arr[queries[i][1]]^arr[queries[i][0]-1]);
            else ans.push_back(arr[queries[i][1]]);
        }
        return ans;
    }
};
