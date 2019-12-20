/*
Design an in-memory file system to simulate the following functions:

ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.

mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.

addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.

readContentFromFile: Given a file path, return its content in string format.

 

Example:

Input: 
["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]

Output:
[null,[],null,null,["a"],"hello"]

Explanation:
filesystem
 
wrong test case:
["FileSystem","mkdir","ls","ls","mkdir","ls","ls","addContentToFile","ls","ls","ls"]
[[],["/goowmfn"],["/goowmfn"],["/"],["/z"],["/"],["/"],["/goowmfn/c","shetopcy"],["/z"],["/goowmfn/c"],["/goowmfn"]]



Note:

You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.
*/
class FileSystem {
    class fs {
        public:
            //fs();
            fs (string name) {
                folderName = name;
            }
            vector<FileSystem::fs*>folder;
            unordered_map<string, string>file;
            string folderName;
    };
public:
    fs* root = NULL;
    queue<string>getPath (string path) {
        stringstream ss(path);
        string p;
        queue<string>subpath;
        while (getline(ss,p, '/')) {
            if(p.size())subpath.push(p);
            //cout<< p <<endl;
        }
        return subpath;
    }

    FileSystem() {
        root = new fs("root");
    }

    vector<string> ls(string path) {
        //cout <<"try to find " << path << endl;
        queue<string>paths = getPath(path);
        vector<string>ans;
        if (paths.size()) {
            fs* next = root;
            bool found = true;
            while (paths.size() && found ) {
                found = false;
                for (auto& f: next->folder) {
                    if (f->folderName == paths.front()) {
                        next = f;
                        paths.pop();
                        found = true;
                        break;
                    }
                }
            }
            if (paths.size()) {
                //cout <<"here " << endl;
                ans.emplace_back(paths.front());
                return ans;
            } else {
                //cout <<"folder name is " << next->folderName << endl;
                for (auto& it: next->file) ans.emplace_back(it.first);
                for (auto& it: next->folder) ans.emplace_back(it->folderName);
            }
        } else {
            //cout <<"folder name is : " << root->folderName << endl;
            //cout <<root->file.size() << endl;
            for (auto& it: root->file) ans.emplace_back(it.first);
            for (auto& it: root->folder) ans.emplace_back(it->folderName);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    void mkdir(string path) {
        queue<string>paths = getPath(path);
        fs* next = root;
        bool found = true;
        while (paths.size()) {
            found = false;
            for (auto& f: next->folder) {
                if (f->folderName == paths.front()) {
                    next = f;
                    paths.pop();
                    found = true;
                    break;
                }
            }
            if (!found) {
                fs* newfolder = new fs(paths.front());
                paths.pop();
                next->folder.emplace_back(newfolder);
                next = newfolder;
            }
        }
        return;
    }

    void addContentToFile(string filePath, string content) {
        queue<string>paths = getPath(filePath);
        fs* next = root;
        bool found = true;
        while (paths.size() > 1 && found ) {
            found = false;
            for (auto& f: next->folder) {
                if (f->folderName == paths.front()) {
                    next = f;
                    paths.pop();
                    found = true;
                    break;
                }
            }
        }
        //cout <<"set file name: " << paths.front() << endl;
        next->file[paths.front()] += content;
    }

    string readContentFromFile(string filePath) {
        queue<string>paths = getPath(filePath);
        fs* next = root;
        bool found = true;
        while (paths.size() > 1 && found ) {
            found = false;
            for (auto& f: next->folder) {
                if (f->folderName == paths.front()) {
                    next = f;
                    paths.pop();
                    found = true;
                    break;
                }
            }
        }
        //cout <<"read file name: " << paths.front() << endl;
        return next->file[paths.front()];
    }
};
//the fatest solution
class FileSystem {
public:
    FileSystem () {
        dirs["/"]; // initialize a root path
    }
    
    // If it is a directory path, return the list of file and directory names in this directory.
    vector<string> ls(string path) {
        if(files.count(path)) { // it is a file not directory
            int indx = path.find_last_of("/"); // "/"之後就是file name
            return {path.substr(indx+1)};
        }
        // else it is a diectory
        auto t = dirs[path];
        vector<string> res(t.begin(), t.end());
        return res;
    }
    
    void mkdir(string path) {
        istringstream is(path);
        string token = "";
        string dir = "";
        while(getline(is, token, '/')) {
            // cout<< token<< " "; // " a b c"
            if(token.empty())
                continue;
            if(dir.empty()) {
                // cout<<"empty: \n"<< dir<< endl;
                // cout<< "======\n";
                dir += "/";
            }
            dirs[dir].insert(token);
            
            // 每次都加 e.g. /a在後面
            if(dir.size() > 1) // > 1 否則會出現//a這樣的path(兩個/)
                dir += "/";
            dir += token;
            // cout<< dir<< endl;
        }
        // cout<< dir<< " "<< token;
        // dirs[dir].insert(token);
    }
    
    void addContentToFile(string filePath, string content) {
        // 例如 filePath: existDirectory/filename ==> 要把fileName加到existDirectory 下面
        int indx = filePath.find_last_of("/");
        string directoryPath = filePath.substr(0, indx);
        string fileName = filePath.substr(indx+1);
        cout<< directoryPath<< " "<< fileName<< endl;
        if(directoryPath.empty())
            directoryPath = "/";
        if(!dirs.count(directoryPath))
            mkdir(directoryPath);
        dirs[directoryPath].insert(fileName);
        // string test = "test1";
        // test.push_back('2');
        // cout<< test; // print out test12
        files[filePath].append(content); // append 因為content是string不是char, string的push_back只能用在char
    }
    
    string readContentFromFile(string filePath) {
        return files[filePath];
    }
private:
    unordered_map<string, set<string> > dirs; // 這個path下面的所有directory
    unordered_map<string, string> files; // file's path: content
};
// 其中dirs建立了路径和其对应的包含所有文件和文件夹的集合之间的映射，files建立了文件的路径跟其内容之间的映射。
/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
