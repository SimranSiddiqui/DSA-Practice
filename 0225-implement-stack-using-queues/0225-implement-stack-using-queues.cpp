class MyStack {
public:
    queue<int> q;
    queue<int> s;
    
    void push(int x) {
        q.push(x);
        while(!s.empty())
        {
            q.push(s.front());
            s.pop();
        }
        while(!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = s.front();
        s.pop();
        return x;
    }
    
    int top() {
        if(!s.empty())
        return s.front();
        
        return -1;
    }
    
    bool empty() {
        cout << s.front();
        return s.size() == 0;
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