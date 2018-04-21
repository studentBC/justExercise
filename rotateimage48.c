#include<stdio.h>
#include<stdlib.h>

void rotate(int** matrix, int matrixRowSize, int* matrixColSizes) {
//	matrix = malloc((*matrixColSizes)*sizeof(int*));
//	int col;
//	for(col=0;col<(*matrixColSizes);col++){
//		matrix[col] = malloc(matrixRowSize*sizeof(int));
//	}
//https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/?qa-rewrite=4493/rotate-the-matrix-inplace
      int i= 0;
      int turns = matrixRowSize;
      //first we have to know the four actual location to rotate
      int top , right,buttom,left,temp,startRow,endRow;
      top = startRow = 0;left = right =buttom= endRow = matrixRowSize-1;

      while(turns>=2){

		    // for 4 points to rotate at each round
		  for(i=0:i < matrixRowSize;i++){
		  	//for the top to right
		  	temp = matrix[startRow+i][right];
		  	matrix[startRow+i][right] = matrix[startRow][top+i];
		  	//for the left to top 
		  	matrix[startRow][top+i] = matrix[endRow-i][left];
		  	//for the buttom to left
		  	matrix[endRow-i][left] = temp;
		  }
		  startRow+=1;endRow-=1;
		  top+=1;right-=1;buttom-=1;left-=1;
          turns-=2;
      }   
	return ;	
}
int main(){
//	int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//	int* matrixColSizes = &matrix;
	int **matrix;
	int matrixColSize = 3;
	int *matrixColSizes = &matrixColSize;
	*matrix = matrixColSizes;
	matrix = malloc(*matrixColSizes*sizeof(int*));
	int col,row,count = 1;
	for(col=0;col<3;col++){
		matrix[col] = malloc(3*sizeof(int));
		for(row=0;row<3;row++){
			matrix[col][row] = count;
			printf("%d",matrix[col][row]);
			count++;
		}
		printf("\n");
	}
	rotate(matrix,3,matrixColSizes);
	int i = 0;
	int j = 0;
	for(i = 0;i< 3;i++){
		for(j = 0;j<3;j++){
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

