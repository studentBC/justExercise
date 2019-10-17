class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        
        while(n) {
			n--;
            result += n%26+'A';
            n = n/26;
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};
