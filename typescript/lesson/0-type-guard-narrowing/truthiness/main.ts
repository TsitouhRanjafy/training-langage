function getUsersOnlineMessage(numUsersOnline: number) {
    if (numUsersOnline) {
        return `There are ${numUsersOnline} online now`;
    }
    return "Nobody's here. :(";
}

/* FALSE

0
NaN
"" (the empty string)
0n (the bigint version of zero)
null
undefined

*/

console.log(Boolean("")); // false
console.log(Boolean("ok")); // true
console.log(Boolean(NaN)); // false

console.log(getUsersOnlineMessage(0));


