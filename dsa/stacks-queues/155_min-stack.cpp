/*
class MinStack {
public:
    struct Item {
        int element;
        int cached_min;
    };
    vector<Item> data;
    MinStack() {
        
    }
    
    bool isEmpty() {
        return data.empty();
    }
    
    void push(int val) {
        if (isEmpty()) {
            data.push_back({val, val});
        } else {
            data.push_back({val, std::min(val, data.back().cached_min)});
        }
    }
    
    void pop() {
        if (isEmpty()) {
            throw std::length_error("cannot pop(): stack is empty");
        }
        
        data.pop_back();
    }
    
    int top() {
        if (isEmpty()) {
            throw std::length_error("cannot get top(): stack is empty");
        }        
        return data.back().element;
    }
    
    int getMin() {
        if (isEmpty()) {
            throw std::length_error("cannot getMin(): stack is empty");
        }        
        return data.back().cached_min;        
    }
};
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
public:
    struct Node {
        int element;
        int cached_min;
        Node *next;
    };
    Node *head;
    MinStack() {
        head = nullptr;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    void push(int val) {
        if (isEmpty()) {
            head = new Node({val, val, nullptr});
        } else {
            head = new Node({val, std::min(val, head->cached_min), head});
        }
    }
    
    void pop() {
        if (isEmpty()) {
            throw std::length_error("cannot pop(): stack is empty");
        }
        
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        if (isEmpty()) {
            throw std::length_error("cannot get top(): stack is empty");
        }        
        return head->element;
    }
    
    int getMin() {
        if (isEmpty()) {
            throw std::length_error("cannot getMin(): stack is empty");
        }        
        return head->cached_min;        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
