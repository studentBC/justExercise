class Solution {
public:
    void go (int start, vector<int>& temp, vector<int>& candidate, vector<vector<int>>& newtime) {
        if (temp.size() == 4) {
            //for (char c: temp) cout << c << " , ";
            //cout << endl;
            int hour = (temp[0])*10+temp[1];
            if (hour <= 24) {
                int min = (temp[2])*10+temp[3];
                if (min <= 59) {
                    newtime.emplace_back(temp);
                    return;
                }
            }
        } else {
            for (int i = 0; i < candidate.size(); i++) {
                temp.push_back(candidate[i]);
                go (i, temp, candidate, newtime);
                temp.pop_back();
            }
        }
    }
    string nextClosestTime(string time) {
        int h = 0, m = 0, pos = 0;
        bool meet = false;
        for (char c:time) {
            if (c == ':') {
                meet = true;
            } else {
                if (!meet) {
                    h = h*10+c-'0';
                    pos++;
                } else {
                    m = m*10+c-'0';
                }
            }
        }
        vector<int>candidate, temp, index;
        for (char c: time) {
            if (c != ':') candidate.emplace_back(c-'0');
        }
        while (candidate.size() < 4) candidate.emplace_back(0);
        vector<vector<int>>newtime;
        string ans;
        go (0, temp, candidate, newtime);
        int hour, min, big = INT_MAX;
        double diff;
        for (auto& it: newtime) {
            hour = min = 0;
            for (int i = 0; i < 2; i++) hour = 10*hour+it[i];
            for (int i = 2; i < it.size(); i++) min = 10*min+it[i];
            //cout << hour <<" : " << min << endl;
			if (hour == h && min > m ) {
				diff = (hour-h)*60 + (min-m);
				if (big > abs(diff)) {
					big = abs(diff);
					index = it;
				}
			} else if (hour > h) {
				diff = (hour-h)*60 + (min-m);
				if (big > abs(diff)) {
					big = abs(diff);
					index = it;
				}
			} else {
				diff = (24+hour-h)*60 + (min-m);
				if (big > abs(diff)) {
					big = abs(diff);
					index = it;
				}
			}
        }
        for (int i = 0; i < 2; i++) {
            ans.push_back(index[i]+'0');
        }
        ans.push_back(':');
        for (int i = 2; i < index.size(); i++) {
            ans.push_back(index[i]+'0');
        }
        return ans;
    }
};
//the fatest solution
class Solution {
public:
    string nextClosestTime(string time) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int i = time.length() - 1;
        set<char>::iterator it;
        set<char> st;
        
        for(int j = 0; j < time.length(); j++)
            if(j != 2)
                st.insert(time[j]);
        
        while(i >= 0){
            it = st.find(time[i]);
            if(i == 4){
                if(++it != st.end()){
                    time[i] = *it;
                    break;
                }
            }else if(i == 3){
                if(++it != st.end() && *it < '6'){
                    time[i] = *it;
                    break;
                }
            }else if(i == 1){
                if(++it != st.end() && (time[0] < '2' || *it < '4')){
                    time[i] = *it;
                    break;
                }
            }else if(i == 0){
                if(++it != st.end() && *it < '3'){
                    time[i] = *it;
                    break;
                }
            }
            i--;
        }
        
        while(++i < time.length()){
            if(i != 2)
                time[i] = *(st.begin());            
        }

        
        return time;
    }
};
