class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
 		map<string,int>words;
		string temp;
		auto it = words.begin();
		int found;
		vector<string>ans;
		A+=" ";B+=" ";
		while (A.find(" ") != string::npos) {
        	found = A.find(" ");
        	temp = A.substr(0, found);
			//cout << temp << endl;
			it = words.find (temp);
			if (it == words.end()) {
				words.insert(pair<string,int>(temp,1));
			} else {
				it->second++;
			}
        	A = A.substr(found + 1);
    	}
		while (B.find(" ") != string::npos) {
        	found = B.find(" ");
        	temp = B.substr(0, found);
			//cout << temp << endl;
			it = words.find (temp);
			if (it == words.end()) {
				words.insert(pair<string,int>(temp,1));
			} else {
				it->second++;
			}
        	B = B.substr(found + 1);
    	}
		for (it = words.begin(); it!= words.end(); it++) {
			if (it->second == 1) {
				ans.push_back (it->first);
			}
		}
		return ans;
    }
};
