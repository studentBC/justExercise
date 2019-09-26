//concept solution
    vector<string> spellchecker(vector<string>& wordlist, vector<string> queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vowel;
        for (string w : wordlist) {
            string lower = tolow(w), devowel = todev(w);
            cap.insert({lower, w});
            vowel.insert({devowel, w});
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (words.count(queries[i])) continue;
            string lower = tolow(queries[i]), devowel = todev(queries[i]);
            if (cap.count(lower)) {
                queries[i] = cap[lower];
            } else if (vowel.count(devowel)) {
                queries[i] = vowel[devowel];
            } else {
                queries[i] = "";
            }
        }
        return queries;
    }

    string tolow(string w) {
        for (auto & c: w)
            c = tolower(c);
        return w;
    }

    string todev(string w) {
        w = tolow(w);
        for (auto & c: w)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '#';
        return w;
    }
//the fatest solution
class Solution
{
private:
    string toLower(const string& s)
    {
        string result;
        for(int i=0; i<s.length(); i++)
        {
            result.push_back(tolower(s[i]));
        }
        return result;
    }

    string replaceVowels(const string& s)
    {
        string result;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
                result.push_back('#');
            else
                result.push_back(tolower(s[i]));
        }
        return result;
    }
    
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        vector<string> result;
        unordered_set<string> equalMatches;
        unordered_map<string, string> capitalization;
        unordered_map<string, string> vowelErrors;
        for(int i=0; i<wordlist.size(); i++)
        {
            equalMatches.insert(wordlist[i]);
            string lowerCase = toLower(wordlist[i]);
            if(capitalization.find(lowerCase) == capitalization.end())
                capitalization[lowerCase] = wordlist[i];
            string replacedVowels = replaceVowels(wordlist[i]);
            if(vowelErrors.find(replacedVowels) == vowelErrors.end())
                vowelErrors[replacedVowels] = wordlist[i];
        }
        for(int i=0; i<queries.size(); i++)
        {
            if(equalMatches.find(queries[i]) != equalMatches.end())
            {
                result.push_back(queries[i]);
            }
            else if(capitalization.find(toLower(queries[i])) != capitalization.end())
            {
                result.push_back(capitalization[toLower(queries[i])]);
            }
            else if(vowelErrors.find(replaceVowels(queries[i])) != vowelErrors.end())
            {
                result.push_back(vowelErrors[replaceVowels(queries[i])]);
            }
            else
            {
                result.push_back("");
            }
        }
        return result;
    }
};
//my original solution which spend much time on searching and processing the word
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string>ans, alpha, candidate;
        bool match = false, found, capitalization , need;
        for (string s:queries) {
            found = false;
            need = true;
            if (find(wordlist.begin(), wordlist.end(), s) == wordlist.end()) {
                candidate.clear();
                for (int i = 0; i < wordlist.size(); i++) {
                    if (wordlist[i].size() == s.size()) {
                        match = true;
                        capitalization = false;
                        for (int j = 0; j < s.size(); j++) {
                            if (tolower(wordlist[i][j]) == tolower(s[j])) {
                                continue;
                            } else if (tolower(s[j]) == 'a' || tolower(s[j]) == 'e' || tolower(s[j]) == 'i' || tolower(s[j]) == 'o' || tolower(s[j]) == 'u') {
                                if (tolower(wordlist[i][j]) == 'a' || tolower(wordlist[i][j]) == 'e' || tolower(wordlist[i][j]) == 'i' || tolower(wordlist[i][j]) == 'o' || tolower(wordlist[i][j]) == 'u') {
                                    capitalization = true;
                                    continue;
                                } else {
                                    match = false;
                                    break;
                                }
                            } else {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            if (!capitalization) {
                                found = true;need = false;
                                ans.emplace_back(wordlist[i]);
                                break;
                            } else {
                                 //cout << "query " << s << " we may choose " << wordlist[i] << endl;
                                found = true;
                                candidate.emplace_back(wordlist[i]);
                            }
                        }
                    }
                }
            } else {
                found = true;
                capitalization = false;
                need = false;
                ans.emplace_back(s);
            }
            if (!found) {
                ans.emplace_back("");
            } else {
                if (candidate.size() && need)ans.emplace_back(candidate[0]);
            }
        }
        return ans;
    }
};
