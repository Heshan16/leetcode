//Solution 1
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
        topval=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(data.empty())
            return -1;
        queue<int> temp;
        for(int i=data.size();i>1;i--) {
            int x=data.front();
            data.pop();
            temp.push(x);
            topval=x;
        }
        int res=data.front();
        data=std::move(temp);
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return topval;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
private:
    queue<int> data;
    int topval;
};


//Solution 2
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
        for(int i=data.size();i>1;i--){
            data.push(data.front());
            data.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(data.empty())
            return -1;
        int x=data.front();
        data.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return data.empty()?-1:data.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }
private:
    queue<int> data;
};
