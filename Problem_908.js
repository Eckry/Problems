/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var smallestRangeI = function (nums, k) {
  [max, min] = [Math.max(...nums), Math.min(...nums)];
  if (max === min || max - 2 * k <= min) return 0;
  return max - min - 2 * k;
};

console.log(smallestRangeI([1, 3, 6], 3));
console.log(smallestRangeI([0, 10], 2));
console.log(smallestRangeI([1], 0));
console.log(smallestRangeI([3, 1, 10], 4));
