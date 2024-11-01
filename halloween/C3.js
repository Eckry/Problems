function findSafestPath(dream) {
  const n = dream.length;
  const m = dream[0].length;
  function dp(i, j) {
    if (i >= n - 1 && j >= m - 1) {
      return dream[i][j];
    }
    if (i === n - 1) return dp(i, j + 1) + dream[i][j];
    if (j === m - 1) return dp(i + 1, j) + dream[i][j];
    return Math.min(dp(i + 1, j) + dream[i][j], dp(i, j + 1) + dream[i][j]);
  }

  return dp(0, 0);
}

const d = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1],
];

console.log(findSafestPath(d));
