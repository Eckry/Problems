function findSafestPath(dream) {
  const n = dream.length;
  const m = dream[0].length;
  const mem = Array.from({ length: n }, () => Array(m).fill(null));
  function dp(i, j) {
    if (i === n - 1 && j === m - 1) {
      return dream[i][j];
    }
    if (mem[i][j] !== null) return mem[i][j];

    if (i === n - 1) mem[i][j] = dp(i, j + 1) + dream[i][j];
    else if (j === m - 1) mem[i][j] = dp(i + 1, j) + dream[i][j];
    else
      mem[i][j] = Math.min(
        dp(i + 1, j) + dream[i][j],
        dp(i, j + 1) + dream[i][j]
      );
    return mem[i][j];
  }
  dp(0, 0);

  return mem[0][0];
}

const d = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1],
];

console.table(findSafestPath(d));
