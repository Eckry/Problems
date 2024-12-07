/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  const n = s.length;
  const dp = new Array(n).fill().map(() => new Array(n).fill(0));
  let max = s[0];

  for (let i = 0; i < n; i++) {
    dp[i][i] = s[i];
    if (i < n - 1)
      if (s[i] === s[i + 1]) {
        dp[i + 1][i] = `${s[i]}${s[i + 1]}`;
        if (max.length < dp[i + 1][i].length) max = dp[i + 1][i];
      }
  }

  for (let k = 2; k < n; k++) {
    for (let i = k, j = 0; i < n; i++, j++) {
      if (dp[i - 1][j + 1] && s[i] === s[j]) {
        dp[i][j] = `${s[i]}${dp[i - 1][j + 1]}${s[j]}`;
        if (max.length < dp[i][j].length) max = dp[i][j];
      } else dp[i][j] = 0;
    }
  }

  return max;
};

console.log(longestPalindrome("babadda"));
console.log(longestPalindrome("cbbd"));
console.log(longestPalindrome("a"));
console.log(longestPalindrome("ac"));
console.log(longestPalindrome("ccc"));
