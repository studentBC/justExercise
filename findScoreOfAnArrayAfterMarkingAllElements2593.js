/**
 * @param {number[]} nums
 * @return {number}
 */
var findScore = function(nums) {
    let sorted = [];
    for (let i = 0; i < nums.length; i++) {
        sorted.push([nums[i], i]);
    }
    sorted = sorted.sort((a,b)=> {
            if (a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        }
    );
    let used = new Set();
    let ans = 0;
    for (let i = 0; i < sorted.length; i++) {
        if (used.has( sorted[i][1])) continue;
        ans+=sorted[i][0];
        used.add(sorted[i][1]+1);
        used.add(sorted[i][1]-1);
    }
    return ans;
};
