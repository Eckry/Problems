const fs = require("fs");

const numbers = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
const alph = [
  "a",
  "b",
  "c",
  "d",
  "e",
  "f",
  "g",
  "h",
  "i",
  "j",
  "k",
  "l",
  "m",
  "n",
  "o",
  "p",
  "q",
  "r",
  "s",
  "t",
  "u",
  "v",
  "w",
  "x",
  "y",
  "z",
];

fs.readFile("./log.txt", "utf8", (err, data) => {
  const formattedData = data.split("\n");
  let letter = false;
  let truers = 0;
  let falses = 0;
  let prev;
  for (let i = 0; i < formattedData.length; i++) {
    prev = null;
    letter = false;
    for (let j = 0; j < formattedData[i].length; j++) {
      if (!prev) prev = formattedData[i][j];
      if (prev > formattedData[i][j]) {
        falses++;
        prev = null;
        break;
      }
      if (letter && numbers.includes(formattedData[i][j])) {
        falses++;
        prev = null;
        break;
      }
      if (alph.includes(formattedData[i][j])) {
        letter = true;
      }
      prev = formattedData[i][j];
      if (j === formattedData[i].length - 1) {
        prev = null;
        truers++;
      }
    }
  }
  console.log(`submit ${truers}true${falses}false`);
});
