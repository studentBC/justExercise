#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* longestPalindrome(char* s) {
    int length = strlen(s);
    char* Palindrome = NULL;
    if (length == 1){
        return s;
    }
    int i = 0;
    int alphabet[26];
    int location[length];
    int count = 0;
    for (i = 0;i< length;i++){
        printf("%d\n",s[i]-97);
        alphabet[s[i]-97]++;
    }
    char possible[length];
    for (i =0;i<26;i++){
        if (alphabet[i] >1){
            count++;
        }
    }
    int j = 0 , k = 0 ,start, from = 1000,to = -1;
    int newlength = 0;char* newstr=NULL;
    char* longestPalindrome = "";
    while(start<26){
        
        if(alphabet[start] > 1){
            for (j = 0; j < length;j++){
                if ((s[j]-97) == start){
                    if (j<from) {
                        from = j;
                    } else if (j > to){
                        to = j;
                    }
                }
            }
            newlength = to-from+1;
            newstr = malloc(sizeof(char)*(newlength+1));
            for (i = 0; i < newlength;i++){
                newstr[i] = s[from+i];
            }
            newstr = findPalindrome(newstr);
            printf("%s",newstr);
            if (strlen(newstr) > strlen(longestPalindrome)){
                longestPalindrome = newstr;
            }else{
                free(newstr);
            }
        }
        start++;
    }
     return Palindrome;

}
char* findPalindrome(char* s){
    int length = strlen(s);
   
     bool mark[length];
     int i = 0;
     int count = 0,biggestCount = 0;
     char* Palindrome;
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
      int start;
      for(i = 0; i < length;i++){
          if(mark[i]){
              count++;
              printf("count %d",count);
              if(count ==2 ){
                  start = i-1;
              }
              if (count>biggestCount) {
                      biggestCount = count;
              }
          } else {
              count =0;
          }
      }
    printf("start form %d big count is %d",start,biggestCount);
      Palindrome = malloc((biggestCount+1)*sizeof(char));
      for(i = 0; i < biggestCount;i++){
          Palindrome[i] = s[start+i];
      }
     return Palindrome;
} 
int main(){
	char* palindrome= "spxps";
	printf("%s\n",longestPalindrome(palindrome));
}
