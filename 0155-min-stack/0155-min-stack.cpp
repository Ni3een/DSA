class MinStack {
public:
     stack<int>st1,st2;
    MinStack() {
        
    }
    
    void push(int val) {
       if(st2.empty() || val<=st2.top()){ 
        st2.push(val);
       }
       st1.push(val); // st1 mein toh hmesha push krta rhunga
    }
    void pop() {
     if(st1.top()==st2.top()){ // stack 1 ka top equal hai toh stack 2 toh stack 1 se pop
        st2.pop();
     }
     st1.pop();
    }
    
    int top() {
       return st1.top();
    }
    
    int getMin() {
       return st2.top();
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