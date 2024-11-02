function battleHorde(zombies, humans) {
  let r = 0;
  for (let i = 0; i < zombies.length; i++) {
    r = humans[i] - zombies[i] + r;
  }

  if (r !== 0) return `${Math.abs(r)}${r > 0 ? "h" : "z"}`;

  return "x";
}
