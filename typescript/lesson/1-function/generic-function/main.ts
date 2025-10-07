function map<Input, Output>(arr: Input[], fn: (arg: Input) => Output) {
    return arr.map(fn);
}

const arrayStr: string[] = ["1", "2", "3", "4"];
const parsed = map(arrayStr, (n) => parseInt(n));

console.log(parsed); // Integer Array
console.log(arrayStr); // string Array


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