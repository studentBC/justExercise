/*
Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

 

Example:

Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false
 
["Vector2D","hasNext","next","hasNext"]
[[[[],[3]]],[null],[null],[null]]

["Vector2D","hasNext","next","hasNext"]
[[[[-1],[],[]]],[null],[null],[null]]



Notes:

Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.*/
class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        data = v;
    }

    int next() {
        int ans = INT_MAX;
        while (ans == INT_MAX && i < data.size()) {
            if (i < data.size() && j < data[i].size()) {
                ans = data[i][j];
                if (j+1 < data[i].size()) {
                    j++;
                } else {
                    i++;j = 0;
                }
            } else {
                i++;
            }
        }
        return ans;
    }

    bool hasNext() {
        //cout <<"start from "<< i <<" , "<< j << endl;
        if (i < data.size() && j < data[i].size()) {
            return true;
        } else {
            while (i < data.size()) {
                i++;
                if (i < data.size() && j < data[i].size()) {
                    j = 0;
                    return true;
                }
            }
        }
        return false;
    }
private:
    vector<vector<int>>data;
    int i = 0, j = 0;
};
//the fatest method
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        data = v;
        r = 0;
        c = 0;
    }
    
    int next() {
        hasNext();
 //       cout<<r<<" "<<c<<endl;
        return data[r][c++];
    }
    
    bool hasNext() {
        while(r < data.size() && c == data[r].size()) {
            ++r;
            c = 0;
        }
        return r < data.size();
    }
private:
    vector<int> cur;
    int r, c;
    vector<vector<int>> data;
};


int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
