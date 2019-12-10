/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 * https://en.cppreference.com/w/cpp/thread/thread/thread
 * http://www.cplusplus.com/reference/thread/thread/thread/
 */
class Solution {
public:
    string getHost (string url) {
        string ans;
        for (int i = 7; i < url.size(); i++) {
            if (url[i] == '/') return ans;
            ans.push_back(url[i]);
        }
        return ans;
    }
    void go (string startUrl, string target) {
        //if (visit.count(startUrl)) return;
        vector<string> links = hp->getUrls(startUrl);
        vector<string>valid;
        for (string s:links) {
            if (getHost(s) == target) {
                valid.push_back(s);
            }
        }

        vector<thread*>at;
        for (string s:valid) {
            m.lock();
			if (!visit.count(s)) {
                visit.insert(s);
                ans.push_back(s);
			} else continue;
            m.unlock();
            thread *t = new thread (&Solution::go , this, s, target);
            at.emplace_back(t);
        }
        for (auto& t: at) {
            if(t)t->join();
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        hp = &htmlParser;
        m.lock();
        m.unlock();
        thread mt (&Solution::go, this ,startUrl, getHost(startUrl));
        mt.join();
        return ans;
    }
private:
    mutex m;
    HtmlParser* hp;
    unordered_set<string> visit;
    vector<string> ans;
};


class Solution {
public:
    
    string GetHost(const string& s)
    {
        string res = "";
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == '/' && s[i - 1] == '/')
            {
                for (++i; i < s.size() && s[i] != '/'; ++i) res += s[i];                                    
                break;
            }
        }
        
        return res;
    }
    
    bool CompareStr(const string& s, string& pattern)
    {
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == '/' && s[i - 1] == '/')
            {
                int index = 0;
                for (++i; i < s.size() && s[i] != '/'; ++i)
                {
                    if (index >= pattern.size()) return false;
                    if (pattern[index] != s[i]) return false;
                    ++index;
                }
                if (index != pattern.size()) return false;                
                return true;
            }
        }
        return false;
    }
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        
        hostName = GetHost(startUrl);        
        pParser  = &htmlParser;        
        hash.insert(startUrl);
        res.push_back(startUrl);
        
        thread mainThread(&Solution::Visit, this, startUrl);
        mainThread.join();
                        
        return res;
    }
    
    void Visit(string startUrl)
    {   
        vector<string> urls = pParser->getUrls(startUrl);
                
        vector<string> temp;
        for (auto curUrl : urls)
        {
            if (CompareStr(curUrl, hostName) == false) continue;
            temp.push_back(curUrl);            
        }
        
        int index = 0;
        vector<thread*> vecThread(temp.size(), NULL);
        for (auto curUrl : temp)
        {
            unique_lock<mutex> lkHash(mHash);
            if (hash.count(curUrl) == 0) 
            {
                hash.insert(curUrl);            
                res.push_back(curUrl);
            }
            else continue;
            lkHash.unlock();
            
            vecThread[index++] = new thread(&Solution::Visit, this, curUrl);            
        }
        
        for (auto& item : vecThread)
            if (item == NULL) break;
                         else item->join();                
    }
        
    mutex mHash;
    
    string hostName;
    vector<string> res;
    unordered_set<string> hash;
    HtmlParser* pParser;    
    
};

//the fatets solution

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
      unordered_set<string> vis;
      queue<string> q;
      q.push(startUrl);
      
      vis.insert(startUrl);
      string tld = getTld(startUrl);
      //cout << "tld: " << tld << endl;
      
      for (; !q.empty(); q.pop()) {
        auto url = q.front();
        auto links = htmlParser.getUrls(url);
        
        //cout << "crawl url: " << url << endl;
        
        for (auto& l : links) {
          if (vis.count(l)) continue;
          
          //cout << " - next: " << l << endl;
          
          string nTld = getTld(l);
          if (nTld != tld) continue;
          
          q.push(l);
          vis.insert(l);
        }
      }
      
      return vector<string>(vis.begin(), vis.end());
    }
  
    string getTld(string& url) {
      if (url.empty()) return url;
      
      return url.substr(7, url.find('/', 7) - 7);
    }
};
