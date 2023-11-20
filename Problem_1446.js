/**
 * @param {string} s
 * @return {number}
 */

var maxPower = function(s) {
  max = 0
  count = 0
  letter = s[0]
  for(let i = 0; i < s.length; i++){
    if(letter !== s[i]){
      letter = s[i]
      if(max < count) max = count
      count = 0
    }
    count++
  }
  return max < count ? count : max
};

console.log(maxPower("cc"))