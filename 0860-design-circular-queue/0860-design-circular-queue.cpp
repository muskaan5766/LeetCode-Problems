class MyCircularQueue {
    vector<int> queue;
    int front = 0, rear = 0, size = 0, capacity;
public:
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(k);
    }
    bool enQueue(int value) {
        if (size == capacity) return false;
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        ++size;
        return true;
    }
    bool deQueue() {
        if (size == 0) return false;
        front = (front + 1) % capacity;
        --size;
        return true;
    }
    int Front() {
        return size == 0 ? -1 : queue[front];
    }
    int Rear() {
        return size == 0 ? -1 : queue[(rear + capacity - 1) % capacity];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
};