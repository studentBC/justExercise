bool isIsomorphic(char* s, char* t) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (s[i] == s[j]) {
				if (t[i]!=t[j]) {
					return false;
				}
			}
			if (t[i] == t[j]) {
				if (s[i]!=s[j]) {
					return false;
				}
			}
		}
	}
	return true;
}
//the fatest method
bool isIsomorphic(char* s, char* t) {
    int n = strlen(s);
    int m1[256] = {0};
    int m2[256] = {0};
    
    for (int i = 0; i < n; ++i) {
        if (m1[s[i]] != m2[t[i]])
            return false;
        
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    
    return true;
}
