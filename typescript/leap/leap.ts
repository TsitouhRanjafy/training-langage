export function isLeap(year: number): boolean {
  if ((year % 4) !== 0) 
    return false;
  return ((year % 100) === 0) === ((year % 400) === 0);
}

// export function isLeap(year: number): boolean {
//   return year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0)
// }
