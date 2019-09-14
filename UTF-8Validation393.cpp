class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int leading = 0, count = 0;
        for (int i = 0; i < data.size(); i++) {
            count = 0;
            for (int j = 7; j > -1; j--) {
                if( (data[i]>>j) &1 ) {
                    count++;
                } else {
                    break;
                }
            }
            //cout << count <<" , ";
            if (count > 4) return false;
            if (count == 1) {
                if (leading) {
                    leading--;
                } else {
                    return false;
                }
            } else if (count == 0) {
                if (leading) return false;
                leading = 0;
            } else {
                if (leading == 0) leading = count-1;
                else return false;
            }
        }
        if(leading) return false;
        return true;
    }
};
//the fatest solution
auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n_bytes = 0;
        for (int num : data)
        {
        	if (n_bytes == 0)
        	{
        		int mask = 1 << 7;
        		while (num & mask)
        		{
        			++n_bytes;
        			mask >>= 1;
        		}
        		if (n_bytes == 0)
        			continue;
        		if (n_bytes == 1 || n_bytes > 4)
        			return false;
        	}
        	else
        	{
        		int mask1 = 1 << 7, mask2 = 1 << 6;
        		if (!(num & mask1) || (mask2 & num))
        			return false;
        		//--n_bytes;
        	}
        	--n_bytes;
        }
        return n_bytes == 0;
    }
};
