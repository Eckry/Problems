/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
  let integerToRoman = {
    M: 1000,
    CM: 900,
    D: 500,
    CD: 400,
    C: 100,
    XC: 90,
    L: 50,
    XL: 40,
    X: 10,
    IX: 9,
    V: 5,
    IV: 4,
    I: 1,
  };
  let romanNumber = "";
  for (let roman in integerToRoman) {
    let number = integerToRoman[roman]
    if (integerToRoman[roman] <= num) {
      x = Math.floor(num / number);
      num -= x * integerToRoman[roman];
      romanNumber += roman.repeat(x)
    }
  }
  return romanNumber;
};

console.log(intToRoman(3));
