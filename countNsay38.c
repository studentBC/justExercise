#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* transform(char* ans) {
    int length = strlen(ans);
    printf("the len is %d \n",length);
    int count = 1,start = 0 ,i=0,j;
    char* answer = calloc(2*length+1,sizeof(char));
    while (i < length) {
        for (j = i+1; j < length; j++) {
            if(ans[i] == ans[j]) {
                count++;
            } else {
				break;
			}
        }        
        answer[start] = count+'0';
        answer[start+1] = ans[i];
        if (count >1) {
            i +=count;
        } else {
            i++;
        }
        start+=2;
        count = 1;
    }
    free(ans);
	count = 0;
	for (i = 0; i < strlen(answer);i++) {
		if(answer[i] > 0) {
			count++;
		} else {
			break;
		}
	}
    char* answers = calloc(count+1,sizeof(char));

	for (i = 0; i < count;i++) {
		answers[i] = answer[i];
	}
	free(answer);
    return answers;
}

char* countAndSay(int n) {
    char* ans = (char*)calloc(2,sizeof(char));
    ans[0] = '1';int i;
	printf(" enter countAndSay \n");
    for (i = 1; i<n; i++) {
        ans = transform(ans);
    }
    return ans;
}
int main() {
	int in;
	scanf("%d",in);
	char* str = countAndSay(in);
	printf("%s\n",str);
		return 0;
}
//the fatest method
char *countAndSay(int n) {
    static char buf1[5000];
    static char buf2[5000];
    
    char *cur = buf1, *next = buf2;
    
    for (int N=1; N<=n; N++) {
        if (N==1) {
            next[0] = '1';
            next[1] = '\0';
        }
        else {
            int i=0, c=0;
            while (cur[i]) {
                int j;
                for (j=i; cur[j]==cur[i]; j++);
                next[c++] = '0'+j-i;
                next[c++] = cur[i];
                i = j;
            }
            next[c] = '\0';
            
        }
    
        char *temp = cur;
        cur = next;
        next = temp;
    }
    
    return cur;
    
}

char* countAndSayBad(int n) {
    if (n==1){
        return "1";
    }
    
    int resInt = 1;
    char newResStr[100];
    char *res = newResStr;
    char temp[10];
    int count;
    int changes;
    char prev;
    
    for (int i=1; i<n; i++){
        
        int size = numOfDigits(resInt);
        char resStr[size];
        sprintf(resStr, "%d", resInt);
        printf("\ni=%d; resStr=%s; resInt=%d; size=%d", i, resStr, resInt, size);
        
        count = 0;
        changes = 0;
        prev = resStr[0];
        
        for (int j=0; j<size; j++){
            printf("\n\tj=%d; count=%d; changes=%d; prev=%c", j, count, changes, prev);
            if (resStr[j] != prev){
                sprintf(temp, "%d", count);
                newResStr[changes*2] = temp[0];
                newResStr[changes*2+1] = prev;
                changes += 1;
                count = 1;
                prev = resStr[j];  
            }
            else {
                count += 1;
            }
        }
        sprintf(temp, "%d", count);
        printf("\nThe count is: %d", count);
        newResStr[changes*2] = temp[0];
        newResStr[changes*2+1] = prev;
        newResStr[(changes+1)*2] = '\0';
        
        resInt = atoi(newResStr);
        printf("\nThe resInt is: %d", resInt);
        printf("\nThe newResStr is: %s", newResStr);
    }
    
    //char *ret;
    //sprintf(resStr, "%d", resInt);
    //*ret = newResStr;
    //printf("\nThe value stored at ret is: %s", ret);
    return res;
}

int numOfDigits(int n) {
    int count = 0;
    while (n){
        n /= 10;
        count ++;
    }
    return count;
}
