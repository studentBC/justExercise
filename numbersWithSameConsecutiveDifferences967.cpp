class Solution {
public:
    int VectorToInt(vector<int> v) {
        int total = 0;
        int end = v.size()-1;
        for (int i = 0; i < end; i++)
        {
            total += v[i];
            total *= 10;
        }
        return total+v[end];
    }
    void go (int num, int N, int K, vector<int>& temp, set<int>& ans) {
        if (N == temp.size()) {
            ans.insert(VectorToInt(temp));
        } else {
            int diff = num+K;
            if (diff < 10) {
                temp.emplace_back(num);
                go (diff, N, K, temp, ans);
                temp.pop_back();
            }
            diff = num-K;
            if (diff  >= 0) {
                temp.emplace_back(num);
                go (diff, N, K,temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) {
            vector<int>imediate{0,1,2,3,4,5,6,7,8,9};
            return imediate;
        }
        vector<int>temp;
        set<int>ans;
        //if (N == 1 && K == 0) ans.emplace_back (0);
        //int diff;
        for (int i = 1; i < 10; i++) {
            go (i,N,K,temp,ans);
        }
        vector<int>answer(ans.begin(),ans.end());
        
        return answer;
    }
};
//the fatest method
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        
        vector<int> org,tmp;
        if(N==1){for(int i=0;i<=9;i++)org.push_back(i);}
        else{
        for(int i=1;i<=9;i++)org.push_back(i);
        for(int l=1;l<N;l++){
            for(int i=0;i<org.size();i++)
        {
            int rem=org[i]%10;
            if(K==0){if(rem+K>=0 && rem+K<=9)tmp.push_back(org[i]*10+(rem+K));}
            else {if(rem-K>=0 && rem-K<=9)tmp.push_back(org[i]*10+(rem-K));
                  if(rem+K>=0 && rem+K<=9)tmp.push_back(org[i]*10+(rem+K));}
        }
            org=tmp; tmp.clear();
            
        }
        }
        return org;
    }
};
