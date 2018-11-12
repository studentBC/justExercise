//fatest method
class Solution {
public:
    vector<int> grayCode(int n) {
       bitset<32> bits;
		vector<int> ans;
		auto bt = [&bits, &ans, n](int i, const auto& fun) -> void {
			if (n == i) ans.push_back((int)bits.to_ulong());
			else {
				fun(i + 1, fun);
				bits.flip(i);
				fun(i + 1, fun);
			}
		};
		bt(0, bt);
		return ans;
    }
};
//my method beat 80%
class Solution {
public:
    vector<int> grayCode(int n) {
       vector<int> ans;
       if (n < 1) {
           ans.push_back(0);
           return ans;
        }
       int half, total;
       vector<int*>basic;
       int* array;
       array = new int[n];
       //initialize array
       for (int i = 0; i < n; i++) {
           array[i] = 0;
       }
       basic.push_back(array);
        
       array = new int[n];
       //initialize array
       for (int i = 0; i < n; i++) {
           array[i] = 0;
       }
       array[n-1] = 1;
       basic.push_back(array);
       
       int* temp;
       for (int i = 2; i <= n; i++) {
           half = basic.size()-1;
           total = pow(2,i);
            for (int j = half; j > -1; j--) {
                temp = new int[n];
                for (int a = 0; a < n; a++) temp[a] = basic[j][a];
                //temp = basic[j];
                basic.push_back(temp);
                basic[j][n-i] = 0;
            }
            for (int k = half+1; k < total; k++) {
                basic[k][n-i] = 1;
            }
       }
        /*
        for (int i = 0; i < basic.size(); i++) {
           for (int j = 0; j < n; j++) {
               cout << basic[i][j] << " , ";
            }
           cout << endl;
       }
       */
       int sum = 0;
       for (int i = 0; i < basic.size(); i++) {
           sum = 0;
           for (int j = n-1; j >-1; j--) {
               //cout << basic[i][j]*pow(2,j) << " , ";
                sum+=(basic[i][j]*pow(2,j));
           }
           ans.push_back(sum);
       }
       return ans;

    }
};
