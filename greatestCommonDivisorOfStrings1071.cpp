class Solution {
public:
    string tmp , temp, st, str;
    string gcdOfStrings(string str1, string str2) {
        int divide;
        for (int i = 0; i < str1.size(); ++i) {
            divide = str1.size()/(i+1);
            temp = str1.substr(0,i+1);
            //cout << "try " << temp << " loop " << divide<< endl;
            str = "";
            for (int j = 0; j < divide; j++) {
                str+=temp;
            }
            //cout << str << endl;
            if (str.compare(str1) == 0) {
                break;
            }
        }
        for (int i = 0; i < str2.size(); ++i) {
            divide = str2.size()/(i+1);
            tmp = str2.substr(0,i+1);
            //cout << "try " << tmp << endl;
            st = "";
            for (int j = 0; j < divide; j++) {
                st+=tmp;
            }
            //cout << st << endl;
            if (st.compare(str2) == 0) {
                break;
            }
        }
        int a = str1.size(), b = str2.size(), times;
        //cout << str << " " << st << endl;
        string ans = "";
        if (tmp.compare(temp) == 0) {
            for(int i=1;i<=a && i<=b;i++){
                if(!(a%i) && !(b%i)) times=i;
            }
            times/=tmp.size();
            for (int i = 0; i < times; i++)ans+=tmp;
            return ans;
        } else {
            return "";
        }
    }
};
//the fatest method
string rem(string dvd,string div){
   if(div!=dvd.substr(0,div.length()))
       return div;

    string r="";
    int l1=dvd.length();
    //int l2=div.length();
    string prev=div;
   // if(prev==dvd.substr(0,))
    while(1>0){
        string s=prev+div;
        if(s.length()>l1|| s!=dvd.substr(0,s.length())){
            r=dvd.substr(prev.length(),dvd.length()-prev.length());
            if(r.length()>=div.length())
                return "";
            return r;
        }
        
        prev=s;
        
    }
}

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
       if(str1.length()<str2.length()){
           auto temp=str1;
           str1=str2;
           str2=temp;
           
       }
        string dvd=str1;
        string div=str2;
        string r="";
       // int 
        while(1>0){
            if(div!=dvd.substr(0,div.length()))
                return "";
            
            
            r=rem(dvd,div);
            if(r=="")
                return div;
            dvd=div;
            div=r;
            
        }
        
        
    }
};
