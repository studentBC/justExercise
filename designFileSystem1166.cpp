/*
You are asked to design a file system which provides two functions:

create(path, value): Creates a new path and associates a value to it if possible and returns True. Returns False if the path already exists or its parent path doesn't exist.
get(path): Returns the value associated with a path or returns -1 if the path doesn't exist.
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.

Implement the two functions.

Please refer to the examples for clarifications.

 

Example 1:

Input: 
["FileSystem","create","get"]
[[],["/a",1],["/a"]]
Output: 
[null,true,1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.create("/a", 1); // return true
fileSystem.get("/a"); // return 1
Example 2:

Input: 
["FileSystem","create","create","get","create","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
Output: 
[null,true,true,2,false,-1]
Explanation: 
FileSystem fileSystem = new FileSystem();

fileSystem.create("/leet", 1); // return true
fileSystem.create("/leet/code", 2); // return true
fileSystem.get("/leet/code"); // return 2
fileSystem.create("/c/d", 1); // return false because the parent path "/c" doesn't exist.
fileSystem.get("/c"); // return -1 because this path doesn't exist.
 

Constraints:

The number of calls to the two functions is less than or equal to 10^4 in total.
2 <= path.length <= 100
1 <= value <= 10^9

wrong test case:
Input
["FileSystem","create","get","get","get","create","create","create","get"]
[[],["/zt/x",710263947],["/zt/ob"],["/zt/u"],["/zt"],["/zt/u",99415876],["/zt",912783775],["/zt/ob",885899287],["/zt/x"]]

Input
["FileSystem","create","create","get","create","get"]
[[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
*/
class FileSystem {
public:
    FileSystem() {
        dir.clear();
    }

    bool create(string path, int value) {
        //cout << path << endl;
        vector<string>p;
        int count = 0;
        for (char c:path) {
            if (c == '/') count++;
        }
        if (count == 0) {
            return false;
        } else if (count == 1) {
            if (!dir[path]) {
                dir[path]=value;
                return true;
            }
            return false;
        } else {
            int end = 0;
            for (int i = path.size()-1; i > -1; i--) {
                if (path[i] == '/') {
                    end++;
                    break;
                } else {
                    end++;
                }  
            }
            //cout << end <<" , " ;
            string s(path, 0, path.size()-end);
            //cout <<"go find " <<s<< endl;
            //cout << dir[s] << endl;
            //if (dir[s] ) cout <<"can find "<<endl;
            if (!dir[s] || dir[path]) return false;
            //cout <<"cant find " <<s<< endl;
            dir[path]=value;
            return true;
        }


    }

    int get(string path) {
        if (dir[path]) return dir[path];
        return -1;
    }
private:
    map<string,int>dir;
};

//the fatest method
class FileSystem {
public:
  bool create(const string& path, int value) {
    auto parent = string(path.begin(), path.begin() + path.rfind("/"));
    if (!parent.empty() && !paths.count(parent))
      return false;
    return paths.emplace(path, value).second;
  }
    
  int get(const string& path) {
    auto it = paths.find(path);
    if (it == paths.end())
      return -1;
    return it->second;
  }
  
private:
  unordered_map<string, int> paths;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */

static auto const magic = []{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
