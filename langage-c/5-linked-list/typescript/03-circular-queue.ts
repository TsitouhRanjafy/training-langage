// This fixed-size (limite size) where the last position connect to the front
// Similare with SimpleQueue but it's with a fixed-size
import { LinkedList } from "./01-linked-list";
import { SimpleQueue } from "./02-simple-queue";


export class CircularyQueue<T>{
    private list: LinkedList<T>;
    private maxSize: number;

    
    constructor(maxSize: number) {
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
        return this.list.size() >= this.maxSize;
    }

    isEmpty(){
        return this.list.isEmpty();
    }

}
