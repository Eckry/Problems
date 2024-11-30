const fs = require("fs");

const data = fs.readFileSync("./res.txt", "utf8").split(",");

function isPrime(x) {
  for (let i = 2; i * i <= x; i++) if (x % i === 0) return false;
  return true;
}

let suspiciusNumbers = [];

data.forEach((string) => {
  let number = parseInt(string);
  if (isPrime(number)) {
    let temp = number;
    let sum = 0;

    while (temp) {
      sum += temp % 10;
      temp = Math.floor(temp / 10);
    }

    if (isPrime(sum)) {
      suspiciusNumbers.push(number);
    }
  }
});
console.log(suspiciusNumbers.length, suspiciusNumbers[2]);
