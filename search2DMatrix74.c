void search(int** matrix, int i, int j, int target,int right, int down,bool* ans) {
    if (i > down || j > right || matrix[i][j] > target || matrix[i][j] == -1) {
        return;
    } else if (target == matrix[i][j]) {
        *ans = true;
        return;
    }
    matrix[i][j] = -1;
    if (i == down && j < right) {
        search(matrix, i, j+1, target, right, down,ans);
    } else if (i < down && j == right) {
        search(matrix, i+1, j, target, right, down,ans);
    } else if (i < down && j < right) {
        if (matrix[i+1][j] <= target && matrix[i][j+1] <= target) {
            if (matrix[i+1][j] < matrix[i][j+1]) {
                search(matrix, i, j+1, target, right, down,ans);
            } else {
                search(matrix, i+1, j, target, right, down,ans);
            }
        } else if (matrix[i+1][j] <= target && matrix[i][j+1] > target) {
                search(matrix, i+1, j, target, right, down,ans);
        } else {
                search(matrix, i, j+1, target, right, down,ans);
        }
    }
    return;
}
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i = matrixRowSize/2;
    int j = matrixColSize/2;
    int middle = matrix[i][j];
    bool* ans = malloc(sizeof(bool));
    *ans = false;
    if (target < middle) {
        search(matrix, 0, 0, target, matrixColSize -1, i,ans);
    } else {
        search(matrix, i, 0, target, matrixColSize -1 , matrixRowSize -1,ans);
    }
    return *ans;
}

