type GreetFunction = (a: string) => void;

function greeter(fn: GreetFunction) {
    fn("Salut");
}

function print(str: string) {
    console.log(str);
}

greeter(print);


type DescribableFunction = {
    description: string;
    (someArg:  number): boolean;
}

function doSomething(fn: DescribableFunction): void {
    console.log(fn.description + " returned " + fn(6));
}

function myFunc(someArg: number): boolean {
    return someArg > 3;
}

myFunc.description = "default description";
myFunc.level = 3; // no impact for doSomething function

console.log(myFunc);
doSomething(myFunc);