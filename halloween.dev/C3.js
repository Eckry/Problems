function findSafestPath(dream) {
  const n = dream.length;
  const m = dream[0].length;
  const memo = Array.from({ length: n }, () => Array(m).fill(null));

  function dp(i, j) {
    if (memo[i][j] !== null) return memo[i][j];

    if (i >= n - 1 && j >= m - 1) {
      return dream[i][j];
    }
    if (i === n - 1) {
      return (memo[i][j] = dp(i, j + 1) + dream[i][j]);
    }
    if (j === m - 1) {
      return (memo[i][j] = dp(i + 1, j) + dream[i][j]);
    }

    memo[i][j] = Math.min(
      dp(i + 1, j) + dream[i][j],
      dp(i, j + 1) + dream[i][j]
    );
    return memo[i][j];
  }

  const res = dp(0, 0);

  return res;
}
const d = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1],
];

console.table(findSafestPath(d));
