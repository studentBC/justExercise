class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        if (x < arr[0]) {
            for (int i = 0; i < k; i++) {
                ans.push_back(arr[i]);
            }
        } else if (x > arr[arr.size()-1]) {
            for (int i = arr.size()-1; i >=arr.size() - k; i--) {
                ans.push_back(arr[i]);
            }
        } else {
            int pos , min = INT_MAX;
            for (int i = 0; i < arr.size(); i++) {
                if (abs(arr[i]-x) <  min) {
                    min = abs(arr[i]-x);
                    pos = i;
                }
            }
            //cout << pos << endl;
            int right = pos+1 , left = pos-1;
            ans.push_back(arr[pos]);
            while (ans.size() < k) {
                if (right < arr.size() && left > -1) {
                    if (abs(arr[right]-x) < abs(x-arr[left])) {
                        ans.push_back(arr[right]);
                        right++;
                    } else if (abs(arr[right]-x) > abs(x-arr[left])) {
                        ans.push_back(arr[left]);
                        left--;
                    } else {
                        ans.push_back(arr[left]);
                        left--;
                    }
                } else if (left > -1 && right >= arr.size()) {
                    ans.push_back(arr[left]);
                    left--;
                } else if (left < 0 && right < arr.size()) {
                    ans.push_back(arr[right]);
                    right++;
                } else {
                    return ans;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0, end = arr.size() - k;
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (x - arr[mid] > arr[mid + k] - x) start = mid + 1;
            else end = mid;
        }
        
        return vector<int>(arr.begin() + start, arr.begin() + start + k);
    }
};
// the fatest solution
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::ios::sync_with_stdio(false); 
        std::cin.tie(nullptr);
        std::deque<int> closest;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            //cout<<i<<endl;
            if (i < k) {
                closest.push_back(arr[i]);
            }
            else {
                if (abs(closest.front() - x) > abs(arr[i] - x)) {
                    closest.pop_front();
                    closest.push_back(arr[i]);
                }
                else if (arr[i] != closest.front()) {
                    break;
                }
            }
        }
        return std::vector<int>({closest.begin(), closest.end()});
    }
};
