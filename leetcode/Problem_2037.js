/**
 * @param {number[]} seats
 * @param {number[]} students
 * @return {number}
 */
var minMovesToSeat = function (seats, students) {
  seats.sort((a, b) => a - b);
  students.sort((a, b) => a - b);

  let counter = 0;

  for (const idx in students) {
    counter += Math.abs(students[idx] - seats[idx]);
  }

  return counter;
};

console.log(minMovesToSeat([2, 2, 6, 6], [1, 3, 2, 6]));
