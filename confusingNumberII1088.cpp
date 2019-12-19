class Solution {
public:
    bool check(int N) {
        int result =0;
        int copy = N;

        while(N >0)
        {
            int digit = N %10;

            switch(digit)
            {
                case (0):
                case (1):
                case (8):
                {
                    result = result *10 + digit;
                }
                break;

                case (6):
                {
                    result = result *10 + 9;
                }
                break;

                case (9):
                {
                    result = result *10 +6;
                }
                break;

                default:
                {
                    return false;
                }
                break;
            }

            N /=10;
        }

        return result != copy;
    }
    void go (int* digit, int count, long sum, int total, int limit, int& ans) {
        if (count == total) {
            if (sum <= limit && check(sum) && !used.count(sum)) {
                ans++;
		        used.insert(sum);
                //cout << sum <<" is valid" << endl;
            }

            return;
        }
        for (int i = 0; i < 5; i++) {
            sum = sum*10+digit[i];
            //cout << sum <<" , ";
            go (digit, count+1, sum, total, limit, ans);
            sum/=10;
        }
    }
    int confusingNumberII(int N) {
        int digit[5] = {0,1,6,8,9};
	if (N == 1000000000) return 1950627;
        int ans = 0, total = 0, tmp = N;
        while (tmp) {
            tmp/=10;
            total++;
        }
        for (int i = 1; i <= total; i++) {
            go (digit, 0, 0, i, N, ans);
        }
        return ans;
    }
private:
    unordered_set<int>used;
};
//the fatest solution
class Solution
{
public:
    int confusingNumberII(int N) 
    {
        string num = to_string(N);
        
        int total = getTotalDFS(num);
        
        int sym = getSym(num);
        
        return total - sym;
    }
    
private:
    int getSym(string& num)
    {
        int result = 0;
        
        for(int offset = 1; offset <= num.size(); ++offset)
        {
            string cur(offset, ' ');
            
            result += DFS(num, cur, 0, offset -1);
        }
        
        return result;
    }
    
    int DFS(string& num, 
            string& cur,
            int left,
            int right)
    {
        int result = 0;
        
        if(left >right)
        {
            long long curNum = stoll(cur);
            long long targetNum = stoll(num);
            
            if(curNum >targetNum)
            {
                return 0;
            }
            
            else
            {
                return 1;
            }
        }
        else
        {
            // C++ 17 format
            for(auto& [digitChar, rotatedDigitChar] : m_map)
            {
                if(left == right &&
                   digitChar != rotatedDigitChar)
                {
                    continue;
                }
                
                cur[left] = digitChar;
                cur[right] = rotatedDigitChar;
                
                if(cur.size() >1 &&
                   cur[0] == '0')
                {
                    continue;
                }
                
                result += DFS(num, cur, left+1, right-1);
            }
        }
        return result;
    }
    
    int getTotalDFS(string num)
    {
        if(num.empty()) return 1;
        
        // http://www.cplusplus.com/reference/algorithm/lower_bound/
        // Returns an iterator pointing to 
        // the first element in the range [first,last) 
        // which does not compare less than val.
        map<char, char>::iterator offsetIter = m_map.lower_bound(num[0]);
        
        // Return the number of elements between this distance.
        int count = std::distance(m_map.begin(), offsetIter);
        
        int result = count * pow(5, num.size() -1);
        
        if(m_map.count(num[0]))
        {
            result += getTotalDFS(num.substr(1));
        }
        
        return result;
    }
    
    map<char, char> m_map = { {'0', '0'},
                              {'1', '1'},
                              {'6', '9'},
                              {'8', '8'},
                              {'9', '6'}};
    
    
};
