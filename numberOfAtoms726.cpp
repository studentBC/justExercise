//https://leetcode.com/problems/number-of-atoms/discuss/109324/Elegant-and-Clean-C%2B%2B-Iterative-Solution-Using-stack-(-via-Reverse-the-Formula)
class Solution {
public:
    string countOfAtoms(string formula) {
        vector<string>line;
        map<string, int>count;
        string atom;
        char prev = '$';
        for (char c : formula) {
            if (isupper(c)) {
                if(atom.size()) {
                    line.push_back(atom);
                    atom = "";
                }
                atom.push_back(c);
            } else if (islower(c)) {
                atom.push_back(c);
            } else if (isdigit(c)) {
                if(!isdigit(prev)) {
                    if (atom.size()) {
                        line.push_back(atom);
                        atom = "";
                    }
                }
                atom.push_back(c);
            } else  {
                if(atom.size()) {
                    //cout <<"atom is " << atom << endl;
                    line.push_back(atom);
                    atom = "";
                }
                //cout <<"atom is " << c << endl;
                atom.push_back(c);
                line.push_back(atom);
                atom = "";
            }
            prev = c;
        }
        if(atom.size()) line.push_back(atom);
        //for (string s : line) cout << s <<", ";
        // cout << endl;
        vector<int>factors;
        factors.push_back(1);
        int factor = 1;
        for (int i = line.size()-1; i > -1; i--) {
            if (line[i][0] == '(') {
                factors.pop_back();
            } else if (isdigit(line[i][0])) {
                factor = stoi(line[i]);
            } else if (line[i][0] == ')') {
                factors.push_back(factor*factors.back());
                factor = 1;
            } else {
                count[line[i]] += factor*factors.back();
                factor = 1;
            }
        }
        string ans;
        for (auto& it: count) {
            //cout << it.first << " : " << it.second << endl;
            ans+=it.first;
            if (it.second > 1) ans+=to_string(it.second);
        }
        return ans;
    }
};
