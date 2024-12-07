function createFrame(names) {
  // Code here

  const namesOrdered = names.toSorted((a, b) => b.length - a.length);
  const longest = namesOrdered[0].length;
  const topBorder = Array.from({ length: longest + 4 })
    .fill("*")
    .join("");
  let res = "";
  for (let i = 0; i < names.length; i++) {
    const space = Array.from({ length: longest - names[i].length + 1 })
      .fill(" ")
      .join("");
    res += `* ${names[i]}${space}*\n`;
  }

  return `${topBorder}\n${res}${topBorder}`;
}

console.log(createFrame(["midu", "madeval", "educalvolpz"]));
