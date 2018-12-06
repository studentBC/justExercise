class Solution {
public:
    int getCount(string s, int start, int end, int k) {
        int map[26]={0};
        int count = 0, index;
        for (int i = start; i < end; i++) {
            map[s[i]-'a']++;
        }
        for (int j = start; j < end; j++) {
            index = s[j]-'a';
            if (map[index]>=k) {
                count+=map[index];
                map[index] = -1;
            } else if ( map[index]<k && map[index]>-1) {
                return 0;
            }
        }
        return count;
    }
    int longestSubstring(string s, int k) {
        if (k > s.length())return 0;
        int max = 0 , count, end = s.length()-k;
        for (int i = 0; i <= end; i++) {
            for (int j = i+k; j <= s.length(); j++) {
                count = getCount(s, i , j, k);
                if (max < count)max = count;
                //cout << max << endl;
            }
        }
        return max;
    }
};
//fatest method
class Solution {
public:
    int longestSubstring(string s, int k) {
         return longestSubstringHelper(s, k, 0, s.size());
    }
    
    int longestSubstringHelper(const string& s, int k, int start, int end) {
        vector<int> freq(26);
        for(int i = start; i < end; i++){
            freq[s[i]-'a']++;
        }
        int max_len = 0;
        for(int i = start; i <end;){
            while(i < end && freq[s[i]-'a'] < k){
                i++;
            }
            if (i == end) {
                break;
            }
            int j = i;
            while(j < end && freq[s[j]-'a'] >= k){
                j++;
            }
            if (i == start && j == end) {
                return end - start; 
            }
            max_len = max(max_len, longestSubstringHelper(s, k, i, j));
            i = j;
        }
        return max_len;
        
    }
};
