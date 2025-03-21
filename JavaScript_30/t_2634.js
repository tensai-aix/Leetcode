/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var ret = new Array();
    for(var i = 0;i < arr.length;i++){
        if(fn(arr[i],i)){
            ret.push(arr[i]);
        }
    }
    return ret;
};