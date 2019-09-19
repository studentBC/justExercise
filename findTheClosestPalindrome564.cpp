class Solution {
public:
    string nearestPalindromic(string n) {
        if (n.size() == 1) {
            if (n == "0") {
                return "1";
            } else {
                int a = n[0]-'1';
                stringstream ss;
                ss << a;
                return ss.str();
            }
        }
        int mid = n.size()>>1;
        //find special case
        bool match = true;
        if (n[0] == '1') { //1000
            for (int i = 1; i < n.size(); i++) {
                if (n[i] != '0') {
                    match = false;
                    break;
                }
            }
            if (match) {
                string ans;
                for (int i = 1; i < n.size(); i++) ans.push_back('9');
                return ans;
            }
            if (n.back() == '1') {
                match = true;
                for (int i = n.size()-2; i > 0; i--) {
                    if (n[i]!='0') {
                        match = false;
                        break;
                    }  
                }  
                if (match) {
                    string ans;
                    for (int i = n.size()-1; i > 0; i--) ans.push_back('9');
                    return ans;
                }  
            }

        } else if (n[0] == '9') {
            for (int i = 1; i < n.size(); i++) {
                if (n[i] != '9') {
                    match = false;
                    break;
                }
            }
            if (match) {
                string ans;
                ans.push_back('1');
                for (int i = 1; i < n.size(); i++) ans.push_back('0');
                ans.push_back('1');
                return ans;
            }
            if (n.size()%2) {
                match = true;
                for (int i = 1; i < mid; i++) {
                    if (n[i] != '9') {
                        match = false;
                        break;
                    }
                }
                for (int i = mid+1; i < n.size(); i++) {
                    if (n[i] != '0') {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    string ans;
                    for (int i = 0; i < mid; i++) ans.push_back('9');
                    ans.push_back((n[mid]-'0'-1)+'0');
                    for (int i = mid+1; i < n.size(); i++) ans.push_back('9');
                    return ans;
                }
            }
        }
        string target = n;
        for (int i = n.size()-1, j = 0; i > mid; i--,j++) {
            if (n[i]!=n[j]) {
                target[i] = n[j];
            }
        }
        char a, b, c, d, e, f;
        //cout << mid << endl;
        if (n.size()%2 == 0) {
            a = target[mid]-'0'-1+'0';
            string A = target;
            A[mid] = A[mid-1] = a;
            b = target[mid-1]-'0'-1+'0';
            string B = target;
            B[mid] = B[mid-1] = b; 
            //cout << A <<" , " << B << endl;
            c = target[mid]-'0'+1+'0';
            string C = target;
            C[mid] = C[mid-1] = c;
            d = target[mid-1]-'0'+1+'0';
            string D = target;
            D[mid] = D[mid-1] = d;
            e = target[mid];
            string E = target;
            E[mid] = E[mid-1] = e;
            f = target[mid-1];
            string F = target;
            F[mid] = F[mid-1] = f;
            vector<string>target{A,B,C,D,E,F};
            vector<long long>value;
            long long choose = LLONG_MAX;
            int index; 
            for (int i = 0; i < 6; i++) {
                if (abs(stoll(target[i])-stoll(n)) && choose > abs(stoll(target[i])-stoll(n)) ) {
                    choose = abs(stoll(target[i])-stoll(n));
                    index = i;
                } else if (choose == abs(stoll(target[i])-stoll(n)) && stoll(target[i]) < stoll(target[index])) {
                    index = i;
                }
            }   
            return target[index];
        } else {
            a = target[mid]-'0'-1+'0';
            string A = target;
            A[mid] = a;
            b = target[mid]-'0'+1+'0';
            string B = target;
            B[mid] = b;
            vector<string>tt{A,B};
            if (target != n) tt.emplace_back(target);
            long long choose = LLONG_MAX;
            int index; 
            for (int i = 0; i < tt.size(); i++) {
                if (choose > abs(stoll(tt[i])-stoll(n))) {
                    choose = abs(stoll(tt[i])-stoll(n));
                    index = i;
                }
            }   
            return tt[index];
        }
        /*long long temp = stoll(n);
        long long diff = abs(stoll(n)-stoll(target));
        string tmp;
        if (target == n) {
            
        } else {
            
        }*/
        return target;

    }
};
/*the fatest solution
Let's build a list of candidate answers for which the final answer must be one of those candidates. Afterwards, choosing from these candidates is straightforward.

If the final answer has the same number of digits as the input string S, then the answer must be the middle digits + (-1, 0, or 1) flipped into a palindrome. For example, 23456 had middle part 234, and 233, 234, 235 flipped into a palindrome yields 23332, 23432, 23532. Given that we know the number of digits, the prefix 235 (for example) uniquely determines the corresponding palindrome 23532, so all palindromes with larger prefix like 23732 are strictly farther away from S than 23532 >= S.

If the final answer has a different number of digits, it must be of the form 999....999 or 1000...0001, as any palindrome smaller than 99....99 or bigger than 100....001 will be farther away from S.
*/
class Solution {
public:
    string nearestPalindromic(string n) {
        // assume n has no leading zeros
        int len = n.length(), len0 = len / 2 + (len & 1);

        // construct first half 
        long long ori = stoll(n);
        long long left = stoll(n.substr(0, len0));

        long long ans = -1;
        for(long long i=left-1; i<=left+1; i++){
            long long pal = stoll(make_pal(to_string(i), len-len0));
            if(pal!=ori && abs(pal-ori)<abs(ans-ori))
                ans = pal;
        }

        return to_string(ans);
    }

private:
    string make_pal(string left, int len1){
        if(left == "0") return len1 ? "9" : "0";
        if(left.length() < len1) left += "9", len1--;
        return left + string(left.rend() - len1, left.rend());
    }
};
