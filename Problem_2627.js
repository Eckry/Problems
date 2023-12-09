/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
  let time
  return function(...args) {
      clearTimeout(time);
      time = setTimeout(() => {
          fn(...args)
      }, t)
  }
};