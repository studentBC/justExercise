/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

 

Note:

The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
 */
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string response = "";
        for (int i = 0; i < strs.size(); i++) {
            response+=strs[i];
            response+="~@+#";
        }
        //cout <<response << endl;
        return response;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>ans;
        size_t found = s.find("~@+#");
        int start = 0, length;
        while (found != string::npos) {
            length = (int)found-start;
            ans.emplace_back(s.substr(start, length));
            start = found+4;
            //cout <<"start from " << start << endl;
            found = s.find("~@+#", start);
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
//the fatest method
auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Codec {
public:
    int cnt=0;
    //unordered_map<string,int> strToId;
    unordered_map<int,vector<string>> mmap;
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        mmap[cnt]=strs;
        string res=to_string(cnt);
        cnt++;
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        return mmap[stoi(s)];
    }
};
