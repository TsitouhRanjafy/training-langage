// FIFO (add item to the back and remove them into the front)
import { LinkedList } from "./01-linked-list";

export class SimpleQueue<T> {
    private list: LinkedList<T>;
    private maxSize?: number;


    constructor(maxSize?: number){
        this.list = new LinkedList<T>();
        this.maxSize = maxSize;
    }

    enqueue(item: T): void{
        if (this.isFull()) throw new Error("Queue is full");
        this.list.append(item);
    }

    dequeue(): T | undefined {
        return this.list.deleteHead();
    }

    getFront(): T | undefined {
        return this.list.getHead();
    }

    getRear(): T | undefined {
        return this.list.getTail();
    }

    size(): number {
        return this.list.size();
    }

    isFull(): boolean{
        return this.maxSize !== undefined && this.list.size() >= this.maxSize;
    }

    isEmpty(){
        return this.list.isEmpty();
    }
}

const newSQ: SimpleQueue<number> = new SimpleQueue<number>(4);



