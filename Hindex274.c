int hIndex(int* citations, int citationsSize) {
	int maxh = 0, h = 0;
	for (int i = 1; i <= citationsSize; i++) {
		h = 0;
		for (int j = 0; j < citationsSize; j++) {
			if ( citations[j] >= i ) h++;
		}
		for (int k = 0; k < citationsSize; k++) {

		}
		if ( h >= i && maxh < i) {
			maxh = i;
		} else {
			return maxh;
		}
	}
	return maxh;
}
//the fatest method
int hIndex(int* citations, int citationsSize) {
    int *map = (int*)calloc((citationsSize+1), sizeof(int));
    int i;
    for(i=0; i<citationsSize; i++) {
        int idx = citations[i];
        if(idx > citationsSize) idx = citationsSize;
        map[idx]++;
        //printf("map[%d] = %d\n", idx, map[idx]);
    }

    int sum = 0;
    for(i=citationsSize; i>=0; i--) {
        sum += map[i];
        //printf("map[%d]: sum=%d\n", i, sum);
        if(sum >= i) {
            free(map);
            return i;
        }
    }
    free(map);
    return 0;
}
