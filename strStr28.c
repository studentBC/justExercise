#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int strStr(char* haystack, char* needle) {
    int i = 0 , j = 0 , start = -1;
    if (strlen(needle) == 0 ) {
        return 0;
    }
    printf(" before get str length \n");
    //printf("%lu \n",strlen(haystack));
    //printf("%lu \n",strlen(needle));
//    if (strcmp(needle,"bbabba") == 0){
//        printf(" found that ");
//        return -1;
//    }
    printf(" after get strlen ");
    for (i = 0; i < strlen(haystack);i++) {
        if (haystack[i] == needle[0] && strlen(needle) <= strlen(haystack)-i) {
            for (j = 0; j < strlen(needle);j++) {
                start = i;
                if (needle[j] != haystack[j+i]) {
                    break;
                }
                if (j == strlen(needle) - 1) {
                    return start;
                }
            }
        }
    }
    return -1;
}
int main(){
char* found = "bbababaaaababbaabbbabbbaaabbbaaababbabaabbaaaaabbaaabbbbaaabaabbaababbbaabaaababbaaabbbbbbaabbbbbaaabbababaaaaabaabbbababbaababaabbaa";
char* founder = "bbabba";
printf("%d \n",strStr(found,founder));
}
