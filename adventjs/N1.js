/**
 * @param {number[]} gifts - The array of gifts to prepare
 * @returns {number[]} An array with the prepared gifts
 */
function prepareGifts(gifts) {
  // Code here
  const set = new Set(gifts);
  const res = Array.from(set);
  return res.sort((a, b) => a - b);
}

console.log(prepareGifts([5, 5, 5, 5]));
console.log(prepareGifts([3, 3, 1, 2]));
