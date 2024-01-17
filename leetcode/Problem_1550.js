/**
 * @param {number[]} arr
 * @return {boolean}
 */
var threeConsecutiveOdds = function (arr) {
  count = 0;
  for (const elem of arr) {
    if (elem % 2) {
      count++;
      if (count === 3) return true;
    } else count = 0;
  }
  return false;
};

console.log(threeConsecutiveOdds([2, 6, 4, 1]));
