// A priority queue processes items based on their priority, not their order of arrival.
import { LinkedList, NodeItem } from "./01-linked-list";


/**
 * Interface for an element with priority
 */
interface PriorityItem<T> {
    value: T;
    priority: number;
}

export class PriorityQueue<T> {
    private list: LinkedList<PriorityItem<T>>;
    private maxSize?: number;

    constructor(maxSize?: number) {
        this.list = new LinkedList<PriorityItem<T>>;
        this.maxSize = maxSize;
    }

    enqueue(value: T, priority: number): void{
        if (this.isFull()) throw new Error("Priority queue is full");
        
        const newItem: PriorityItem<T> = { value, priority };
        if (this.isEmpty()) {
            this.list.prepend(newItem);
            return;
        }

        let current = this.list["head"];
        let count = 0;
        while(
            current &&
            current.value.priority >= priority &&
            count < this.size()
        ) {
            current = current.next;
            count++;
        }

        if(count == this.list.size()){
            this.list.append(newItem)
        } else {
            const newNode = new NodeItem(newItem);
            newNode.next = current;
            newNode.prev = current!.prev;
            if (current!.prev){
                current!.prev.next = newNode;
            } else {
                this.list["head"] = newNode;
            }
            current!.prev = newNode;
            if (current == this.list["head"]) {
                this.list["head"] = newNode;
            }
            this.list["tail"]!.next = this.list["head"];
            this.list["head"]!.prev = this.list["tail"];
            this.list["currentSize"]++;
        }
    }

    dequeue(): T | undefined {
        return this.list.deleteHead()?.value;
    }

    getFront(): T | undefined {
        return this.list.getHead()?.value;
    }

    getRear(): T | undefined {
        return this.list.getTail()?.value;
    }

    size(): number {
        return this.list.size();
    }

    isFull(): boolean {
        return this.maxSize !== undefined && this.maxSize == this.list.size();
    }

    isEmpty(): boolean {
        return this.list.isEmpty();
    }
}
