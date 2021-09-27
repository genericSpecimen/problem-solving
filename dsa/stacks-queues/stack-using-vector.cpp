#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> data;
public:
    void push(int x) {
        data.push_back(x);
    }
    
    bool isEmpty() {
        return data.empty();
    }
    
    int top() {
        if (isEmpty()) {
            throw std::length_error("stack is empty");
        }
        return data.back();
    }
    
    bool pop() {
        if (isEmpty()) return false;
        data.pop_back();
        return true;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    
    std::cout << "[";
    for (int i=0; i<3; i++) {
        std::cout << s.top() << ", ";
        s.pop();
    }
    std::cout << "]\n";
    
    std::cout << std::boolalpha << s.pop() << std::endl;
    std::cout << s.top() << std::endl;
    
    return 0;
}
