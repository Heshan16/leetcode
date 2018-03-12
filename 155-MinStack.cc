/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

*/


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        cur.push(x);
        if(min.empty() || x<=min.top())
            min.push(x);
    }
    
    void pop() {
        if(cur.top()==min.top())
            min.pop();
        cur.pop();
    }
    
    int top() {
        return cur.top();
    }
    
    int getMin() {
        return min.top();
    }
    private:
        stack<int> cur;
        stack<int> min;
};

