bool isValid(char* s) {
int i = 0;
int length = strlen(s);
char* queue = (char*)calloc(length+1,sizeof(char));
    if( s[0] == ')' || s[0] == ']' || s[0] == '}' || length%2!=0) {
        return false;
    } else if (length == 0) {
        return true;
    }
//    ()[]{}
//    "(([]){})"
int count = 0;
    for (i = 0; i < length ;i++) {
        queue[count] = s[i];
        if (queue[count] == ')' || queue[count] == ']' || queue[count] == '}' ) {
            if (queue[count] == ')' && queue[count-1] == '(') {
                queue[count] = queue[count-1] = '\0';
                    count-=2;
            } else if ( queue[count] == ']'  && queue[count-1] == '[' ) {
                queue[count] = queue[count-1] = '\0';
                    count-=2;
            } else if (queue[count] == '}' && queue[count-1] == '{') {
                queue[count] = queue[count-1] = '\0';
                    count-=2;
            } else {
                return false;
            }  
        }
        count++;
    }
    if (queue[0] == '\0') {
        return true;
    } else {
        return false;
    }
    
}
