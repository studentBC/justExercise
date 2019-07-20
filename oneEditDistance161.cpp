/*
Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

wrong test case:
""
""

"ab"
"ba"
*/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        string temp = t;
        if (s == t) return false;
        int count = 0, start = 0;
        bool found;
        for (int i = 0; i < s.size(); i++) {
            found = false;
            for (int j = start; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    found = true;
                    t[j] = '$';
                    start = j+1;
                    break;
                }
            }
            if (!found)count++;
        }
        if (s.size() > t.size()) {
            return count == 1;
        } else if (s.size() == t.size()) {
            count = 0;
            for (int j = 0; j < t.size(); j++) {
                if (s[j] != temp[j]) {
                    count++;
                }
            }
            return count == 1;
        } else {
            cout << "here " << endl;
            if (t.size() - s.size() == 1 && count == 0) {
                return true;
            }
            return false;
        }
    }
};
//the fatest method
class Solution{
public:
  bool isOneEditDistance(string s, string t)
  {
    if (s == t) return false;
    
    if (s.size() == t.size() - 1)
      {
	for (int a = 0; a < s.size(); ++a)
	  {
	    if (s[a] != t[a])
	      {
		for (int b = a + 1; b < t.size(); ++b, ++a)
		  {
		    if (s[a] != t[b]) return false;
		  }
		return true;		
	      }
	  }

	return true;
      }
    else if (s.size() == t.size() + 1)
      {
	for (int a = 0; a < t.size(); ++a)
	  {
	    if (s[a] != t[a])
	      {
		for (int b = a + 1; b < s.size(); ++b, ++a)
                  {
                    if (s[b] != t[a]) return false;
                  }
                return true;
	      }
	  }

	return true;
      }
    else if (s.size() == t.size())
      {
	int num = 0;
	for (int a = 0; a < t.size(); ++a)
	  {
	    if (s[a] != t[a])
	      {
		++num;
		if (num >= 2) return false;
	      }
	  }

	return true;
      }

    return false;
  }
};
