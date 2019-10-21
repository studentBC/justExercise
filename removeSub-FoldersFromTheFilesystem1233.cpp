class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector < string > ans;
        sort(folder.begin(), folder.end());
        int n = folder.size();
        string cur = folder[0];
        for(int i = 1;i < n;++i) {
            if(folder[i].find(cur) != string::npos && folder[i][cur.size()] == '/') {
                continue;
            }

            cur = folder[i];
            ans.push_back(cur);
            
        }
        ans.push_back(folder[0]);
        return ans;
    }
};

/*
Observation

Strings with subfolders will always be of larger length than the ones that include their parents.
When parents are stored as sorted, if a string has a parent in the sorted list, binary searching that string in that list will result in getting an iterator next to its parent. (We dont actually need this since when the input is sorted all we need to do is look at the last found parent which will be the only viable candidate to be a parent - refer to solution 2)
Since the question states that the folders are unique, we don't need to check the iterator that the binary search returns.
We se these observations to form the solution.
Solution

Sort the folders by length.
Check if the parent folder exists in the set using the above observation, if not add it to result and the sorted set of parents.
*/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(),folder.end());
        vector<string>::iterator it;
        vector<string> result;
        for(string &s:folder)
        {
            it=lower_bound(result.begin(),result.end(),s);         //Binary search to find the string s.
            if(it!=result.begin())  //Using the observation that the parent would be an iterator before the returned iterator when searched for string with child.
                --it;
            if(result.empty()||it->compare(0,it->length(),s,0,it->length())!=0||s[it->length()]!='/')     //Check if 1. This is the first string, 2. String at iterator is not the parent of `s` by comparing.
                result.push_back(s);                                                     //3. If the entire parent matches `s` check if last folder name in parent does not match the folder of same depth in `s`. for cases like `/a/b, /a/bc`.
        }
        return result;
    }
};
/*
On a further look, we don't actually need to binary search, rather we can just use the previous found parent and since the array is already sorted we just need to check the string with the last found parent. (Although this doesn't improve on complexity)
*/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(),folder.end());
        vector<string> result;
        for(string &s:folder)
            if(result.empty()||result.back().compare(0,result.back().length(),s,0,result.back().length())!=0||s[result.back().length()]!='/') //Check if 1. This is the first string, 2.parent at back is not the parent of `s` by comparing.
                result.push_back(s);                                   //3. If the entire parent matches `s` check if last folder name in parent does not match the folder of same depth in `s`. for cases like `/a/b, /a/bc`.
        return result;
    }
};
/*
Complexity
Space: O(1). Although I would say using output vector for calculations in not space saving.
Time: O(nlogn) (considering the size of input) else O(avg(s.length())*nlogn) where s are the strings in folder.
*/
