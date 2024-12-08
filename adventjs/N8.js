/**
 * @param {number[]} indices - The reno indices
 * @param {number} length - The length of the race
 * @returns {string} The reno race
 */
function drawRace(indices, length) {
  const res = [];
  for (let i = 0; i < indices.length; i++) {
    const shift = " ".repeat(indices.length - 1 - i);
    const goal = ` /${i + 1}`;
    let position = indices[i];

    if (position < 0) position = length + position;
    const track = `${"~".repeat(position)}${position ? "r" : ""}`.padEnd(
      length,
      "~"
    );
    res.push(shift + track + goal);
  }
  return res.join("\n");
}

console.log(drawRace([0, 5, -3], 10));
/*
  ~~~~~~~~~~ /1
 ~~~~~r~~~~ /2
~~~~~~~r~~ /3
*/

console.log(drawRace([2, -1, 0, 5], 8));
/*
   ~~r~~~~~ /1
  ~~~~~~~r /2
 ~~~~~~~~ /3
~~~~~r~~ /4
*/

console.log(drawRace([3, 7, -2], 12));
/*
  ~~~r~~~~~~~~ /1
 ~~~~~~~~r~~~ /2
~~~~~~~~~r~~ /3
*/
