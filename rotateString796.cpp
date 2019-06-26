class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() == 0 && B.size() == 0) return true;
        char front;
        for (int i = 0; i < A.size(); i++) {
            front = A.front();
            A.erase(A.begin());
            A.push_back(front);
            if (A == B) return true;
        }
        return false;
    }
};
//the fatest method
class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};
