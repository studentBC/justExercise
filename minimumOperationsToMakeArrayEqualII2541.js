/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums1, nums2, k) {
    let sum = 0, ans = 0
    let num = []
    for (let i = 0; i < nums1.length; i++) {
        let tmp =(nums1[i]-nums2[i]);
        sum+=tmp
        if (tmp != 0) num.push(tmp)
    }
    if (sum != 0) return -1
    if (num.length && k == 0) return -1
    for (let i = 0; i < num.length; i++) {
        if (Math.abs(num[i]) < k || Math.abs(num[i])%k) return -1;
        if (num[i] > 0) {
            if (num[i]%k) return -1;
            ans+=num[i]/k
        }
    }
    return ans;
};
