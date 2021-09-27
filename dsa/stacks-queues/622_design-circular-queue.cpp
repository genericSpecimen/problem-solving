class MyCircularQueue {
private:
    vector<int> queue;
    int front, rear, size;
public:
    MyCircularQueue(int k) : front{-1}, rear{-1}, size{k} {
        queue.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        if (isEmpty()) {
            front = (front + 1) % size;
        }
        
        rear = (rear + 1) % size;
        queue[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (!isEmpty()) {
            if (front == rear) {
                // single element in the queue
                // after dequeue-ing, queue will be empty 
                front = -1;
                rear = -1;
                return true;
            }
            // otherwise simply increment front
            // the leftover spaces will be used
            // by enqueue using (rear+1) % size
            front = (front + 1) % size;
            return true;
        }
        return false;
    }
    
    int Front() {
        if (!isEmpty()) {
            return queue[front];
        }
        return -1;
    }
    
    int Rear() {
        if (!isEmpty()) {
            return queue[rear];
        }
        return -1;
    }
    
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }
    
    bool isFull() {
        return ((rear + 1) % size == front);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
