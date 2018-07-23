/*
 *s = "leetcode"
	return 0.

	s = "loveleetcode",
	return 2.
 *
 */


int firstUniqChar(char* s) {
	int map[26]={0};
	int i = 0,len = strlen(s);
	for (i = 0; i < len;i++) {
		map[s[i]-'a']++;
	}
	for(i =0; i < len;i++) {
		if(map[s[i]-'a'] == 1){
			return i;
		}
	}
	return -1;
}

//the fatest method
int firstUniqChar(char* s) {
    int* posArr=(int*)calloc(26,sizeof(int));
    int pos=1;
    while(*s!='\0'){
        if(posArr[*s-'a']<0){
            
        }
        else if(posArr[*s-'a']==0){
            posArr[*s-'a']=pos;
        }
        else{
            posArr[*s-'a']=-1;
        }
        pos++;
        s++;
    }
    
    int ret=INT_MAX;
    for(int i=0;i<26;i++){
        if(posArr[i]>0&&posArr[i]<ret){
            ret=posArr[i];
        }
    }
    if(ret==INT_MAX)
        ret=0;
    return ret-1;
}
