class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
 		unordered_map<int,int>count;
		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				if (count.find(mat[i][j]) == count.end()) {
					count[mat[i][j]] = 1;
				} else {
					count[mat[i][j]]++;
					if (count[mat[i][j]] == mat.size()) {
						return mat[i][j];
					}
				}
			}
		}
		return -1;
    }
};
//the 24 ms solution
class Solution {
public:
    bool binary_search(vector<int>& vec, int target)    {
        int l = 0;
        int r = vec.size() - 1;
        
        while(l <= r)    {
            int mid = (r + l) / 2;
            
            if(vec[mid] == target)  {
                return true;
            }
            else if(vec[mid] > target)  {
                r = mid - 1;
            }
            else    {
                l = mid + 1;
            }
        }
        
        return false;
    }
    
    int smallestCommonElement(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        
        if(!mat.size()) {
            return -1;
        }
        
        if(!mat[0].size())  {
            return -1;
        }
        
        for(int i = 0; i < mat[0].size(); ++i)  {
            bool found = true;
            for(int j = 1; j < mat.size(); ++j) {
                if(!binary_search(mat[j], mat[0][i]))   {
                    found = false;
                    break;
                }
            }
            
            if(found)   {
                return mat[0][i];
            }
        }
            
        return -1;
    }
};
