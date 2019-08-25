class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>qf, wf, ans;
        for (string s: queries) {
            vector<int> frequency(26,0);
            for (char c:s) {
                frequency[c-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (frequency[i]) {
                    qf.emplace_back(frequency[i]);
                    break;
                }
            }
        }
        for (string s: words) {
            vector<int> frequency(26,0);
            for (char c:s) {
                frequency[c-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (frequency[i]) {
                    wf.emplace_back(frequency[i]);
                    break;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < qf.size(); i++) {
            count = 0;
            for (int j = 0; j < wf.size(); j++) {
                if (wf[j] > qf[i]) {
                    count++;
                }
            }
            ans.emplace_back(count);
        }
        return ans;
    }
};
//20 ms solution
class Solution {
public:
    
    vector < int > getFreq(vector < string > &A) {
        int n = A.size();
        
        vector < int > freq;
        for(int i = 0;i < n;++i) {
            char mi = 'z' + 3;
            for(int j = 0;j < A[i].size();++j) {
                mi = min(mi, A[i][j]);
            }
            
            int f = 0;
            for(int j = 0;j < A[i].size();++j) {
                if(A[i][j] == mi) {
                    ++f;
                }
            }
            freq.push_back(f);
        }
        return freq;
    }
    
    vector<int> numSmallerByLeadingCount(vector<string>& Q, vector<string>& A) {
        vector < int > freqA = getFreq(A);
        vector < int > freqQ = getFreq(Q);
        
        vector < int > ans;
        sort(freqA.begin(), freqA.end());
        
        for(int i = 0;i < freqQ.size();++i) {
            int x = freqQ[i];
            int lo = 0, hi = freqA.size();
            while(lo + 1 < hi) {
                int mid = lo + (hi - lo)/2;
                if(freqA[mid] > x) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            while(hi > 0 and freqA[hi - 1] > x) {
                --hi;
            }
            ans.push_back(A.size() - hi);
            
        }
        return ans;
    }
};
