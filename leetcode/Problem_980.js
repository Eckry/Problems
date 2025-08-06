/**
 * @param {number[][]} grid
 * @return {number}
 */

let cnt = 0;

function findStart(grid) {
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (grid[i][j] == 1) return [i, j]
    }
  }
}

function dfs(row, col, grid, visited) {
  if (row >= grid.length || col >= grid[0].length || row < 0 || col < 0) return
  if (grid[row][col] === -1) return;
  if (visited[row][col] === 1) {
    return
  }
  if (grid[row][col] === 2) {
    for (let i = 0; i < grid.length; i++) {
      for (let j = 0; j < grid[i].length; j++) {
        if (grid[i][j] === 1 || grid[i][j] === 2 || grid[i][j] === -1) continue
        if (visited[i][j] === 0) {
          return;
        }
      }
    }
    cnt++;
    return
  }
  visited[row][col] = 1;

  dfs(row + 1, col, grid, visited)
  dfs(row - 1, col, grid, visited)
  dfs(row, col + 1, grid, visited)
  dfs(row, col - 1, grid, visited)
  visited[row][col] = 0;
}
var uniquePathsIII = function(grid) {

  let visited = Array.from({ length: grid.length }, () => Array.from({ length: grid[0].length }).fill(0))
  const [a, b] = findStart(grid)
  dfs(a, b, grid, visited)
  console.log(cnt)
};
const test = [
  [1, 0, 0, 0],
  [0, 0, 0, 0],
  [0, 0, 2, -1]
]
const test2 = [[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 2]]
const test3 = [[0, 1], [2, 0]]
uniquePathsIII(test)
cnt = 0;
uniquePathsIII(test2)
cnt = 0;
uniquePathsIII(test3)
