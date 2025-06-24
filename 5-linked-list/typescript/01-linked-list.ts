/**
 * Node for doubly linked list 
 */


export class NodeItem<T> {
    prev: NodeItem<T> | null = null;
    value: T;
    next: NodeItem<T> | null = null;

    constructor(value: T){
        this.value = value;
    }
}

/**
 * Cirulary Doubly Linked List
 */

export class LinkedList<T> {
    private head: NodeItem<T> | null = null;
    private tail: NodeItem<T> | null = null;
    private currentSize: number = 0;

    /**
     * Add a new node to the front of the list
     * @param value The value to add
     */
    prepend(value: T):void {
        const newNode: NodeItem<T> = new NodeItem<T>(value);
        if (this.currentSize == 0){
            this.head = newNode;
            this.tail = newNode;
            this.currentSize += 1;
        } else {
            newNode.next = this.head;
            newNode.prev = this.tail;
            this.tail!.next = newNode;
            this.head!.prev = newNode;
            this.tail = newNode;
        }
        this.currentSize++;
    }


    /**
     * Add new node to the back of the list 
     * @param value The value to add
     */

    append(value: T): void{
        const newNode: NodeItem<T> = new NodeItem<T>(value);
        if(this.currentSize == 0  ){
            this.head = newNode;
            this.tail = newNode;
        } else {
            newNode.next = this.head;
            newNode.prev = this.tail;
            this.head!.prev = newNode;
            this.tail!.next = newNode;
            this.head = newNode
        }
        this.currentSize++;
    }

    /**
     * Remove and return value form front of the list
     * @returns The value at the head or undefinied if empty
     */
    deleteHead(): T | undefined{
        if (this.currentSize == 0){
            return undefined;
        }

        const value = this.head!.value;
        if (this.currentSize == 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.head!.next!.prev = this.tail;
            this.tail!.next = this.head;
            this.head = this.head!.next;
        }
        this.currentSize--;
        return value;
    }


    deleteTail(): T | undefined {
        if (this.currentSize == 0){
            return undefined;
        }
        const  value = this.tail!.value;
        if (this.currentSize == 1){
            this.head = null;
            this.tail = null;
        } else {
            this.tail!.prev!.next = this.head;
            this.head!.prev = this.tail!.next;
            this.tail = this.tail!.prev;
        }
        this.currentSize--;
        return value;
    }

    getHead(): T | undefined {
        return this.head?.value;
    }

    getTail(): T | undefined {
        return this.tail?.value;
    }

    size(): number {
        return this.currentSize;
    }

    isEmpty(): boolean {
        return this.currentSize == 0;
    }
}



