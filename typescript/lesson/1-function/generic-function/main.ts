function map<Input, Output>(arr: Input[], fn: (arg: Input) => Output) {
    return arr.map(fn);
}

const arrayStr: string[] = ["1", "2", "3", "4"];
const parsed = map(arrayStr, (n) => parseInt(n));

console.log(parsed); // Integer Array
console.log(arrayStr); // string Array


/* Generic Constraint */
function longest<Type extends { length: number }>(a: Type, b: Type) {
    if (a.length >= b.length) {
        return a;
    } else {
        return b;
    }
}

const longerArray = longest([1, 2], [1, 2, 3]); // longerArray is of type 'number[]'
const longerString = longest("alice", "bob"); // longerString is of type 'alice' | 'bob'
const notOK = longest(10, 100); // Error! Numbers don't have a 'length' property


interface Lengthwise {
  length: number;
}

function loggingIdentity<T extends Lengthwise>(arg: T): T {
  // Now we know it has a .length property, so no more error
  console.log(arg.length);

  return arg;
}

loggingIdentity(3); // Error, number doesn't have a .length property
loggingIdentity({ length: 10, value: 3 }); // OK