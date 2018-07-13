/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int  Toarray(int n) {
	int count = 1;
	int origin = n;
	while( n>=10 ) {
		n/=10;
		count++;
	}
	int array[count];
	int i = 0;
	int sum = 0;
	for(i = 0; i < count;i++) {
		array[i] = origin%10;
		sum +=(array[i]*array[i]);
		origin/=10;
	}

	return sum;
}
bool isHappy(int n) {
	int * array = NULL;
	while(n>=10) {
		n = Toarray(n);
		printf("%d \n", n);
	}
	
	if (n == 1 || n == 7) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int input;
	scanf("%d",&input);
	if (isHappy(input)) {
		printf(" happy ~~ \n");
	} else {
		printf(" not so happy \n");
	}
	return 0;
}
