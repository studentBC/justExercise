class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            vector<double>answer(nums.begin(), nums.end());
            return answer;
        }
        vector<int>window;
        vector<double>ans;
        int end = nums.size()-k;double temp;
        for (int i = 0; i < k; i++) window.emplace_back(nums[i]);
        sort(window.begin(), window.end());
        if (k%2 == 0) {
            temp = (double)window[k/2]+(double)window[k/2-1];
            ans.emplace_back(temp/2);
        } else {
            ans.emplace_back(window[k/2]);
        }
        //cout << end << endl;
        for (int i = 1; i <= end; i++) {
            //cout <<"try to erase:  " << nums[i-1] << endl;
            //for (int k:window) cout << k <<" , ";
            //cout << endl;
            window.erase(find(window.begin(), window.end(), nums[i-1]));
            //cout <<"try to insert:  " << nums[i+k-1] << endl;
            temp = nums[i+k-1];
            if (temp <= window[0]) {
                window.insert(window.begin(), temp);
                //cout <<"front" << endl;
            } else if (temp >= window.back()) {
                //cout << temp <<"  back  " << window.back() << endl;
                window.emplace_back(temp);
            } else {
                //cout <<"here "<<endl;
                for (int j = 1; j < window.size(); j++) {
                    if (temp >= window[j-1] && temp <= window[j]) {
                        //cout <<"find at  " << j << endl;
                        window.insert(window.begin()+j, temp);
                        break;
                    }
                }
            }
            if (k%2 == 0) {
                ans.emplace_back(((double)window[k/2]+(double)window[k/2-1])/2);
            } else {
                ans.emplace_back(window[k/2]);
            }
        }
        return ans;
    }
};
//the fatest solution
static auto _______ = [](){
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        std::vector<double> res;

        if (k == 0) return res;

        std::multiset<int> window(begin(nums), begin(nums) + k);

        // if k is odd, then mid points to the middle element, e.g. 1 in {-1, 1, 3}
        // if k is even, then mid points to the lower middle element, e.g. 2 in {1, 2, 3, 4}
        auto mid = std::next(begin(window), (k - 1) / 2);

        for (auto window_last = begin(nums) + k; window_last != end(nums); ++window_last)
        {
            // (k + 1) % 2 == 0 if k is odd, == 1 if k is even
            res.push_back((static_cast<double>(*mid) + *std::next(mid, (k + 1) % 2)) / 2.0);

            window.insert(*window_last);

            if (*window_last < *mid) --mid;
            if (*(window_last-k) <= *mid) ++mid;
            window.erase(window.lower_bound(*(window_last-k)));
        }

        res.push_back((static_cast<double>(*mid) + *std::next(mid, (k + 1) % 2)) / 2.0);
        return res;
    }
};
