/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {  
    var map = new Map();  // 创建一个 Map 来存储缓存的结果  
    return function(...args) {  // 返回一个新函数，使用剩余参数语法来获取所有参数  
        let k = args.join("-");  // 将参数数组转换成字符串作为键  
        if (!map.has(k)) {  // 检查这个键是否已经在缓存中  
            map.set(k, fn(...args));  // 如果没有，调用原函数并将结果存入缓存  
        }  
        return map.get(k);  // 返回缓存的结果  
    }  
}  


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 *//**
 * @param {Function} fn
 * @return {Function}
 */
