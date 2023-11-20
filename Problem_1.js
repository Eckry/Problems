/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let checked = new Map()
    for(let idx in nums){
      numberNeeded = target - nums[idx] 
      if(checked[nums[idx]]) return [checked[nums[idx]], idx]
      checked[numberNeeded] = idx
    }
};

console.log(twoSum([2,7,11,15], 9));