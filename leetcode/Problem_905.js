/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function (nums) {
  return nums.sort(a => (a % 2 ? 1 : -1));
};

console.log(sortArrayByParity([3, 1, 2, 4]));
