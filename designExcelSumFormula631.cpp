/*
 *Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need to implement the following functions:

 Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a positive integer, range from 1 to 26. It represents the height. W is a character range from 'A' to 'Z'. It represents that the width is the number of characters from 'A' to W. The Excel form content is represented by a height * width 2D integer array C, it should be initialized to zero. You should assume that the first row of C starts from 1, and the first column of C starts from 'A'.


 void Set(int row, char column, int val): Change the value at C(row, column) to be val.


 int Get(int row, char column): Return the value at C(row, column).


 int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column), where the value should be the sum of cells represented by numbers. This function return the sum result at C(row, column). This sum formula should exist until this cell is overlapped by another value or another sum formula.

 numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it has the following format : ColRow. For example, "F7" represents the cell at (7, F).

 If the string represent a range of cells, then it has the following format : ColRow1:ColRow2. The range will always be a rectangle, and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.


 ["Excel","set","sum","set"]
 [[3,"C"],[1,"A",2],[3, "C", ["A1", "A1:B2"]],[2,"B",2]]


 Example 1:
 Excel(3,"C"); 
 // construct a 3*3 2D array with all zero.
 // //   A B C
 // // 1 0 0 0
 // // 2 0 0 0
 // // 3 0 0 0
 //
 // Set(1, "A", 2);
 // // set C(1,"A") to be 2.
 // //   A B C
 // // 1 2 0 0
 // // 2 0 0 0
 // // 3 0 0 0
 //
 // Sum(3, "C", ["A1", "A1:B2"]);
 // // set C(3,"C") to be the sum of value at C(1,"A") and the values sum of the rectangle range whose top-left cell is C(1,"A") and bottom-right cell is C(2,"B"). Return 4. 
 // //   A B C
 // // 1 2 0 0
 // // 2 0 0 0
 // // 3 0 0 4
 //
 // Set(2, "B", 2);
 // // set C(2,"B") to be 2. Note C(3, "C") should also be changed.
 // //   A B C
 // // 1 2 0 0
 // // 2 0 2 0
 // // 3 0 0 6
 // Note:
 // You could assume that there won't be any circular sum reference. For example, A1 = sum(B1) and B1 = sum(A1).
 // The test cases are using double-quotes to represent a character.
 // Please remember to RESET your class variables declared in class Excel, as static/class variables are persisted across multiple test cases. Please see here for more details.
 *
 * test case:
 * ["Excel","set","sum","set"]
 * [[3,"C"],[1,"A",2],[3, "C", ["A1", "A1:B2"]],[2,"B",2]]
 *
 * ["Excel","set","sum","set","get","set","get"]
 * [[5,"E"],[1,"A",1],[2,"B",["A1"]],[2,"B",0],[2,"B"],[1,"A",5],[2,"B"]]
 *
 * ["Excel","set","set","set","sum","get","set","get","sum","set","get","get","sum","set","get","get","get","get"]
 * [[5,"E"],[1,"A",5],[1,"B",3],[1,"C",2],[1,"C",["A1","A1:B1"]],[1,"C"],[1,"B",5],[1,"C"],[1,"B",["A1:A5"]],[5,"A",10],[1,"B"],[1,"C"],[3,"C",["A1:C1","A1:A5"]],[3,"A",3],[1,"B"],[1,"C"],[3,"C"],[5,"A"]]
 *
 * ["Excel","set","set","sum","sum"]
 * [[26,"Z"],[1,"A",1],[1,"I",1],[7,"D",["A1:D6","A1:G3","A1:C12"]],[10,"G",["A1:D7","D1:F10","D3:I8","I1:I9"]]]
 *
 */
class Excel {
public:
    Excel(int H, char W) {
		number = new int*[H];
		int col = W-'A'+1;
        for (int i = 0; i < col; i++) {
			number[i] = new int[col];
            memset(number[i], 0, sizeof(int)*col);
		}
    }
    
    void set(int r, char c, int v) {
        int diff = v-number[r-1][c-'A'];
        number[r-1][c-'A'] = v;
        string key = to_string(r);
        key.push_back(c);
        for (auto& it: formula) {
            if (it.first == key) {
                formula.erase(key);
                break;
            }
        }
        change.push_back(make_pair(key, diff));
        update();
        cout <<"set " << r <<" , " << c << endl;
    }

    void update() {
        int count, diff, num; 
        while (change.size()) {
            pair<string,int> t = change.back();
            change.pop_back();
            diff = t.second;
            num = 0; 
            for (int i = 0; i < t.first.size()-1; i++) {
                num = num*10+t.first[i]-'0';
            }
            pair<int,int>target(num-1, t.first.back()-'A');
            cout <<"target:  " << target.first <<" , " << target.second << endl;
            for (auto& it: formula) {
                count = 0; 
                for (auto& p: it.second) {
                    if (p == target) count++;
                }
                cout <<"count is " << count << " diff is  " << diff << endl;
                if (count) { 
                    num = 0; 
                    cout <<"key:  " << it.first << endl;
                    for (int i = 0; i < it.first.size()-1; i++) {
                        num = num*10+it.first[i]-'0';
                    }
                    int c = it.first.back()-'A';
                    cout <<"at  " << num-1 <<" , " << c << "  original is  " << number[num-1][c] << endl;
                    number[num-1][c]+=count*diff;
                    cout <<"it became  " << number[num-1][c] << endl;
                    change.push_back(make_pair(it.first, count*diff));
                }
            }
        }
        return;
    }
    int get(int r, char c) {
        update();
        return number[r-1][c-'A'];
    }

    
    int sum(int r, char c, vector<string> strs) {
        //cout <<"here is sum" << endl;
		string key = to_string(r);
		key.push_back(c);
		int num = 0, sum = 0, prev = number[r-1][c-'A'];
		formula[key].clear();
        for (string s: strs) {
			size_t pos = s.find(':');
            num = 0;
			if (pos != string::npos) {
				int sr, sc = s[0]-'A', er, ec = s[pos+1]-'A';
				for (int i = 1; i < pos; i++) {
					num = num*10+s[i]-'0';
				}
				//cout <<"start row  " << num << endl;
				sr = num -1;
				num = 0;
				for (int i = pos+2; i < s.size(); i++) {
					num = num*10+s[i]-'0';
				}
				//cout <<"end row  " << num << endl;
				er = num-1;
                cout <<"sr:  " << sr << "  er:  " << er << endl;
                cout <<"sc:  " << sc << "  ec:  " << ec << endl;
				for (int i = sr; i <= er; i++) {
					for (int j = sc; j <= ec; j++) {
						formula[key].push_back(make_pair(i, j));
						sum+=number[i][j];
					}
				}

			} else {
				for (int i = 1; i < s.size(); i++) {
					num = num*10+s[i]-'0';
				}
				formula[key].push_back(make_pair(num-1, s[0]-'A'));
				sum+=number[num-1][s[0]-'A'];
			}
		}
		number[r-1][c-'A'] = sum;
        cout <<"set sum:   " << r-1 <<" , " << c-'A' <<"  is   " << sum << endl;
		change.push_back(make_pair(key,sum-prev));
        update();
		return sum;
    }
	int** number;
	unordered_map<string, vector<pair<int,int>>>formula;
	vector<pair<string,int>>change;
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 */
//the fatest solution
class Excel {
public:
    Excel(int H, char W) {
        m.clear();
        mat.resize(H, vector<int>(W - 'A'+  1, 0));
    }
    
    void set(int r, char c, int v) {
        if (m.count({r, c})) m.erase({r, c});
        mat[r - 1][c - 'A'] = v;
    }
    
    int get(int r, char c) {
        if (m.count({r, c})) return sum(r, c, m[{r, c}]);
        return mat[r - 1][c - 'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int res = 0;
        for (string str : strs) {
            auto found = str.find_last_of(":");
            if (found == string::npos) {
                char y = str[0];
                int x = stoi(str.substr(1));
                res += get(x, y);
            } else {
                int x1 = stoi(str.substr(1, (int)found - 1)), y1 = str[0] - 'A';
                int x2 = stoi(str.substr(found + 2)), y2 = str[found + 1] - 'A';
                for (int i = x1; i <= x2; ++i) {
                    for (int j = y1; j <= y2; ++j) {
                        res += get(i, j + 'A');
                    }
                }
            }
        }
        m[{r, c}] = strs;
        return res;
    }

private:
    vector<vector<int>> mat;
    map<pair<int, char>, vector<string>> m;
};
