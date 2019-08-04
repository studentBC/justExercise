/*
Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
wrong test case:
["StringIterator","next","next","next","next","hasNext","hasNext","next","next","next","next","next","next","next","next","hasNext","next","next","next","next","next","next","hasNext","next","next","next","next","next","next","next","hasNext","next","hasNext","next","next","next","next","next","next","hasNext","next","next","next","next","next","hasNext","next","next","next","hasNext","next","hasNext","hasNext","next","hasNext","next","next","next","next","next","next","hasNext","next","next","next","next","next","next","next","next","next"]
[["X15D18V8"],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]


*/
class StringIterator {
public:
    StringIterator(string compressedString) {
        int count = 0, next, nj;
        for (int i = 0; i < compressedString.size(); ) {
            //cout << compressedString[i] <<" , "<< compressedString[i+1] <<endl;
            for (int j = i+1; j < compressedString.size(); j++) {
                //cout << " start from " <<j << endl;
                if (compressedString[j]-'0' < 10) {
                    count = count*10+(compressedString[j]-'0');
                    //cout <<"enter "<<count <<endl;
                } else {
                    next = j;
                    //cout << endl;
                    break;
                }
                nj = j;
            }
            //cout <<compressedString[i] <<" : "<< count<<endl;
            data.push(pair<char,int>(compressedString[i], count));
            i = next;
            count = 0;
            if (nj+1 == compressedString.size()) return;
        }
    }
    
    char next() {
        char next;
        if (data.empty())return ' ';
        data.front().second--;
        next = data.front().first;
        if (data.front().second == 0)data.pop();
        return next;       
    }
    
    bool hasNext() {
        return !data.empty();
    }
private:
    queue<pair<char,int>>data;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//the fatest method
class StringIterator {
public:
    StringIterator(string compressedString) : data{compressedString}{
    }
    
    char next() {
        if(!hasNext())
            return ' ';
        
        auto c = data[idx];
        if(cnt == 0)
        {
            string num;
            for(next_idx = idx + 1; next_idx < data.size(); ++next_idx)
            {
                if(data[next_idx] < '0' || data[next_idx] > '9')
                    break;
                num += data[next_idx];
            }
                               
            cnt = stoi(num);
        }
        
        if(--cnt <= 0)
            idx = next_idx;
        
        return c;
    }
    
    bool hasNext() {
        return idx < data.size();
    }
    
    string data;
    size_t idx{0U};
    size_t next_idx{0U};
    int cnt{0U};
};
