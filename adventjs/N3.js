/**
 * @param {{ name: string, quantity: number, category: string }[]} inventory
 * @returns {object} The organized inventory
 */
function organizeInventory(inventory) {
  return inventory.reduce((organized, { name, quantity, category }) => {
    organized[category] ??= {};
    organized[category][name] ??= 0;

    organized[category][name] += quantity;

    return organized;
  }, {});
}

console.log(
  organizeInventory([
    { name: "doll", quantity: 5, category: "toys" },
    { name: "car", quantity: 3, category: "toys" },
    { name: "ball", quantity: 2, category: "sports" },
    { name: "car", quantity: 2, category: "toys" },
    { name: "racket", quantity: 4, category: "sports" },
  ])
);
