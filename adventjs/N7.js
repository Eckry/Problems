/** @param {string} packages with parentheses
 *  @returns {string} Fixed and sorted packages
 */
function fixPackages(packages) {
  const stack = [];
  packages = packages.split("");

  for (let i = 0; i < packages.length; i++) {
    if (packages[i] === "(") {
      stack.push(i);
    } else if (packages[i] === ")") {
      const start = stack.pop();
      const substr = packages.slice(start, i + 1).reverse();
      packages.splice(start, i - start + 1, ...substr);
    }
  }

  return packages.join("").replace(/\(|\)/g, "");
}

//console.log(fixPackages("a(cb)de"));
console.log(fixPackages("a(b(cd)e)f")); // agdefcbh
// abcdef // abdcef // aecdbf
