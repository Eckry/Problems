function createMagicPotion(potions, target) {
  const m = new Map();
  for (let i = 0; i < potions.length; i++) {
    const r = target - potions[i];
    if (m.has(r)) {
      return [m.get(r), i];
    }
    m.set(potions[i], i);
  }
  return undefined;
}
