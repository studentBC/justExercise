int hammingDistance(int x, int y) {
	int count = 0;
	for (int i = 1; i < 33; i++) {
		if ( (x >>i & 1) != (y >> i & 1) ) {
			count++;
		}
	}
    return count;
}
