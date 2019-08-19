class Solution {
public:
    int check (string text) {
        int count = 1;
        char prev = '$';
        int ans = 0;
        for (char c: text) {
            if (c!=prev) {
                count = 1;
            } else {
                count++;
            }
            ans = max(ans, count);
            prev = c;
        }
        return ans;
    }
    int maxRepOpt1(string text) {
        int ans = 0;
        string temp; char tmp;
        for (int i = 0; i < text.size(); i++) {
            for (int j = i+1; j < text.size(); j++) {
                temp = text;
                tmp = temp[i];
                temp[i] = temp[j];
                temp[j] = tmp;
                ans = max(ans, check(temp));
            }
        }
        return ans;
    }
};


/*Collect indexes for each character. Then, count the number of consecutive indices cnt, and track the number of previous consecutive indices cnt1.

Note that we set cnt1 to zero if the gap is larger than one.

In the end, we'll get a max count of the repeated characters with no more than one-character gap. If we have more of that character somewhere in the string (idx[n].size() > mx), we add 1 for the swap operation.*/
class Solution {
public:
    int maxRepOpt1(string text) {
        vector<vector<int>>index(26);
        for (int i = 0; i < text.size(); i++) index[text[i]-'a'].emplace_back(i);
        int count = 0, consecutive = 0, longest = 0, ans = 1;
        for (int i = 0; i < 26; i++) {
			count = 1; consecutive = 0; longest = 0;
            for (int j = 1; j < index[i].size(); j++) {
                if (index[i][j] == index[i][j-1]+1) {
                    count++;
                } else {
                    if (index[i][j] == index[i][j-1]+2) {
                        consecutive = count;
                    } else {
                        consecutive = 0;
                    }
                    count = 1;
                }
                longest = max (longest, consecutive+count);
            }
            if (index[i].size() > longest) {
                ans = max (ans, longest+1);
            } else {
                ans = max (ans, longest);
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.length();
        int arr[26]={0};
        int prev_id=0,count=1,ans=1,ans_id=0;
        for(int i=0;i<n;i++)
        {
            int id=text[i]-'a';
            arr[id]++;
        }
        int flag=0;
        for(int i=0;i<n;i++)
        {
            int id=text[i]-'a';
            if(i>0)
            {
                if(prev_id==id)
                    count++;
                else
                {
                    flag=1;
                    int z=i+1,lcount=0;;
                    while(z<n && (text[z]-'a')==prev_id)
                    {
                        lcount++;
                        z++;
                    }
                    int localans=count+lcount;
                    if(ans < localans)
                    {
                        ans = localans;
                        ans_id=prev_id;
                    }
                    count=1;
                }
            }
            
            prev_id=id;
        }
        if(flag==0) ans=count;
        if(ans<arr[ans_id]) ans++;
        return ans;
    }
};
