/*
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        num.clear();
    }
   
    /** Add the number to an internal data structure.. */
    void add(int number) {
        num.insert(number);
        if (nums.find(number) == nums.end()) {
            nums[number] = 1;
        } else {
            nums[number]++;
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        //if (num.size() < 2) return false;
        int temp;
        for (int i : num) {
            temp = i*2;
            if (temp == value && nums[i] > 1) {
                return true;
            } else if (temp != value && nums[value-i]) {
                //cout << "find " << value <<" , " << i << endl;
                return true;
            }
        }
        return false;
    }
private:
    unordered_set<int>num;
    unordered_map<int,int>nums;
};
//40 ms solution
class TwoSum {
public:
	/** Initialize your data structure here. */
	TwoSum() {
	}

	/** Add the number to an internal data structure.. */
	void add(int number) {
		insert(number);
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int target) {
		return hasTwoSum(target);
	}

private:

   	unordered_map<int, int> nums;
	int count = 0;
	int dmin = INT_MAX;
	int dmax = INT_MIN;

	inline void insert(int number) {
		nums[number] ++;
		count++;
		dmin = min(dmin, number);
		dmax = max(dmax, number);
	}

	bool hasTwoSum(int target) const {
		if (count < 2 || target < (dmin * 2) || target >(dmax * 2))
			return false;

		if (target % 2 == 0 && nums.find(target / 2) != nums.end()) {
			if (nums.at(target / 2) > 1)
				return true;
		}

		for (auto elem : nums) {
			if (elem.first * 2 == target)
				continue;

			if (nums.find(target - elem.first) != nums.end())
				return true;
		}

		return false;
	}

};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
//the concept solution
public class TwoSum {
        Set<Integer> sum;
        Set<Integer> num;
        
        TwoSum(){
            sum = new HashSet<Integer>();
            num = new HashSet<Integer>();
        }
        // Add the number to an internal data structure.
    	public void add(int number) {
    	    if(num.contains(number)){
    	        sum.add(number * 2);
    	    }else{
    	        Iterator<Integer> iter = num.iterator();
    	        while(iter.hasNext()){
    	            sum.add(iter.next() + number);
    	        }
    	        num.add(number);
    	    }
    	}
    
        // Find if there exists any pair of numbers which sum is equal to the value.
    	public boolean find(int value) {
    	    return sum.contains(value);
    	}
    }
