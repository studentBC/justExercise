class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string para, ans, result;
        /*std::remove_copy_if(paragraph.begin(), paragraph.end(),
            std::back_inserter(result), //Store output
            std::ptr_fun<int, int>(&std::ispunct)
        );*/
        std::replace_if(paragraph.begin() , paragraph.end() , 
            [] (const char& c) { return std::ispunct(c) ;},' ');
        //cout << paragraph << endl;
        vector<string>words;
        paragraph+=" ";
        for (auto&c:paragraph) {
            if (c == ' ') {
                if (result.find(' ') == string::npos && result!=""){
                    //cout << result << " , ";
                    words.emplace_back(result);
                }
                result = "";
            } else {
                c = tolower(c);
                result+=c;
            }
        }
        int most = 0;
        map<string,int>word;
        auto it = word.begin();
        if (banned.size() == 0) {
            while (!words.empty()) {
                para = words.back();
                //cout << para << " , ";
                it = word.find(para); 
                if (it == word.end()) {
                    word.insert(pair<string,int>(para,1));
                } else {
                    it->second++;
                }
                it = word.find(para);
                if (it->second > most) {
                    ans = it->first;
                    most = it->second;
                }
                words.pop_back();
            }
            return ans;

        }
        bool found;
        for (auto&i:words) {
            found = false;
            for (auto& x:banned) {
                if (i.find(x) != string::npos) {
                    //cout << i<<" is banned" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                //cout << i << endl;
                it = word.find(i);
                if (it == word.end()) {
                    word.insert(pair<string,int>(i,1));
                } else {
                    it->second++;
                }
                it = word.find(i);
                if (it->second > most) {
                    ans = it->first;
                    most = it->second;
                }
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int start=0;
        int n=paragraph.size();
        unordered_map<string,int> map1;
        for(int i=0;i<=n;i++){
            if(!isalpha(paragraph[i])){
                string temp=paragraph.substr(start,i-start);
                map1[temp]++;
                while(i<n&&!isalpha(paragraph[i]))
                    i++;
                start=i;
            }
            paragraph[i]=tolower(paragraph[i]);
        }
        for(auto x:banned)
            map1[x]=0;
        int count=0;
        string ans;
        for(auto x: map1){
            if(x.second>count){
                count=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};
