function exemple(x: string | number, y: string | boolean) {
    if (x === y) {
        x.toUpperCase();
        y.toLowerCase()
    } else {
        console.log(x);
        console.log(y);
    }
}

exemple("first","first");

function printAll(strs: string | string[] | null) {
    if (strs !== null) {
        if (typeof strs === "object") {
            for (const str of strs) {
                console.log(str);
            }
        }
    } else if (typeof strs === "string") {
        console.log(strs);
    }
}

printAll("foo"); // 
printAll(["foo","bar"]) // foo bar

interface Container {
  value: number | null | undefined;
}
 
function multiplyValue(container: Container, factor: number) {
  // Remove both 'null' and 'undefined' from the type.
  if (container.value != null) {
    console.log(container.value);
 
    // Now we can safely multiply 'container.value'.
    container.value *= factor;
  }
}

multiplyValue({ value: 2 }, 3);

console.log(undefined !== null); // true
console.log(undefined != null); // false

