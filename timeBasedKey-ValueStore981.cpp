class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (data.find(key) == data.end()) {
            data[key].emplace_back(make_pair(timestamp, value));
        } else {
            if (data[key][0].first >= timestamp) {
                data[key].insert(data[key].begin(), make_pair(timestamp, value));
            } else if (data[key].back().first <= timestamp) {
                data[key].emplace_back(make_pair(timestamp, value));
            } else {
                int end = data[key].size()-1;
                for (int i = 0; i < end; i++) {
                    if (data[key][i].first <= timestamp && timestamp <= data[key][i+1].first) {
                        data[key].insert(data[key].begin()+i+1, make_pair(timestamp, value));
                        return;
                    }
                }
            }
        }
        
    }
    
    string get(string key, int timestamp) {
        if (data[key].size()) {
            /* int left = 0, right = data[key].size()-1, mid;
            while (left <= right) {
                mid = left+(right-left)/2;
                if (data[key][mid].first == timestamp) {
                    return data[key][mid].second;
                } else if (data[key][mid].first > timestamp) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }*/
            for (int i = data[key].size()-1; i > -1; i--) {
                if (timestamp >= data[key][i].first) {
                    return data[key][i].second;
                }
            }
            return "";
        } else {
            return "";
        }
    }
private:
    unordered_map<string,vector<pair<int,string>>>data;
};
//the 268 ms solution
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
    }
    
    void set(string key, string value, int timestamp) {
    	hash[key].emplace_back(value, timestamp);
    	return;
    }
    
    string get(string key, int timestamp) {
        if (hash.find(key) == hash.end()) {
        	return "";
        }
        const auto& vec = hash[key];
        KeyValue tsToFind;
        tsToFind.timestamp = timestamp;
        auto it = lower_bound(vec.begin(), vec.end(), tsToFind, [](const KeyValue& lhs, const KeyValue& rhs) {
        	return lhs.timestamp < rhs.timestamp;
        });
        if (it == vec.end()) {
        	return vec.back().value;
        }
        if (it == vec.begin() && it->timestamp != timestamp) {
            return "";
        }
        if (it->timestamp == timestamp) {
            return it->value;
        }
        return (--it)->value;
    }
private:
	struct KeyValue
	{
		KeyValue()
		{}
		KeyValue(string v, int t)
			: timestamp(t)
			, value(v)
		{}
		int timestamp;
		string value;
	};
	unordered_map<string, vector<KeyValue>> hash;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
