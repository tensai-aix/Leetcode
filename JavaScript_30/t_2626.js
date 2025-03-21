/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var ret = init;
    for(var i = 0;i < nums.length;i++){
        ret = fn(ret,nums[i]);
    }
    return ret;
};