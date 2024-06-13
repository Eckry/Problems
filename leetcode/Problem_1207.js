/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function (arr) {
  let counter = {};
  for (const number of arr) {
    if (!counter[number]) counter[number] = 1;
    else counter[number]++;
  }

  const set = new Set(Object.values(counter));
  return Object.values(counter).length === set.size;
};

console.log(uniqueOccurrences([1, 2, 2, 1, 1, 3]));
console.log(uniqueOccurrences([1, 2]));
console.log(uniqueOccurrences([-3, 0, 1, -3, 1, 1, 1, -3, 10, 0]));
