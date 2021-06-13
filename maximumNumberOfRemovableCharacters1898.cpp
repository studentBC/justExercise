class Solution {
public:
    //int m, n;
    bool isSubSequence(string& str1, string& str2, int m, int n)
    {

        // Base Cases
        if (m == 0)
            return true;
        if (n == 0)
            return false;

        // If last characters of two
        // strings are matching
        if (str1[m - 1] == str2[n - 1])
            return isSubSequence(str1, str2, m - 1, n - 1);

        // If last characters are
        // not matching
        return isSubSequence(str1, str2, m, n - 1);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {

        //else if (s.size() > 47000) return 0;
        //target = p;
        int i;
        bool found;
        int m = p.size(), n = s.size(), left = 0, right = removable.size(), mid;
        string temp;
        while (left <= right) {
            mid = (left+right)/2;
            temp = s;
            for (int i = 0; i < mid; i++) {
                temp[removable[i]] = '$';
            }
            if (!isSubSequence(p, temp, m, n)) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        //cout << mid <<" , " << right <<" , " << left << endl;
        return right;
    }
};
//the 116 ms solution
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int i = 1, t = removable.size();
        if(isSubsequence(s, p, removable, t)){
            return t;
        }
        while(t <= removable.size()){
            if(!isSubsequence(s, p, removable, i)){
                return i - 1;
            }
            i++;
        }
        return i - 1;
    }
private:
    bool isSubsequence(const string& s, const string& p, const vector<int>& removable, int k){
        int n = s.size(), m = p.size();
        vector<bool> shouldRemove(n, false);
        for(int i = 0; i < k; i++){
            shouldRemove[removable[i]] = true;
        }
        int i = 0, j = 0;
        while(i < n && j < m){
            if(shouldRemove[i]){
                i++;
                continue;
            }
            if(s[i] == p[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j == m;
    }
};
