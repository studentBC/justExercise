class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        size_t pos;
        string path, context, filename;
        unordered_map<string,vector<string>>group;
        vector<vector<string>>ans;
        for (string s:paths) {
            istringstream is(s);
            is >> path;
            while (is >> context) {
                context.pop_back();
                pos = context.find('(');
                group[context.substr(pos+1)].emplace_back(path+"/"+context.substr(0,pos));
            }
        }
        for (auto& it: group) {
            vector<string>temp;
            if (it.second.size() > 1) {
                for (string s: it.second) {
                    temp.emplace_back(s);
                }
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};
//the fatest solution
int f=[]()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        const size_t l=paths.size();
        unordered_map<string,vector<string>> mp;
        for(auto i=0;i<l;++i)
        {
            const string& ith= paths[i];
            const size_t il=ith.length();
            size_t idx=ith.find_first_of(' ',0); // 0,idx is directory_path
            
            size_t fnameidx=ith.find_first_of('(',idx+1); //idx+1 -->fnameidx fileName
            size_t fspace=idx;
            while(fnameidx!=string::npos && fspace!=string::npos)
            {
                size_t contidx=ith.find_first_of(')',fnameidx);
                //string cont;
                //if(contidx!=string::npos)
                string cont=ith.substr(fnameidx+1,contidx-fnameidx-1);
                mp[cont].push_back(ith.substr(0,idx)+"/"+ith.substr(fspace+1,fnameidx-fspace-1));
                //cout<<cont<<" "<<ith.substr(0,idx)+"/"+ith.substr(fspace+1,fnameidx-fspace-1)<<"\n";
                fspace=ith.find_first_of(' ',contidx);
                fnameidx=ith.find_first_of('(',fspace+1);
                
                
            }
        }
        
        vector<vector<string>> res;        
        for(auto& it:mp){
            if(it.second.size()>=2)
                res.push_back(it.second);
        }

        return res;
    }
};
