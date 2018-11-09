int lengthOfLastWord(char* s) {
	int len = strlen(s);
	int count = 0 , prev = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			if (count != 0)prev = count;
			count = 0;
		} else {
			count++;
		}
	}
	if (s[len -1] == ' ' ) {
		return prev;
	}
	return count;
}
