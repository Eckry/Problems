const fs = require("fs");

fs.readFile("./trace.txt", "utf8", (err, data) => {
  const formattedData = data.split("\n");
  let position = 0;
  let steps = 0;
  let lastLine = 0;
  for (let i = 0; i < formattedData.length; i++) {
    const present = formattedData[i].split(" ");
    lastLine = 0;
    while (position >= 0 && position < present.length) {
      const x = present[position];
      present[position] = parseInt(x) + 1;
      position += parseInt(x);
      steps++;
      lastLine++;
    }
    position = 0;
  }
  console.log(steps, lastLine);
});
