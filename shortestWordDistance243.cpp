/*
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3

Input: word1 = "makes", word2 = "coding"
Output: 1

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

 */
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
		vector<int>pos1, pos2;
		int count = 0, ans = INT_MAX, temp;
		for (string s:words) {
			if (s == word1) pos1.emplace_back(count);
			if (s == word2) pos2.emplace_back(count);
			count++;
		}
		for (int i:pos1) {
			for (int j:pos2) {
				temp = abs(i-j);
				ans = min(temp,ans);
			}
		}
		return ans;
    }
};
//8ms solution
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        //return map_compare_two_array(words, word1, word2); // my first thought, seems fast but not
        return one_pass(words, word1, word2);
    }
    
    int map_compare_two_array(vector<string>& words, string& word1, string& word2) {
        unordered_map<string, vector<int>> map;
        
        for(int i = 0; i < words.size(); i++) {
            map[words[i]].push_back(i);
        }
        
        vector<int> v1 = map[word1];
        vector<int> v2 = map[word2];
        
        return min_dist(v1, v2);
    }
    
    int min_dist(vector<int>& v1, vector<int>& v2) {
        int len1 = v1.size();
        int len2 = v2.size();
        int min = INT_MAX;
        
        for(int i = 0; i < len1; i++) {
            int dist = binary_close(v1[i], v2);
            if(dist < min)
                min = dist;
        }
        return min;
    }
    
    int binary_close(int d, vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        
        while(l < r - 1) {
            int mid = l + (r - l)/2;
            if(d < arr[mid]) {
                r = mid;
            }
            else if(d > arr[mid]) {
                l = mid;
            }
            else
                return 0;
        }
        return min(abs(d - arr[l]), abs(arr[r] - d));
        
    }
    // a b b c d e f b g f              b f
    //   i i       j i   j 
    int one_pass(vector<string>& words, string& word1, string& word2) {
        int len = words.size();
        int i = -1, j = -1;
        int min = INT_MAX;
        
        for(int n = 0; n < len; n++) {
            if(words[n] == word1) {
                i = n;
                if(j >= 0) {
                    int dist = abs(i - j);
                    if(dist < min)
                        min = dist;
                }
            }
            if(words[n] == word2) {
                j = n;
                if(i >= 0) {
                    int dist = abs(i - j);
                    if(dist < min)
                        min = dist;
                }
            }
        }
        return min;
    }
    
    
};
