#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
/*
Input: "A man, a plan, a canal: Panama"
Output: true
*/
bool isPalindrome(char* s) {
	int i , length = strlen(s) , count = 0;
	if(length == 0) {
		return true;
	}
	char* alphabet = calloc(length,sizeof(char));
	for (i = 0 ;i < length; i++) {
		if(s[i] >47 && s[i] < 58) {
			alphabet[count] = s[i];
				count++;
		} else if (s[i] < 91 && s[i] >64) {
			alphabet[count] = s[i]+32;
				count++;
		} else if (s[i]>96 && s[i]<123) {
			alphabet[count] = s[i];
				count++;
		}
	}
	length = count/2;
	for (i = 0; i < length ;i++) {
			printf("lower letter is %c",s[i]);
		if(alphabet[i] != alphabet[count-1-i]) {
			count--;
			return false;
		}
	}
	return true;
}
int main() {
	char temp[] = {"0P"};

	if ( isPalindrome(temp)) {
		printf(" it is palindrome !! \n");
	} else {
		printf(" it is not palindrome !! \n");
	}
	return 0;
}
//the fatest method
bool isPalindrome(char* s) {
    int len = strlen(s);
    
    int left = 0, right = len-1;
    bool output=1;
    
    while(left<right && len>0 && right>=0 && left<len){
    // scan the alphanumeric chars from left and right respectively
        while((s[left] < 'a' || s[left] > 'z')&&(s[left] < 'A' || s[left] > 'Z')&&(s[left] < '0' || s[left] > '9')){
            left++;
            if(left>=len){
                output=0;
                break;
            }
        }
        
        while((s[right] < 'a' || s[right] > 'z')&&(s[right] < 'A' || s[right] > 'Z')&&(s[right] < '0' || s[right] > '9')&&output){
            right--;
            if(right<0){
                output=0;
                break;
            }
        }
        
    // if there is not any alphanumeric char, return true.
        if(output==0){
            output=1;
            break;
        }
        
        int inteval='a'-'A'; // Lowercases have larger ascii code values.
        
    // compare left char with right char
        if(s[left]==s[right]){
            left++;
            right--;
        }
        else if(s[left]>s[right] && s[left] >= 'a' && s[left] <= 'z'){ // maybe is the same alpha but different size case.
            if(inteval!=s[left]-s[right]){
                output=0;
                break;
            }
            else{
                left++;
                right--;
            }
        }
        else if(s[left]<s[right] && s[right] >= 'a' && s[right] <= 'z'){ // maybe is the same alpha but different size case.
            if(inteval!=s[right]-s[left]){
                output=0;
                break;
            }
            else{
                left++;
                right--;
            }
        }
        else{
            output=0;
            break;
        }
    }
    
    return output;
}

