/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var findPeakGrid = function(mat) {
    var i = 0, j = 0, row = mat.length, col = mat[0].length, x, y, ni = 0, nj = 0;
    let dist = [-1, 0, 1, 0, -1];
    while(1) {
        i = ni
        j = nj
        let big = mat[i][j];
        for (let a = 0; a < 4; a++) {
            let x = i+dist[a]
            let y = j+dist[a+1]
            if (x > -1 && x < row && y > -1 && y < col) {
                if (big < mat[x][y]) {
                    big = mat[x][y];
                    ni = x
                    nj = y
                }
            }
        }
        if (ni == i && nj == j) return [i, j];
    }
    return [0, 0];
};
