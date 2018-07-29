
bool isAnagram(char* s, char* t) {
	int lens = strlen(s);
	int lent = strlen(t);
	int i ,j;
	bool found = false;
	if(lens == lent) {
		for (i = 0; i <lens; i++) {
			found = false;
			for (j = 0; j < lens; j++) {
				if (s[i] == t[j]) {
					t[j] = '5';
					found = true;
					break;
				}
			}
			if(!found) {
				return false;
			}
		}
		return true;
	} else {
		return false;
	}
}
int main() {
	char a,b;
	scanf("%c",a);
	scanf("%c",b);
	if( isAnagram(a,b) ) {
		printf(" yes it isAnagram   \n");
	} else {
		printf(" no it isAnagram   \n");
	}
	return 0;
}
//the fatest method turn the char to ascii if they have count twice 
//that value is 0
bool isAnagram(char* s, char* t) {
    int array[26];
    int i;
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t)
        return (false);
    for (i = 0; i < 26; i++) {
        array[i] = 0;
    }

    for (i = 0; i < len_s; i++) {
        array[s[i]-'a']++;
        array[t[i]-'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (array[i] != 0)
            return (false);
    }

    return (true);
}

