// A double-ended queue (deque) lets you add or remove items from both the front and the back.
import { LinkedList } from "./01-linked-list";


export class Deque<T> {
    private list: LinkedList<T>;
    private maxSize?: number;

    constructor(maxSize?:number){
        this.list = new LinkedList<T>();
        this.maxSize = maxSize;
    }


    enqueueFront(item: T): void {
        if (this.isFull()) throw new Error("Deque is full");
        this.list.prepend(item);
    }


    enqueueRear(item: T): void {
        if (this.isFull()) throw new Error("Deque is full");
        this.list.append(item);
    }

    dequeueFront(): T | undefined {
        return this.list.deleteHead();
    }

    dequeueRear(): T | undefined {
        return this.list.deleteTail();
    }

    getFront(): T | undefined {
        return this.list.getHead();
    }


    getRear(): T | undefined {
        return this.list.getTail();
    }

    isEmpty(): boolean {
        return this.list.isEmpty();
    }

    size(): number {
        return this.list.size();
    }

    isFull() :boolean {
        return this.maxSize !== undefined && this.maxSize <= this.list.size(); 
    }
}

