class Solution {
public:
    class MyObject{
        public:
            map<char,int>priority;
            bool operator() (char a, char b) {
                std::map<char,int>::iterator ita = priority.find(a);
                std::map<char,int>::iterator itb = priority.find(b);
                if (ita!=priority.end() && itb!=priority.end()) {
                    //cout << ita->first <<" : " << ita->second<< endl;
                    return ita->second < itb->second;
                } else if (ita!=priority.end() && itb==priority.end()) {
                    return true;
                }  else {
                    return false;
                }
            }
    };
    map<char,int>priority;
    string customSortString(string S, string T) {
        for (int i = 0; i < S.size(); i++) {
            priority.insert(pair<char,int>(S[i],i));
        }
        MyObject myobject;
        myobject.priority = priority;
        sort(T.begin(),T.end(),myobject);
        return T;
    }
};
//the fatest method
class Solution {
public:
    string customSortString(string S, string T) {
        if (T.size() == 0) {
            return "";
        }
        if (S.size() == 0) {
            return T;
        }
        vector<int> order(26, 0);
        for (char c : T) {
            order[c - 'a']++;
        }
        string res = "";
        for (char c : S) {
            while (order[c - 'a']-- > 0) {
                res += c;
            }
        }
        
        for (char c : T) {
            while (order[c - 'a']-- > 0) {
                res += c;
            }
        }
        return res;
    }
};
