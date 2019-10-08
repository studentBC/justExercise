class Solution {
public:
	bool bs (vector<int>& arr, int target) {
		int left = 0, right = arr.size()-1, mid;
		while (left<=right) {
			mid = (left+right)/2;
			if (arr[mid] == target) {
				return true;
			} else if (arr[mid] > target) {
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		return false;
	}
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
		vector<int>ans;
 		for (int i :arr1) {
			if (bs(arr2,i) && bs(arr3,i))ans.emplace_back(i);
		}
		return ans;
    }
};
//fatest soltuion
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> results;
        int i = 0, j = 0, k = 0, largest;
        while (i < arr1.size() && j < arr2.size() && k < arr3.size())
        {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
            {
                results.push_back(arr1[i]);
                i++;
                j++;
                k++;
            }
            else
            {
                largest = max(arr1[i], arr2[j]);
                largest = max(largest, arr3[k]);
                while (i < arr1.size() && arr1[i] < largest)
                {
                    i++;
                }
                while (j < arr2.size() && arr2[j] < largest)
                {
                    j++;
                }
                while (k < arr3.size() && arr3[k] < largest)
                    k++;
            }
        }
        return results;
    }
};
