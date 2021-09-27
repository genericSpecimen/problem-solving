#include <iostream>
#include <limits>
#include <vector>
#include <stdexcept>

class Queue {
private:
    std::vector<int> queue;
    int front, rear;
public:
    Queue() : front{-1}, rear{-1} {}
    bool isEmpty() {
        return (
            front == -1 ||
            front > rear
        );
    }
    
    void enqueue(int elem) {
        if (isEmpty()) {
            queue.push_back(elem);
            front = 0;
            rear = 0;
        } else {
            queue.push_back(elem);
            rear++;
        }
    }
    
    int dequeue() {
        if (isEmpty()) {
            throw std::length_error("dequeue(): queue is empty");
        } else {
            int felem = frontElem();
            front++;
            return felem;
        }
    }
    
    int frontElem() {
        if (front >= 0 && front < queue.size()) {
            return queue[front];
        }
        return std::numeric_limits<int>::min();
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    while (!q.isEmpty()) {
        std::cout << q.dequeue() << std::endl;
    }
    
    std::cout << std::boolalpha << q.isEmpty() << std::endl;
    
    std::cout << q.dequeue() << std::endl;
}

         f  r
10 20 30 40 50 
