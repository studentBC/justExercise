class Solution {
public:
    string simplifyPath(string path) {
        path+="/";
        std::string delimiter = "/";
        size_t pos = 0;
        string token, ans = "/";
        vector<string>canonicalPath;
        while ((pos = path.find(delimiter)) != std::string::npos) {
            token = path.substr(0, pos);
            //cout << token << std::endl;
            if (token == "..") {
                if(!canonicalPath.empty()) canonicalPath.pop_back();
            } else if (token != "." && token != "") {
                canonicalPath.emplace_back(token);
            }
            path.erase(0, pos + delimiter.length());
        }
        int end = canonicalPath.size()-1;
        for (int i = 0; i < end; i++) {
            ans.append(canonicalPath[i]);
            ans.append("/");
        }
        if (end > -1) ans.append(canonicalPath[end]);
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> folders;
        istringstream iss(path);
        
        string folder_name;
        while (getline(iss, folder_name, '/')) {
            if (!folder_name.empty()) {
                if (folder_name == ".." && !folders.empty()) {
                    folders.pop_back();
                } else if (folder_name != "." && folder_name != "..") {
                    folders.push_back(folder_name);
                }
            }
        }
        
        string ret = "";
        while (!folders.empty()) {
            ret += "/" + folders.front();
            folders.pop_front();
        }
        return ret.empty() ? "/" : ret;

    }
};

