function findTheKiller(whisper, suspects) {
  let l = whisper.length;
  if (whisper[l - 1] === "$") {
    l--;
    suspects = suspects.filter(
      (suspect) => suspect.length === l && suspect.length >= l
    );
  } else {
    suspects = suspects.filter((suspect) => suspect.length >= l);
  }

  const m = new Set(suspects);

  whisper = whisper.replace(/~/gi, ".");
  whisper = whisper + ".*";
  const regex = new RegExp(whisper, "i");
  for (let i = 0; i < suspects.length; i++) {
    if (!regex.test(suspects[i])) {
      m.delete(suspects[i]);
    }
  }

  return `${Array.from(m)}`;
}

console.log(
  findTheKiller("d~~~~~a", [
    "Dracula",
    "Daaaaaaaa",
    "Freddy Krueger",
    "Jason Voorhees",
    "Michael Myers",
  ])
);
// Expected:
// "Dracula"
