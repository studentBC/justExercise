/*
 * Design a Phone Directory which supports the following operations:

    get: Provide a number which is not assigned to anyone.
    check: Check if a number is available or not.
    release: Recycle or release a number.

Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);

 */
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        total = maxNumbers;
        picked = new bool[total];
        for (int i = 0; i < total; i++) {
            picked[i] = false;
        }
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for (int i = 0; i < total; i++) {
            if (!picked[i]) {
                picked[i] = true;
                return i;
            }
        }
        return -1;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return !picked[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        picked[number] = false;
    }
private:
    int total;
    bool* picked;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
//the fatest method

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int m) : _max(m), _curr(0){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int num=-1;
        if (_recycled.size()) {
            auto itr = _recycled.begin();
            num = *itr;
            _recycled.erase(itr);
        }
        else if (_curr < _max) {
            num = _curr;
            _curr++;
        }
        return num;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number >= _max) return false;
        if (number >= _curr) return true;
        return _recycled.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number < _curr) _recycled.insert(number);
    }
    private:
    int      _max;
    int      _curr;
    unordered_set<int> _recycled;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */


