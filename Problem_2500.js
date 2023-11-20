/**
 * @param {number[][]} grid
 * @return {number}
 */
var deleteGreatestValue = function (grid) {
  sum = 0;
  for (let i = 0; i < grid.length; i++) {
    grid[i].sort((a, b) => b - a);
  }

  let rowLength = grid[0].length;
  for (let i = 0; i < rowLength; i++) {
    maximum = 0;
    for (let j = 0; j < grid.length; j++) {
      if (grid[j][i] > maximum) maximum = grid[j][i];
    }
    sum += maximum;
  }
  return sum;
};

console.log(
  deleteGreatestValue([
    [1, 2, 4],
    [3, 3, 1],
  ])
);
