/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function (x, y) {
  let count = 0;
  while (x > 0 || y > 0) {
    count += (x & 1) ^ (y & 1);
    x >>= 1;
    y >>= 1;
  }
  return count;
};

// console.log(hammingDistance(1, 4));
// console.log(hammingDistance(1501377268, 258791155));
// console.log(hammingDistance(0, 1));
// console.log(hammingDistance(3, 1));
console.log(hammingDistance(4, 2));
