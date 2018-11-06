int numJewelsInStones(char* J, char* S) {
	int jlen = strlen(J);
	int slen = strlen(S);
	int count = 0;
	for (int i = 0; i < jlen; i++) {
		for (int j = 0; j < slen; j++) {
			if (J[i] == S[j]) {
				count++;
			}
		}
	}
	return count;
}
