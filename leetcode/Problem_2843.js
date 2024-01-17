/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
var countSymmetricIntegers = function (low, high) {
  let count = 0;
  for (let i = low; i <= high; i++) {
    const string = i.toString();
    if (string.length % 2 !== 0) continue;
    let sumOne = 0;
    let sumTwo = 0;
    for (let j = 0; j < string.length; j++) {
      if (j < string.length / 2) {
        sumOne += parseInt(string[j]);
      } else {
        sumTwo += parseInt(string[j]);
      }
    }
    if (sumOne === sumTwo) count++;
  }
  return count;
};

console.log(countSymmetricIntegers(1, 100));
console.log(countSymmetricIntegers(1200, 1230));
