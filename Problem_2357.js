/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function (nums) {
  nums.sort((a, b) => a - b);
  let count = 0
  let sum = 0
  for(let i = 0; i < nums.length && nums[nums.length - 1] >= 0; i++){
    if(nums[i] - sum <= 0) continue;
    sum += nums[i] - sum
    nums[nums.length - 1] -= sum - nums[i]
    count++
  }
  return count;
};

// console.log(minimumOperations([0]));
// console.log(minimumOperations([1, 5, 0, 3, 5]));
console.log(minimumOperations([1,2,3,5]));
