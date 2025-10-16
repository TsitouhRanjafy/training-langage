class Thing {
    _size: number = 0;

    get size(): number {
        return this._size;
    }

    set size(value: string | number | boolean) {
        let num: number = Number(value);

        // Don't allow NaN, Infinity, etc
        if (!Number.isFinite(num)) {
            this._size = 0;
            return;
        }
        this._size = num;
    }
}

class MyClass {
    [s: string]: boolean | ((s: string) => boolean);

    check(s: string) {
        return this[s] as boolean;
    }
}

const a = new MyClass();
a["a"] = true;
a["moi"] = false;
console.log(a.check("a"));
console.log(a.check("moi"));

