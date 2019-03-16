class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        target = k;
        if (!nums.empty() ) {
            sort(nums.begin(), nums.end());
            temp = nums;

            /*for (int i = 0; i < temp.size(); i++) {
                cout << temp[i] <<" , ";
            }
            cout << endl;*/
        }
        return;
    }
    
    int add(int val) {
        int count = 0, prev = INT_MAX;
        if (temp.empty() || val >= temp.back()) {
            temp.push_back(val);
        } else if (val <= temp[0]) {
            temp.insert(temp.begin(), val);
        } else {
            for (int i = 0; i < temp.size(); i++) {
                if (i+1 < temp.size() && val >= temp[i] && val <= temp[i+1]) {
                    temp.insert(temp.begin()+i+1,val);
                    break;
                } 
            }
        }
        /*for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] <<" , ";
        }
        cout << endl;*/
        
        return temp[temp.size()-target];
    }
private:
    vector<int>temp;
    int target;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
//the fatest method
class KthLargest {
public:
    KthLargest(int k, vector<int> nums)
        : kk{k}, data{begin(nums),
                      begin(nums) + std::min(static_cast<int>(nums.size()), k)}
    {
        // if there are more than k elements in nums,
        // see if they are greater than the first k elements
        // and if they are, modify the heap accordingly
        for (auto i = k; i < nums.size(); ++i)
        {
            insert_if_greater(nums[i]);
        }
    }

    int add(int val)
    {
        if (data.size() >= kk)
            insert_if_greater(val);
        else
            data.push(val);

        return data.top();
    }
private:
    int kk;
    // heap that contains the k largest elements of the input stream
    std::priority_queue<int, std::vector<int>, std::greater<>> data;

    void insert_if_greater(int val)
    {
        if (val > data.top())
        {
            data.pop();
            data.push(val);
        }
    }
};
