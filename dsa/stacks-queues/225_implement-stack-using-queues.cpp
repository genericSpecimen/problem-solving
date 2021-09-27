class MyStack {
public:
    queue<int> q1, q2;
    
    /** Push element x onto stack. */
    /*
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
        } else {
            while (!q1.empty()) {
                q2.push(q1.front()); q1.pop();
            }
            
            q1.push(x);
            
            while (!q2.empty()) {
                q1.push(q2.front()); q2.pop();
            }
        }
    }
    */

    
    // uses only one queue
    void push(int x) {
        q1.push(x);
        int size = q1.size();
        while (size > 1) {
            q1.push(q1.front()); q1.pop();
            size--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int elem = q1.front(); q1.pop();
        return elem;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
