//fatest method
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if (len == 0) {
        return 0;
    }
    
    // sliding window approach
    // the window stores the count of current added char
    int max = 1;
    int i = 0;
    int j = 0;
    int arr[256] = {0}; // the 'arr' stores the count of letter in the window
    while (i < len && j < len) {
        if (arr[s[j]] == 0) {
            arr[s[j]]++; // put the letter into the window
            j++; // move right border forward
            
            int len = j - i;
            max = max < len ? len : max; // note that we should update max here every time the window size has enlarged.
        } else if (arr[s[j]] > 0) {
            // the current s[j] we want to add has a dup in the 'window', so what we do is
            // to move left border of window, and see if we can match the criteria
            arr[s[i]]--;
            i++;
        }
    }
    return max;
}
//my method only beat 12%...
bool isContain(char* str, char target, int* count) {
    
    if (*count == 0) {
        str[0] = target;
        *count = *count+1;
        return false;
    } else {
        //printf("at input %c its count is %d \n",target,*count);
        for (int i = 0; i < *count; i++) {
            if (str[i] == target) {
                //printf("input char %c and it is true \n",target);
                return true;
            }
        }
        str[*count] = target;
        *count = *count+1;
        //printf("count is %d \n",*count);
        
    }
    return false;
}
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    char* str = calloc((len+1),sizeof(char));
    int max = 0 , start = 0;
    int* count = malloc(sizeof(int));
    *count = 0;
    //printf("length is %d \n",len);
    while(start < len) {
        for (int i = start; i < len; i++) {
            if ( isContain(str , s[i], count) ) {
                //printf("now is %dth \n",i);
                i--;
                memset(str,'\0',len);
                *count = 0;
                break;
            }
            if (max < *count) {
                    max = *count;
            }
        }
        start++;
    }
    return max;
}
