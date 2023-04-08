/**
 * @param {string[]} arr
 * @return {number}
 */
var ans = 0;
var len = [];
var go = function(start, num, cur, count, len) {
    ans = Math.max(count, ans);
    if (start == num.length) {
        return;
    }
    
    for (let i = start; i < num.length; i++) {
        //console.log(cur&num[i]);
        let tmp = cur&num[i]
        if (tmp == 0) {
            //console.log("c: ", i, count+len[i]);
            go(i+1, num, cur|num[i], count+len[i], len);
        }
    }
}
var get = function(num) {
    let sum = 0;
    let uni = new Set();
    for (let i = 0; i < num.length; i++) {
        if (uni.has(num[i]) == true) {
            //console.log("enter");
            return 0;
        }
        sum+= Math.pow(2, num[i].charCodeAt(0) - 'a'.charCodeAt(0));
        uni.add(num[i]);
    }
    return sum;
}
var maxLength = function(arr) {
    let num = [];
    let len = [];
    ans = 0;
    for (let i = 0; i < arr.length; i++) {
        let tmp = get(arr[i]);
        if(tmp) {
            num.push(tmp);
            len.push(arr[i].length);
        }
        //console.log(len.slice(-1));
    }
    // for (let i = 0; i < len.length; i++) {
    //     console.log(len[i]);
    // }
    go(0, num, 0, 0, len);
    return ans;
};
