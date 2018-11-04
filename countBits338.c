/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int convertB(int a) {
	int left = 0;
	while(a > 0) {
		left += a & 1;
		a = a >> 1;
	}
	return left;
}
int* countBits(int num, int* returnSize) {
	*returnSize = num+1;
	int* ans = calloc(*returnSize , sizeof(int));
	for (int i = 1; i <= num; i++) {
		ans[i] = convertB(i);
	}
	return ans;
}
