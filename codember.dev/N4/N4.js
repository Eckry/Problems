const fs = require("fs");

let finalres = "";

try {
  // Read the file synchronously
  const data = fs.readFileSync("./network.txt", "utf8");
  const formattedData = JSON.parse(data);
  const graph = {};

  function getRoot(x) {
    if (!graph[x]) return x;
    return getRoot(graph[x]);
  }

  for (let i = 0; i < formattedData.length; i++) {
    const [a, b] = formattedData[i];
    const rootA = getRoot(a);
    const rootB = getRoot(b);
    if (rootA === rootB) continue;
    else if (rootA === a) graph[a] = b;
    else if (rootB === b) graph[b] = a;
    else graph[rootB] = a;
  }

  const visited = {};
  const networks = {};
  let net = new Set();

  for (let i = 0; i < Object.keys(graph).length; i++) {
    const root = getRoot(Object.keys(graph)[i]);

    if (networks[root]) net = networks[root];
    else networks[root] = new Set();

    let j = parseInt(Object.keys(graph)[i]);

    while (j) {
      visited[j] = true;
      net.add(j);
      j = graph[j];
    }
    networks[root] = net;

    net = new Set();
  }

  const networksArr = Object.values(networks);
  const res = [];

  for (let i = 0; i < networksArr.length; i++) {
    if (networksArr[i].size > 2) continue;
    res.push(...Array.from(networksArr[i]));
  }
  finalres = res.join(",");

  fs.writeFileSync("res.txt", JSON.stringify(finalres), "utf8");
  console.log("File saved successfully!");
} catch (err) {
  console.error("An error occurred:", err.message);
}
