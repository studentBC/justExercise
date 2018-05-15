#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* longestPalindrome(char* s) {
   int length = strlen(s);
   bool mark[length];
   int i = 0;
   int count = 0,biggestCount = 0;
   char* Palindrome,longestPalindrome;
	for(i = 0; i < length/2;i++){
		if(s[i] == s[length-1-i]){
			mark[i] = mark[length-1-i] = true;
		}else{
			mark[i] = mark[length-1-i] = false;
		}
	}
   if(length%2 == 1){//odd
		mark[length/2] = true;	
   }
	//find the longthest 
	for(i = 0; i < length;i++){
		if(mark[i]){
			count++;
			if(count >=2 ){
				if(count>biggestCount){

				}
			}
		}else{
			count =0;
		}

	}
   return truncatedPalindrome;
}
int main(){
	char* palindrome= "spxps";
	printf("%s\n",longestPalindrome(palindrome));
}
