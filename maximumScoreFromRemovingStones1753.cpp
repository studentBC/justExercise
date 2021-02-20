/*
(a+b+c)/2 covers situations: all 3 nums become 0 AND max <= (mid + min), i.e. [1,1,1]
a+b+c-max(a,b,c) only covers max > mid+min
*/
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a+b+c;
        return min(sum/2, sum-max(a,max(b,c)));
    }
};
//https://leetcode.com/problems/maximum-score-from-removing-stones/discuss/1053491/One-line-Python-O(1)
