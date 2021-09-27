#include <iostream>
#include <vector>
#include <limits>

/*
class Stack {
private:
    std::vector<int> data;
public:
    bool isEmpty() {
        return data.empty();
    }

    void push(int x) {
        data.push_back(x);
    }
    
    int top() {
        if (isEmpty()) {
            throw std::length_error("cannot get top element: stack is empty");
        }
        return data.back();
    }
    
    bool pop() {
        if (isEmpty()) return false;
        data.pop_back();
        return true;
    }
    
    // naive max api
    int max() {
        if (isEmpty()) {
            throw std::length_error("cannot get max element: stack is empty");
        }
        int MAX = std::numeric_limits<int>::min();
        for (int elem : data) {
            if (elem > MAX) MAX = elem;
        }
        return MAX;
    }
    
    void printStack() {
        std::cout << "[";
        for (auto elem : data) {
            std::cout << elem << ", ";
        }
        std::cout << "]\n";
    }
};
*/
/*
class Stack {
private:
    struct Item {
        int element;
        int cached_max; // stores the max element at or below this item
    };
    std::vector<Item> data;
public:
    bool isEmpty() {
        return data.empty();
    }

    void push(int x) {
        if (isEmpty()) {
            data.push_back({x, x});
        } else {
            data.push_back( { x, std::max(x, data.back().cached_max) } );
        }
    }
    
    int top() {
        if (isEmpty()) {
            throw std::length_error("cannot get top element: stack is empty");
        }
        return data.back().element;
    }
    
    bool pop() {
        if (isEmpty()) return false;
        data.pop_back();
        return true;
    }
    
    // max api using cached_max
    int max() {
        if (isEmpty()) {
            throw std::length_error("cannot get max element: stack is empty");
        }
        return data.back().cached_max;
    }
    
    void printStack() {
        std::cout << "[";
        for (auto item : data) {
            std::cout << "{" << item.element << ", " << item.cached_max << "}, " ;
        }
        std::cout << "]\n";
    }
};
*/


// Underlying DS: Linked List 
class Stack {
private:
    struct Node {
        int element;
        int cached_max; // stores the max element at or below this item
        Node *next;
    };
    
    Node *head;
    
public:
    Stack() {
        head = nullptr;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }

    void push(int x) {
        if (isEmpty()) {
            head = new Node({x, x, nullptr});
        } else {
            head = new Node( { x, std::max(x, head->cached_max), head } );
        }
    }
    
    int top() {
        if (isEmpty()) {
            throw std::length_error("cannot get top element: stack is empty");
        }
        return head->element;
    }
    
    bool pop() {
        if (isEmpty()) return false;
        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    
    // max api using cached_max
    int max() {
        if (isEmpty()) {
            throw std::length_error("cannot get max element: stack is empty");
        }
        return head->cached_max;
    }
    
    void printStack() {
        std::cout << "TOP-> [";
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << "{" << temp->element << ", " << temp->cached_max << "}, " ;
            temp = temp->next;
        }
        std::cout << "]\n";
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(878);
    s.push(3);
    s.push(128);
    s.push(34);
    s.push(0);
    
    s.printStack();
    
    std::cout << s.max() << std::endl;
    
    return 0;
}
