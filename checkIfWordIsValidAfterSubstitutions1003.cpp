class Solution {
public:
    bool isValid(string S) {
        if (S.size() == 0) return true;
        size_t pos = S.find("abc");
        while (pos != string::npos) {
            S.replace(pos,3,"");
            if (S.size() == 0) return true;
            //cout << S << endl;
            pos = S.find ("abc");
        }
        return false;
    }
};
//20 ms method
class Solution {
public:
    bool isValid(string S) {
        
        stack<char> st;
        for(int i =0 ; i<S.size();i++){
            switch(S[i]){
                case 'a':
                      st.push(S[i]);
                       break;
                case 'b':
                    if(st.empty() || st.top() != 'a') return false;
                    st.push(S[i]);
                    break;
                case 'c':
                    if(st.empty() || st.top() !='b') return false; 
                        st.pop();
                        if(st.empty()||st.top() !='a') return false;
                        st.pop();
        
            }
        }
        return st.empty();
    }
};
