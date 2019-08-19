/*
You are given several logs that each log contains a unique id and timestamp. Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.

Design a log storage system to implement the following functions:

void Put(int id, string timestamp): Given a log's unique id and timestamp, store the log in your storage system.


int[] Retrieve(String start, String end, String granularity): Return the id of logs whose timestamps are within the range from start to end. Start and end all have the same format as timestamp. However, granularity means the time level for consideration. For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", granularity = "Day", it means that we need to find the logs within the range from Jan. 1st 2017 to Jan. 2nd 2017.

Example 1:
put(1, "2017:01:01:23:59:59");
put(2, "2017:01:01:22:59:59");
put(3, "2016:01:01:00:00:00");
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); // return [1,2,3], because you need to return all logs within 2016 and 2017.
retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); // return [1,2], because you need to return all logs start from 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.
Note:
There will be at most 300 operations of Put or Retrieve.
Year ranges from [2000,2017]. Hour ranges from [00,23].
Output for Retrieve has no order required.
*/
ass LogSystem {
public:
    LogSystem() {

    }

    void put(int id, string timestamp) {
        vector<int>temp;
        timestamp+=":";
        int num = 0;
        for (char c:timestamp) {
            if (c == ':') {
                temp.emplace_back(num);
                num = 0;
            } else {
                num = num*10+c-'0';
            }
        }
        temp.emplace_back(id);
        data.emplace_back(temp);
    }

    vector<int> retrieve(string s, string e, string gra) {
        vector<int>ans, start, end;
        s+=":";e+=":";
        int num = 0;
        for (char c:s) {
            if (c == ':') {
                start.emplace_back(num);
                num = 0;
            } else {
                num = num*10+c-'0';
            }
        }
        num = 0;
        for (char c:e) {
            if (c == ':') {
                end.emplace_back(num);
                num = 0;
            } else {
                num = num*10+c-'0';
            }
        }

        time_t start_t, end_t, tmp_t;
        struct tm ss, ee, temp;
        double seconds, sec;
        ss.tm_year = start[0]; ss.tm_mon = start[1];  ss.tm_mday = start[2];
        ss.tm_hour = start[3]; ss.tm_min = start[4]; ss.tm_sec = start[5];

        ee.tm_year = end[0]; ee.tm_mon = end[1];  ee.tm_mday = end[2];
        ee.tm_hour = end[3]; ee.tm_min = end[4]; ee.tm_sec = end[5];
        //start_t = mktime(&ss);
        //end_t = mktime(&ee);
        if (gra == "Year") {
            ss.tm_mon = 1;  ss.tm_mday = 1; ss.tm_hour = 12; ss.tm_min = 0; ss.tm_sec = 0;
            ee.tm_mon = 1;  ee.tm_mday = 1; ee.tm_hour = 12; ee.tm_min = 0; ee.tm_sec = 0;
            start_t = mktime(&ss);
            end_t = mktime(&ee);
            seconds = difftime(end_t, start_t);
            for (int i = 0; i < data.size(); i++) {
                temp.tm_year = data[i][0]; temp.tm_mon = 1;  temp.tm_mday = 1;
                temp.tm_hour = 12; temp.tm_min = 0;  temp.tm_sec = 0;
                tmp_t = mktime(&temp);
                sec = difftime(tmp_t, start_t);
                if (sec <= seconds && sec >=0) ans.emplace_back(data[i][6]);
            }
        } else if (gra == "Month") {
            ss.tm_mday = 1; ss.tm_hour = 12; ss.tm_min = 0; ss.tm_sec = 0;
            ee.tm_mday = 1; ee.tm_hour = 12; ee.tm_min = 0; ee.tm_sec = 0;
            start_t = mktime(&ss);
            end_t = mktime(&ee);
            seconds = difftime(end_t, start_t);
            for (int i = 0; i < data.size(); i++) {
                temp.tm_year = data[i][0]; temp.tm_mon = data[i][1];  temp.tm_mday = 1;
                temp.tm_hour = 12; temp.tm_min = 0;  temp.tm_sec = 0;
                tmp_t = mktime(&temp);
                sec = difftime(tmp_t, start_t);
                if (sec <= seconds && sec >=0) ans.emplace_back(data[i][6]);
            }
        } else if (gra == "Day") {
            ss.tm_hour = 12; ss.tm_min = 0; ss.tm_sec = 0;
            ee.tm_hour = 12; ee.tm_min = 0; ee.tm_sec = 0;
            start_t = mktime(&ss);
            end_t = mktime(&ee);
            seconds = difftime(end_t, start_t);
            for (int i = 0; i < data.size(); i++) {
                temp.tm_year = data[i][0]; temp.tm_mon = data[i][1];  temp.tm_mday = data[i][2];
                temp.tm_hour = 12; temp.tm_min = 0;  temp.tm_sec = 0;
                tmp_t = mktime(&temp);
                sec = difftime(tmp_t, start_t);
                if (sec <= seconds && sec >=0) ans.emplace_back(data[i][6]);
            }
        } else if (gra == "Hour") {
            ss.tm_min = 0; ss.tm_sec = 0;
            ee.tm_min = 0; ee.tm_sec = 0;
            start_t = mktime(&ss);
            end_t = mktime(&ee);
            seconds = difftime(end_t, start_t);
            for (int i = 0; i < data.size(); i++) {
                temp.tm_year = data[i][0]; temp.tm_mon = data[i][1];  temp.tm_mday = data[i][2];
                temp.tm_hour = data[i][3]; temp.tm_min = 0;  temp.tm_sec = 0;
                tmp_t = mktime(&temp);
                sec = difftime(tmp_t, start_t);
                if (sec <= seconds && sec >=0) ans.emplace_back(data[i][6]);
            }
        } else if (gra == "Minute") {
            ss.tm_sec = 0;
            ee.tm_sec = 0;
            start_t = mktime(&ss);
            end_t = mktime(&ee);
            seconds = difftime(end_t, start_t);
            for (int i = 0; i < data.size(); i++) {
                temp.tm_year = data[i][0]; temp.tm_mon = data[i][1];  temp.tm_mday = data[i][2];
                temp.tm_hour = data[i][3]; temp.tm_min = data[i][4];  temp.tm_sec = 0;
                tmp_t = mktime(&temp);
                sec = difftime(tmp_t, start_t);
                if (sec <= seconds && sec >=0) ans.emplace_back(data[i][6]);
            }
        } else if (gra == "Second") {
            start_t = mktime(&ss);
            end_t = mktime(&ee);
            seconds = difftime(end_t, start_t);
            for (int i = 0; i < data.size(); i++) {
                temp.tm_year = data[i][0]; temp.tm_mon = data[i][1];  temp.tm_mday = data[i][2];
                temp.tm_hour = data[i][3]; temp.tm_min = data[i][4];  temp.tm_sec = data[i][5];
                tmp_t = mktime(&temp);
                sec = difftime(tmp_t, start_t);
                if (sec <= seconds && sec >=0) ans.emplace_back(data[i][6]);
            }
        }

        return ans;
    }
private:
    vector<vector<int>>data;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */
//the fatest method
class LogSystem {
private:
    multimap<string, int> m;
    
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        m.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        if (gra == "Year") {
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        }
        else if (gra == "Month") {
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        }
        else if (gra == "Day") {
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        }
        else if (gra == "Hour") {
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        }
        else if (gra == "Minute") {
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
        auto start = m.lower_bound(s), end = m.upper_bound(e);
        vector<int> ans;
        for (auto iter = start; iter != end; ++iter)
            ans.push_back(iter->second);
        return ans;
    }
};
