/**
 * @param {number[][]} image
 * @return {number[][]}
 */
var flipAndInvertImage = function (image) {
  for (const idx in image) {
    image[idx] = image[idx].reverse();
    for (let i = 0; i < image[idx].length; i++) {
      if (image[idx][i]) image[idx][i] = 0;
      else image[idx][i] = 1;
    }
  }
  return image
};

console.log(
  flipAndInvertImage([
    [1, 1, 0],
    [1, 0, 1],
    [0, 0, 0],
  ])
);
