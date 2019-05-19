class Solution {
public:
    static bool compare(string a, string b) {
        return a.size() < b.size();
    }
    string replaceWords(vector<string>& dict, string sentence) {
        istringstream data(sentence);
        sort(dict.begin(), dict.end(), compare);
        string ans,temp;
        bool found;
        std::size_t pos;
        while (data>>temp) {
            found = false;
            for (int i = 0; i < dict.size(); i++) {
                pos = temp.find(dict[i]);
                if (pos == 0 && dict[i][0] == temp[0]) {
                    //cout << pos <<" , ";
                    ans+=dict[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans+=temp;
            }
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};
//the fatest method
int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class TrieNode {
public:
	TrieNode *children[27] = { nullptr };
};

class Solution {
public:
	string replaceWords(vector<string> &dict, string sentence) {
		TrieNode *root = new TrieNode, *node = root;
		for (const string &prefix : dict) {
			for (char l : prefix) {
				if (node->children[l - 'a'] == nullptr)
					node->children[l - 'a'] = new TrieNode;
				node = node->children[l - 'a'];
			}
			node->children[26] = root;
			node = root;
		}
		string output;
		string::const_iterator b = sentence.cbegin(), e = b;
		while (e != sentence.cend()) {
			if (*e == ' ')
				b = ++e;
			bool flag = false;
			while (e != sentence.cend() && *e != ' ') {
				if (node->children[26]) {
					flag = true;
					break;
				} else if (node->children[*e - 'a'] == nullptr)
					break;
				node = node->children[*e++ - 'a'];
			}
			if (flag) {
				output += string(b, e);
				e = find(e, sentence.cend(), ' ');
			} else {
				e = find(e, sentence.cend(), ' ');
				output += string(b, e);
			}
			node = root;
			output += ' ';
		}
		return string(output.cbegin(), output.cend() - 1);
	}
};
