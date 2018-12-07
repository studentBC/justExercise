int cartesianproduct(int* count, int f) {
	int sum = 0;
	for (int i = 1; i <= f; i++) {
		sum+=(count[i-1]*count[f-i]);
	}
	return sum;
}
int numTrees(int n) {
	int* count = calloc(n+1,sizeof(int));
	count[0] = count[1] = 1;
	for (int i = 2; i <=n ;i++) {
		count[i] = cartesianproduct(count, i);
	}
	return count[n];
}
