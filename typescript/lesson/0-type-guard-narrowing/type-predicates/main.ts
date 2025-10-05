function isString(value: unknown): value is string {
    return typeof value === 'string'
}

function isStringBad(value: unknown): boolean {
    return typeof value === 'string';
}

const value: unknown = "hello";
if (isStringBad(value)) {
    console.log(value.toLowerCase()); // Error: 'value'  est encore 'unknow'
}

if (isString(value)) {
    console.log(value.toLowerCase()); // OK: 'value' is a 'string'
}



