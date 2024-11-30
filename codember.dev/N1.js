function solve(number, op) {
  const numbers = number.split("").map((m) => parseInt(m));
  let j = 0;
  for (let i = 0; i < op.length; i++) {
    const letter = op[i];
    switch (letter) {
      case "U":
        if (numbers[j] === 9) numbers[j] = 0;
        else numbers[j]++;
        break;
      case "D":
        if (numbers[j] === 0) numbers[j] = 9;
        else numbers[j]--;
        break;
      case "L":
        if (j === 0) j = numbers.length - 1;
        else j--;
        break;
      case "R":
        if (j === numbers.length - 1) j = 0;
        else j++;
        break;
    }
  }
  return numbers.join("");
}

console.log(solve("528934712834", "URDURUDRUDLLLLUUDDUDUDUDLLRRRR"));
