/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function (numBottles, numExchange) {
  emptyBottles = 0;
  initialBottles = numBottles
  count = 0
  do {
    emptyBottles += numBottles
    count += numBottles
    numBottles = Math.floor(emptyBottles / numExchange)
    emptyBottles -= numExchange * numBottles
  } while (emptyBottles + numBottles >= numExchange);
  return count + numBottles
};

console.log(numWaterBottles(9, 3));
console.log(numWaterBottles(15, 4));
