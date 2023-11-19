/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var rowAndMaximumOnes = function (mat) {
  min = 0;
  index = 0;
  for (let i = 0; i < mat.length; i++) {
    count = 0;
    for (let j = 0; j < mat[i].length; j++) {
      if (mat[i][j] === 1) count++;
    }
    if (count > min) {
      min = count;
      index = i;
    }
  }
  return [index, min]
};

console.log(
  rowAndMaximumOnes([
    [0, 1],
    [0, 1],
  ])
);
