/**
 * @param {number} height - Height of the tree
 * @param {string} ornament - Symbol to draw
 * @returns {string} Drawn tree
 */
function createXmasTree(height, ornament) {
  const width = 2 * height - 1;
  let space = Array.from({ length: (width - 1) / 2 })
    .fill("_")
    .join("");
  let leash = ornament;

  let tree = "";

  for (let i = 1; i <= height; i++) {
    tree += `${space}${leash}${space}\n`;
    leash = `${ornament}${leash}${ornament}`;
    space = space.substring(1, space.length);
  }

  const logSpace = Array.from({ length: (width - 1) / 2 })
    .fill("_")
    .join("");
  const log = `${logSpace}#${logSpace}\n${logSpace}#${logSpace}`;

  const finalTree = tree + log;
  return finalTree;
}
console.log(createXmasTree(6, "@"));
