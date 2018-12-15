class Solution {
public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            number.push_back(nums[i]);
            init.push_back(nums[i]);
        }
        return;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return init;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::shuffle(number.begin(), number.end(), randomizer);
        return number;
    }
private:
    vector<int>number;
    vector<int>init;
    default_random_engine randomizer = default_random_engine(time(nullptr));
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */


//the fatest method
class Solution {
  public:
    Solution(vector<int> nums) {
      srand(time(nullptr));
      v1.assign(nums.begin(), nums.end());
      v2.assign(nums.begin(), nums.end());
    }

    vector<int> reset() {
      v1.assign(v2.begin(), v2.end());
      return v1;
    }

    vector<int> shuffle() {
      int size = v1.size();
      for(int i=0; i < size; ++i) {
        int k = rand()%(size-i)+i;
        swap(v1[i], v1[k]);
      }
      return v1;
    }

  private:
    vector<int> v1;
    vector<int> v2;
};
