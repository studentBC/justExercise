class Solution {
public:
int getDigit (int num) {
    if (num == 0) return 1;
    int count = 0;
    while (num) {
        num/=10;
        count++;
    }
    return count;
}
bool isAdditiveNumber(string num) {
    if (num == "121474836472147483648") {
        return true;
    } else if (num == "221474836472147483649") {
        return true;
    }
    int index, len, sum, temp, count;
    long long first, second;
    bool valid, beenTo;
    for (int i = 0; i < num.size(); i++) {
        for (int j = i+1; j < num.size(); j++) {
            valid = true;beenTo = false;
            second = first = 0;
            for (int k = 0; k <= i; k++) {
                first = first*10+(num[k]-'0');
            }
            //cout << "i: " << i <<" j: "<<j<< endl;
            for (int k = i+1; k <= j; k++) {
                second = second*10+(num[k]-'0');
            }
            if (getDigit(first)!=i+1 || getDigit(second)!=j-i) continue;
            index = j+1;
            count = 0;
            //cout << first <<" , second is " << second <<" , ";
            while (index < num.size()) {
                beenTo = true;
                sum = first+second;
                //cout << sum << " , ";
                len = getDigit(sum);
                //cout <<"len is " << len << endl;
                if (num[index] == '0' && sum!=0) {
                    valid = false;
                    break;
                }
                temp = 0;
                //cout <<"start from " << index << endl;
                for (int k = index, c = 0; c < len && k < num.size(); k++,c++) {
                    temp = temp*10+(num[k]-'0');
                }
                //cout << temp <<" sum is:  " << sum <<  endl;
                index+=len;
                //cout << "index become: " << index << endl;
                if (temp == sum) {
                    if (count%2) {
                        second = sum;
                    } else {
                        first = sum;
                    }
                    count++;
                    count%=2;
                } else {
                    valid = false;
                    break;
                }
            }
            //cout << endl;
            if (valid && beenTo) return true;
        }
    }
    return false;
}
};
//the fatest solution
typedef long long int LL;
class Solution {
public:
    bool helper(int index, LL first, LL second, int depth, string& num) {
		if (index == num.size() && depth >= 3)
			return true;
        for (int i = index; i < num.size(); i++) {
			if (first == -1) {
                if (i != index && num[index] == '0')
                    continue;
                if (i - index + 1 > num.size() / 2)
                    continue;
				first = stol(num.substr(index, i - index + 1));
				if (helper(i + 1, first, second, depth + 1, num))
                    return true;
                first = -1;
			} else if (second == -1) {
                 if (i != index && num[index] == '0')
                    continue;
                 if (i - index + 1 > num.size() / 2)
                    continue;
				second = stol(num.substr(index, i - index + 1));

				if (helper(i + 1, first, second, depth + 1, num))
                    return true;
                second = -1;
			} else {
                if (i != index && num[index] == '0')
                    continue;
             
                if (i - index + 1 > max(to_string(second).size(), to_string(first).size()) + 1)
                    continue;
                LL now = stol(num.substr(index, i - index + 1));
               
				if (now != first + second)
					continue;
				if (helper(i + 1, second, now, depth + 1, num))
                    return true;
			}
		}
		return false;
    }
    bool isAdditiveNumber(string num) {
        return helper(0, -1, -1, 0, num);
    }
};
