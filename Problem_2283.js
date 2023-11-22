/**
 * @param {string} num
 * @return {boolean}
 */
var digitCount = function (num) {
  const count = {
    0: 0,
    1: 0,
    2: 0,
    3: 0,
    4: 0,
    5: 0,
    6: 0,
    7: 0,
    8: 0,
    9: 0,
  };
  for (let i = 0; i < num.length; i++) count[num[i]]++;
  for (let number in num) if (num[number] != count[number]) return false;
  return true;
};

console.log(digitCount("1210"));
