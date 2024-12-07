/**
 * @param {{ type: 'I' | 'R', size: number }[]} shoes
 * @returns {number[]} Available shoes
 */
function organizeShoes(shoes) {
  const sizeMap = {};

  for (const { type, size } of shoes) {
    sizeMap[size] ??= { I: 0, R: 0 };
    sizeMap[size][type]++;
  }

  const result = [];
  const sizesFound = Object.keys(sizeMap).map((number) => parseInt(number));

  for (const size of sizesFound) {
    const pairs = Math.min(sizeMap[size].I, sizeMap[size].R);
    result.push(...Array(pairs).fill(size));
  }

  return result;
}

console.log(
  organizeShoes([
    { type: "I", size: 38 },
    { type: "R", size: 38 },
    { type: "R", size: 42 },
    { type: "I", size: 41 },
    { type: "I", size: 42 },
  ])
);
