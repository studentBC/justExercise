class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>number;
        bitset<21>temp;
        for (int i = 0 ; i < k; i++) {
            if (s[i] == '1') temp.set(i,1);
        }
        number.insert(temp.to_string());
        int end = k-1;
        for (int i = k, j = 0; i < s.size(); i++, j++) {
            temp>>=1;
            temp.set(end, s[i]-'0');
            number.insert(temp.to_string());
        }
        return number.size() == pow(2,k);
    }
};
//the 76ms solution
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n <= (1 << k)) return false;
        vector<uint32_t> m(1 << max(k - 5, 0));
        uint32_t cur = 0U;
        for (int i = 0; i < k; i++) {
            cur |= (s[--n] - '0') << i;
        }
        m[cur >> 5] |= 1 << (cur & 0x1F);
        while (n) {
            cur |= (s[--n] - '0') << k;
            cur >>= 1;
            m[cur >> 5] |= 1 << (cur & 0x1F);
        }
        if (k < 5) return m[0] == ((1U << (1U << k)) - 1U);
        for (auto i : m) if (i != 0xFFFFFFFFU) return false;
        return true;
    }
};

static const auto fast = []() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;
} ();
