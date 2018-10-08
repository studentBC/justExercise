/*
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* function to sort arr using shellSort */
int shellSort(int* arr, int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
} 
int** getSkyline(int** buildings, int buildingsRowSize, int buildingsColSize, int* returnSize) {
    //first we need to find out the start and end position
    int start = 100000, end = 0, pc = 2*buildingsRowSize, a = 0;
	int* x = malloc(sizeof(int)*pc);
    for (int i = 0; i < buildingsRowSize; i++) {
        if (start > buildings[i][0]) {
            start = buildings[i][0];
        }
        if (end < buildings[i][1]) {
            end = buildings[i][1];
        }
		x[a] = buildings[i][0];
		x[a+1] = buildings[i][1];
		a+=2;
    }
	shellSort(x,pc);
    //vertical scan for 
    int prey = -1, high = -1;
    int** ans = malloc(sizeof(int*)*pc);
    bool fall = false;
    for (int i = 0; i < pc; i++) {
        high = 0;
        for (int j = 0; j < buildingsRowSize; j++) {
            if ( x[i]>= buildings[j][0] && x[i] < buildings[j][1] ) {
                if (high < buildings[j][2]) {
                    high = buildings[j][2];
                }
                fall = true;
            }
        }
        if (!fall) {
            high  = 0;
        }
        if (prey!=high) {
            prey = high;
            ans[*returnSize] = malloc(sizeof(int)*2);
            ans[*returnSize][0] = x[i];
            ans[*returnSize][1] = high;
            *returnSize = *returnSize+1;
        }
    }
    return ans;
}

