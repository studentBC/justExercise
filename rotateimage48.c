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
	  int count = 0;
      //first we have to know the four actual location to rotate
      int lux,luy,rux,ruy,rdx,rdy,ldx,ldy,temp;
	  lux = luy = rux = ldy = 0;rdx = rdy = ldx = ruy = matrixRowSize-1;
      while(turns>=2){

		    // for 4 points to rotate at each round
		  for(i=0;i < ruy-count;i++){
		  	//for the top to right
		  	temp = matrix[rux+i][ruy];
		  	matrix[rux+i][ruy] = matrix[lux][luy+i];
		  	//for the left to top 
		  	matrix[lux][luy+i] = matrix[ldx-i][ldy];
		  	//for the buttom to left
		  	matrix[ldx-i][ldy] = matrix[rdx][rdy-i];
			//for right to buttom
			matrix[rdx][rdy-i] = temp;
		  }
		  lux+=1;luy+=1;rux+=1;ruy-=1;rdx-=1;rdy-=1;ldx-=1;ldy+=1;
          turns-=2;
		  count++;
      }   
	return ;	
}
int main(){
//	int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
//	int* matrixColSizes = &matrix;
	int **matrix = NULL;
	int matrixColSize = 10;
	int *matrixColSizes = &matrixColSize;
	//printf("the matrixColSizes is %d",*matrixColSizes);
	matrix = malloc(*matrixColSizes*sizeof(int*));
	int col,row,count = 1;
	for(col=0;col<*matrixColSizes;col++){
		matrix[col] = malloc(*matrixColSizes*sizeof(int));
		for(row=0;row<*matrixColSizes;row++){
			matrix[col][row] = count;
			printf("%d ",matrix[col][row]);
			count++;
		}
		printf("\n");
	}
	//*matrix = matrixColSizes;
	printf("-------------- \n");
	rotate(matrix,matrixColSize,matrixColSizes);
	int i = 0;
	int j = 0;
	for(i = 0;i< matrixColSize;i++){
		for(j = 0;j<matrixColSize;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

