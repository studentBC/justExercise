/*
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], which means the matrix is rows * cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.
*/
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int>d=binaryMatrix.dimensions();
        int left, right, mid, ans = 10000;
        for (int i = 0; i < d[0]; i++) {
            left = 0, right = d[1];
            while (left <= right) {
                mid = (left+right)/2;
                if (mid<0 || mid >= d[1]) break;
                if (binaryMatrix.get(i, mid)) {
                    ans = min(ans, mid);
                    right = mid-1;
                } else {
                    left = mid+1;
                }  
            }
        }
        if (ans == 10000) return -1;
        return ans;
    }
};
//the fatest solution
#define LNO

[[maybe_unused]] static auto const fast = []{return ios_base::sync_with_stdio(false);}();

inline
namespace leetcode_linear_search
{
 struct a_solution
 {
  BinaryMatrix& matrix;
  int const M;
  int const N;

  a_solution (BinaryMatrix& matrix)
  : matrix(matrix)
  , M(matrix.dimensions()[0])
  , N(matrix.dimensions()[1])
  {
  }

  int solve ()
  {
   auto m = N;
   for (auto i = 0, j = N-1; i < M && j >= 0;)
   {
    auto const value = matrix.get(i,j);
    if (value == 0)
    {
     ++i;
    }
    else if (value == 1)
    {
     m = min(m,j);
     --j;
    }
    else
    {
     LNO; throw "control should never reach here.";
    }
   }
   return m >= N ? -1 : m;
  }
 };
} 

struct Solution
{
 int leftMostColumnWithOne (BinaryMatrix& matrix)
 {
  return a_solution{matrix}.solve();
 }
};
