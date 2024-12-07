/**
 * @param {string[]} box
 * @returns {boolean} True if the gift is inside the box
 */
function inBox(box) {
  let boxIndex;

  outer: for (let y = 0; y < box.length; y++) {
    for (let x = 0; x < box[y].length; x++) {
      if (box[y][x] === "*") {
        boxIndex = [y, x];
        break outer;
      }
    }
  }

  if (!boxIndex) return false;
  const [y, x] = boxIndex;
  if (y === box.length - 1 || x === box[y].length - 1 || y === 0 || x === 0)
    return false;

  let counter = 0;

  for (let i = 0; i < box.length; i++) {
    if (box[i][x] === "#") counter++;
  }

  for (let i = 0; i < box[y].length; i++) {
    if (box[y][i] === "#") counter++;
  }
  return counter === 4;
}

console.log(
  inBox(["###", "#*#", "###"]), // ➞ true
  inBox(["####", "#* #", "#  #", "####"]), // ➞ true
  inBox(["#####", "#   #", "#  #*", "#####"]), // ➞ false
  inBox(["#####", "#   #", "#   #", "#   #", "#####"]) // ➞ false
);
