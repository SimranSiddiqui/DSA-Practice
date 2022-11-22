class MinStack {
public:
   
    stack<int> st;
    stack<int> mst;
    int mini = INT_MAX;
    
    void push(int val) {
        
        if(mst.empty())
            mst.push(val);
        else
        {
            mini = min(val, mst.top());
               mst.push(mini);
        }
        
        st.push(val);
        
    }
    
    void pop() {
        st.pop();
        mst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
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