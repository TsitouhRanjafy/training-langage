const POSSIBLE_STR = "AZERTYUIOPQSDFGHJKLMWXCVBN"

const getRandomInt = (max: number): number => {
  return Math.floor(Math.random() * max);
}

const getRandomChar = (): string => {
  return POSSIBLE_STR.charAt(getRandomInt(26));
}


export class Robot {
  private _name: string;
  private static _reservedName: Set<string> = new Set<string>();


  constructor() {
    do {
      this._name = this.generateName();
    } while (Robot._reservedName.has(this._name));
    Robot._reservedName.add(this._name);
  }

  public get name(): string {
    return this._name;
  }

  public resetName(): void {
    do {
      this._name = this.generateName();
    } while (Robot._reservedName.has(this._name));
    Robot._reservedName.add(this._name);
  }

  public static releaseNames(): void {
    Robot._reservedName.clear();
  }

  private generateName(): string {
    return getRandomChar()+getRandomChar()+getRandomInt(10)+getRandomInt(10)+getRandomInt(10);
  }
}









