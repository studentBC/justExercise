class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        string number , subdomain, seperated;
        map<string,int>domain;
        auto it = domain.begin();
        vector<string>ans;
        vector<string>temp;
        for (auto&i:cpdomains) { 
            //cout << i << endl;
            istringstream datas(i); 
            datas >> number;
            datas >> subdomain;
            //cout << number << "  " << subdomain << endl;
            stringstream ss(subdomain);
            temp.clear();
            while (getline(ss, seperated, '.')) {
                //cout << seperated << " , " ;
                temp.emplace_back(seperated);
                if (ss.peek() == '.') ss.ignore();
            }
            for (int i = 0; i < temp.size(); i++) {
                seperated = "";
                for (int j = i; j < temp.size(); j++) {
                    seperated+=temp[j];
                    if (j!=temp.size()-1) seperated+=".";
                }
                //cout  << seperated << " , ";
                it = domain.find(seperated);
                if ( it != domain.end() ) {
                    it->second+=stoi(number);
                } else {
                    domain.insert(pair<string,int>(seperated, stoi(number)));
                }
            }
            //domain.insert(pair<string,int>(subdomain, stoi(number)));
        }
        for (it = domain.begin(); it!= domain.end(); it++) {
            seperated = "";
            seperated+=to_string(it->second);
            seperated+=" ";
            seperated+=it->first;
            ans.emplace_back (seperated);
        }
        return ans;
    }
};
//the fatest method
static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> res;
        
        for (auto& domain : cpdomains) {
            auto end = domain.find(' ');
            int count = std::stoi(domain.substr(0, end));
            //std::cout << count << endl;
            
            auto subdomains = domain.substr(end+1, string::npos);
            auto it = res.find(subdomains);
            if (it != res.end()) {
                it->second += count;
            } else {
                res[subdomains] = count;
            }
            
            //std::cout << subdomains << endl;
            
            end = subdomains.find('.');
            while (end != string::npos) {
                subdomains = subdomains.substr(end+1, string::npos);
                //cout << subdomains << endl;
                it = res.find(subdomains);
                if (it != res.end()) {
                    it->second += count;
                } else {
                    res[subdomains] = count;
                }
                
                end = subdomains.find('.');
            }
            
        }
        
        std::vector<string> result;
        for (auto& dom : res) {
            string count_r = std::to_string(dom.second);
            result.push_back(count_r + " " + dom.first);
        }
        return result;
    }
};
