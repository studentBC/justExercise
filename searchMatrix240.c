/*
 *
 *[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
  ]
 *
 *
 *
 *
 *
*/
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
	if (target < matrix[0][0] || target > matrix[matrixRowSize-1][matrixColSize-1]) {
		return false;
	}
	int possibleRow[matrixRowSize];
	int possibleCol[matrixColSize];
	int i , r , c , pr = 0,pc = 0;
	for (i = 0; i < matrixRowSize ;i++) {
		if (target >= matrix[i][0] && target <= matrix[i][matrixColSize-1]) {
			possibleRow[pr] = i;
			printf("possible row is %d \n",i);
			pr++;
		}
	}
	for (i = 0; i < matrixColSize ;i++) {
		if (target >= matrix[0][i] && target <= matrix[matrixRowSize-1][i]) {
			possibleCol[pc] = i;
			printf("possible col is %d \n",i);
			pc++;
		}
	}
	for (r = 0; r < pr ; r++) {
		for (c = 0; c < pc ;c++) {
			if (target == matrix[possibleRow[r]][possibleCol[c]]) {
				return true;
			}
		}
	}
	return false;
}

//fatest method ... to my suprise the stupid method is the fatest ..@"@
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i, j;
    for (i = 0; i < matrixRowSize; i++) {
        for (j = 0; j < matrixColSize; j++) {
            if (matrix[i][j] == target) return true;
        }
    }
    return false;
}
