class Solution {
public:
    int count_bits(int x)
    {
        x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
        x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
        x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
        x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
        x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
        return x;
    }
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int temp;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                temp = nums[i]^nums[j];
                ans+=count_bits(temp);
            }
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) 
    {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) 
        {
            int cnt = 0;
            for (int num : nums) 
            {
                if (num & (1 << i)) 
                    ++cnt;
            }
            res += cnt * (n - cnt);
        }
        return res;
    }
};
//explantion
/*
The total Hamming distance is constructed bit by bit in this approach.

Let's take a series of number: a1, a2, a3,..., an

Just think about all the Least Significant Bit (LSB) of a(k) (1 ≤ k ≤ n).

How many Hamming distance will they bring to the total?

If a pair of number has same LSB, the total distance will get 0.

If a pair of number has different LSB, the total distance will get 1.

For all number a1, a2, a3,..., a(n), if there are p numbers have 0 as LSB (put in set M), and q numbers have 1 for LSB (put in set N).

There are 2 situations:

Situation 1. If the 2 number in a pair both comes from M (or N), the total will get 0.

Situation 2. If the 1 number in a pair comes from M, the other comes from N, the total will get 1.

Since Situation 1 will add NOTHING to the total, we only need to think about Situation 2

How many pairs are there in Situation 2?

We choose 1 number from M (p possibilities), and 1 number from N (q possibilities).

The total possibilities is p × q = pq, which means

The total Hamming distance will get pq from LSB.
If we remove the LSB of all numbers (right logical shift), the same idea can be used again and again until all numbers becomes zero
*/
