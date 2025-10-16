class Point {
    x: number = 0;
    y: number = 0;

    constructor(x: number, y: number) {}
    constructor(xy: string) {}
    constructor(x: string | number, y: number = 0) {
        // logic here
    }
}