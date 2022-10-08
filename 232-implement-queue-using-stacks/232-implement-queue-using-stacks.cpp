class MyQueue {
public:
    
        stack<int> s1;
        stack<int> s2;

    
    void push(int x) {
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int z= s2.top();
        s2.pop();
        return z;
    }
    
    int peek() {
         while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty())
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */