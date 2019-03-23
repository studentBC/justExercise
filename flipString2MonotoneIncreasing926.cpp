class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int cost = 0, min = INT_MAX;
        vector<int>one(S.size()+1,0);
        vector<int>zero(S.size()+1,0);
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '0')zero[0]++;
        }
        one[S.size()] = S.size()-zero[0];
        //cout <<"right is zero " << endl;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '0') {
                zero[i+1] = zero[i]-1;
            } else {
                zero[i+1] = zero[i];
            }
            //cout << zero[i] <<" , ";
        }
        //cout << zero[S.size()] << endl << "left is one " << endl;
        //cout << one[S.size()] <<" , ";
        for (int i = S.size()-1; i >-1; i--) {
            if (S[i] == '1') {
                one[i] = one[i+1]-1;
            } else {
                one[i] = one[i+1];
            }
            //cout << one[i] <<" , ";
        }
        
        for (int i = 0; i < one.size(); i++) {
            cost = 0;
            //cost of RHS all become 1
            cost+=zero[i];
            //cost of LHS all become 0
            cost+=one[i];
            //cout <<"at "<<i <<" cost " << cost << endl;
            if (min > cost) min = cost;
        }
        return min;
    }
};
//the fatest method
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        
	int len = S.size();
	int i = 0;

	for (i = 0; i < len; i++)
	{
		char c = S[i];
		if (c == '1')
		{
			i++;
			break;
		}
	}

	int cnt0 = 0, cnt1 = 1, cnt = 0;
	bool isOne = false;

	for (; i < len; i++)
	{
		char c = S[i];
		if (c == '0')
		{
			cnt0++;
			isOne = false;
		}
		else
		{
			if (isOne == false)
			{
				isOne = true;
				// next set on ONES
				if (S[i - 1] == '0')
				{
					if (cnt0 > cnt1)
					{
						cnt += cnt1;
						cnt0 = cnt1 = 0;
					}
				}
			}
			cnt1++;
		}
	}

	cnt += std::min(cnt0, cnt1);

	return cnt;
    }
};
