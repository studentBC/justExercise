class Solution {
public:
	string id2url (long key) {
		string mp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
		string url;
		while (key) {
			url.push_back(mp[key%62]);
			key/=62;
		}
		reverse(url.begin(), url.end());
		return url;
	}
	long url2id (string url) {
		long id = 0; // initialize result 
	  
		// A simple base conversion logic 
		for (int i=0; i < url.size(); i++) 
		{ 
			if ('a' <= url[i] && url[i] <= 'z') 
			  id = id*62 + url[i] - 'a'; 
			if ('A' <= url[i] && url[i] <= 'Z') 
			  id = id*62 + url[i] - 'A' + 26; 
			if ('0' <= url[i] && url[i] <= '9') 
			  id = id*62 + url[i] - '0' + 52; 
		} 
		return id; 
	}
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
		long key;
		do {
			key = rand();
		} while (db.find(key) != db.end());
		db[key] = longUrl;
		return id2url(key);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return db[url2id(shortUrl)];
    }
private:
	srand (time(NULL));
	unordered_map<long,string>db;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// the fatest solution
class Solution {
public:
    unordered_map<int, string> mapper;
    int i = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mapper[i++] = longUrl;
        return to_string(i-1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mapper[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

