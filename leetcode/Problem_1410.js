/**
 * @param {string} text
 * @return {string}
 */
var entityParser = function(text) {
  let parser = {
    "&quot;": `"`,
    "&apos;": `'`,
    "&amp;": `&`,
    "&gt;": `>`,
    "&lt;": `<`,
    "&frasl;": `/`
  }
  const regExp = new RegExp(/&quot;|&apos;|&amp;|&gt;|&lt;|&frasl;/, "g");
  text = text.replace(regExp, (string) => parser[string])
  return text
};

// console.log(entityParser("&amp; &amp; is an HTML entity but &ambassador; is not."))
console.log(entityParser("&amp;gt;"))