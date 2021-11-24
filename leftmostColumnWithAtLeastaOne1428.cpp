/*
 (This problem is an interactive problem.)

A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.

You can't access the Binary Matrix directly. You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols], which means the matrix is rows x cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes, the input will be the entire binary matrix mat. You will not have access to the binary matrix directly.

 

Example 1:



Input: mat = [[0,0],[1,1]]
Output: 0
Example 2:



Input: mat = [[0,0],[0,1]]
Output: 1
Example 3:



Input: mat = [[0,0],[0,0]]
Output: -1
Example 4:



Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
 

Constraints:

rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in non-decreasing order.
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
        vector<int>boundary = binaryMatrix.dimensions();
        vector<int>pos;
        int left, right, mid, j, index, ans = INT_MAX;
        for (int i = 0; i < boundary[0]; i++) {
            left = 0; right = boundary[1]-1; index = INT_MAX;
            while (left <= right) {
                mid = (left+right)/2;
                j = binaryMatrix.get(i, mid);
                if (j) {
                    right = mid-1;
                    index = min(mid, index);
                } else left = mid+1;
            }
            ans = min(index, ans);
        }
        return ans == INT_MAX?-1 : ans;
    }
};
//0 ms solution
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        auto const& dimensions = binaryMatrix.dimensions();
        auto rowCount = dimensions[ 0 ];
        auto colCount = dimensions[ 1 ];

        int result = INT_MAX;
        for( int row = 0; row < rowCount; row++ )
        {
            //if ( binaryMatrix.get( row, col ) == 1 ) return col;
            int start = 0;
            int end = colCount - 1;
            while( start <= end )
            {
                if ( start >= end ) 
                {
                    if ( binaryMatrix.get( row, start ) == 1 )
                    {
                        result = min( result, start );
                    }
                    break;
                }
                
                int middle = ( end + start ) / 2;
                bool isOne = binaryMatrix.get( row, middle ) == 1;
                if ( isOne )
                {
                    end = middle - 1;
                    result = min( result, middle );
                }
                else
                {
                    start = middle + 1;
                }
            }
        }

        
        return result == INT_MAX ? -1 : result;
        
    }
};
