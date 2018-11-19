int integerBreak(int n) {
	//from 1 to n
	int* breakdown = malloc(sizeof(int)*n);
	//both 1 and 2 product are 1
	breakdown[0] = breakdown[1] = 1;
	int half, max , product;
	for (int i = 3; i <= n; i++) {
		max = 0;
		half = i/2;
		for (int j = 1; j <= half; j++) {
			//not break * not break
			product = j*(i-j);
			if (max < product)max = product;
			// break * not break
			product = breakdown[j-1]*(i-j);
			if (max < product)max = product;
			//not break * break
			product = j*breakdown[i-j-1];
			if (max < product)max = product;
			// break * break
			product = breakdown[j-1]*breakdown[i-j-1];
			if (max < product)max = product;
		}
		breakdown[i-1] = max;
		printf("%d , ",max);
	}
	return breakdown[n-1];
}
