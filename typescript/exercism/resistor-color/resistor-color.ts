class Dictionnaire<K, V> {
  private map = new Map();
  private set = new Set();


  public addValue (key: K,value: V): void {
      this.map.set(key,value);
      this.set.add(value);
  }

  public getValue(key: K): V {
      return this.map.get(key)
  }

  public hasValue(value: V): boolean {
      return (this.set.has(value))? true : false;
  }

  public hasKey(key: K): boolean {
      return (this.map.has(key))? true : false;
  }

  public del(key: K): void {
    if (!this.hasKey(key)) return;
    const value: V = this.getValue(key);
    this.map.delete(key);
    this.set.delete(value)
  }

  public getSize(): number {
    return this.map.size;
  }
  
  public getKeys(): Array<V> {
    return Array.from(this.map.keys());
  }
}

const DIC_COLORS: Dictionnaire<string, number> = new Dictionnaire<string, number>();
DIC_COLORS.addValue('black', 0);
DIC_COLORS.addValue('brown', 1);
DIC_COLORS.addValue('red', 2);
DIC_COLORS.addValue('orange', 3);
DIC_COLORS.addValue('yellow', 4);
DIC_COLORS.addValue('green', 5);
DIC_COLORS.addValue('blue', 6);
DIC_COLORS.addValue('violet', 7);
DIC_COLORS.addValue('grey', 8);
DIC_COLORS.addValue('white', 9);

export const COLORS = [ 'black',  'brown', 'red',    'orange', 'yellow', 'green', 'blue',   'violet', 'grey',   'white' ]

export const colorCode = (colorName: string): number => {
  if (!DIC_COLORS.hasKey(colorName)) throw new Error(`color ${colorName} not found`);
  return DIC_COLORS.getValue(colorName);
}
