class MapSum {
private:
    map<string,int>words;
    std::map<string,int>::iterator it;
public:
    /** Initialize your data structure here. */
    MapSum() {
        words.clear();
        it = words.begin();
        return;
    }
    
    void insert(string key, int val) {
        it = words.find(key);
        if (it  == words.end() ) {
            words.insert(pair<string,int>(key,val));
        } else {
            it->second = val;
        }
        return;
    }
    
    int sum(string prefix) {
        int end , sum = 0;
        bool match = true;
        string temp;
        for (it = words.begin();it!=words.end();++it) {
            temp = it->first;
            //end = (prefix.length() < temp.length()) ? prefix.length() : temp.length();
            if ( temp.length() >= prefix.length() ) {
                match = true;
                for (int i = 0; i < prefix.length(); i++) {
                    if (prefix[i] != temp[i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    sum+=(it->second);
                }
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
