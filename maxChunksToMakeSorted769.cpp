class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>temp;
        int count , ans = 0, index = 0, i = 0;
        bool same;
        while (index < arr.size()) {
            if (arr[index] != i) {
                temp.clear();
                temp.emplace_back(arr[index]);
                for (int j = index+1; j < arr.size(); j++) {
                    temp.emplace_back(arr[j]);
                    sort(temp.begin(), temp.end());
                    same = true; count = i;
                    for (auto& k:temp) {
                        if (count != k) {
                            same = false;
                            break;
                        }
                        ++count;
                    }
                    if (same) {
                        i = j+1;
                        index = j+1;
                        ans++;
                    }
                }

            } else {
                ans++;
                i++;
                index++;
            }
        }
        return ans;
    }
};

