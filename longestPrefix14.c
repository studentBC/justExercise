#include<stdio.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0,smallest = 1000000, j = 0;char* ans = NULL;
    if (strsSize == 0 || strlen(strs[0]) == 0) {
        ans ="";
        return ans;
    }
    //find the smallest string first
    for (i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) < smallest) {
            smallest = strlen(strs[i]);
        }
    }
    ans = malloc(sizeof(char)*smallest+1);
    for (i = 0; i < smallest;i++) {
        ans[i] = strs[0][i];
    }
    ans[smallest] = '\0';
    //find the longest common prefix now
    for (i = 1; i < strsSize; i++) {
        for (j = 0; j < smallest;j++) {
            if (ans[j] != strs[i][j]) {
                ans[j] = '\0';
                break;
            }  
        }   
    }
    return ans; 
}
int main(){
	char** str = ["flower","flow","flight"];
	printf("%s",longestCommonPrefix(str));
	return 0;
}
